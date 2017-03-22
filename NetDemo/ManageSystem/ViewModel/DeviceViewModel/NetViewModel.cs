using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace ManageSystem.ViewModel.DeviceViewModel
{
   public  class NetViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;

        public DelegateCommand<object> TestCommand { get; set; }
        public DelegateCommand<object> ExportExcelCommand { get; set; }
        public DelegateCommand<object> ExportTXTCommand { get; set; }

        private SHEBEIGUANLIModel _customInfo;
        public SHEBEIGUANLIModel customInfo
        {
            get
            {
                return _customInfo;
            }
            set
            {
                _customInfo = value;
                this.RaisePropertyChanged("customInfo");
            }
        }

        private string _statusText;
        public string statusText
        {
            get
            {
                return _statusText;
            }
            set
            {
                _statusText = value;
                this.RaisePropertyChanged("statusText");
            }
        }

        public NetViewModel()
        {
            _querytablecallbackdelegate         = new QueryTableCallBackDelegate(QueryTableCallBack);

            TestCommand                         = new DelegateCommand<object>(Test);
            ExportExcelCommand                  = new DelegateCommand<object>(ExportExcel);
            ExportTXTCommand                    = new DelegateCommand<object>(ExportTXT);

            _statusText                         = "";
            _customInfo                         = new SHEBEIGUANLIModel();
        }

        private void ExportTXT(object obj)
        {
            SaveFileDialog opf = new SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.txt|*.txt|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == DialogResult.OK)
            {
                string filepath = opf.FileName;

                StreamWriter writer = new StreamWriter(filepath);

                int rowCount = 1 + 1;  //DataTable行数+GirdHead
                int colCount = 1; //DataTable列数

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < colCount; k++)
                    {
                        if (j == 0)
                        {
                            writer.Write("测试速度:" + "\t");
                        }
                        else
                        {
                            writer.Write(statusText + "\t");
                        }
                    }
                    writer.WriteLine();
                }
                writer.Close();               
            }
        }

        private void ExportExcel(object obj)
        {
            SaveFileDialog opf = new SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.xls|*.xls|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == DialogResult.OK)
            {
                string filepath = opf.FileName;
 
                object missing = System.Reflection.Missing.Value;
                Microsoft.Office.Interop.Excel.Application app = new Microsoft.Office.Interop.Excel.Application();
                //创建一个Application对象并使其不可见
                app.Visible=false;
                //创建一个WorkBook对象
                Microsoft.Office.Interop.Excel.Workbook workBook = app.Workbooks.Add(missing);
                Microsoft.Office.Interop.Excel.Worksheet workSheet = null;
                Microsoft.Office.Interop.Excel.Range range = null;


                workSheet = (Microsoft.Office.Interop.Excel.Worksheet)workBook.Worksheets.Add(
                                                                                            Type.Missing,
                                                                                            workBook.ActiveSheet,
                                                                                            Type.Missing,
                                                                                            Type.Missing);

                int rowCount = 1;  //DataTable行数+GirdHead
                int colCount = 1; //DataTable列数

                //利用二维数组批量写入
                string[,] arr = new string[rowCount, colCount];

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < colCount; k++)
                    {
                        if (j == 0)
                        {
                            arr[j, k] = "测试速度:";

                        }
                        else
                        {
                            arr[j, k] = statusText;
                        }
                    }
                }


                range           = (Microsoft.Office.Interop.Excel.Range)workSheet.Cells[1, 1]; //写入Exel的坐标
                range           = range.get_Resize(rowCount, colCount);
                range.Value2    = arr;

                workBook.SaveAs(filepath, missing, missing, missing, missing, missing, Microsoft.Office.Interop.Excel.XlSaveAsAccessMode.xlExclusive, missing, missing, missing, missing, missing);

                if (workBook.Saved)
                {
                    workBook.Close(null, null, null);
                    app.Workbooks.Close();
                    app.Quit();
                }

                if (range != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(range);
                    range = null;
                }

                if (workSheet != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(workSheet);
                    workSheet = null;
                }
                if (workBook != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(workBook);
                    workBook = null;
                }
                if (app != null)
                {
                    System.Runtime.InteropServices.Marshal.ReleaseComObject(app);
                    app = null;
                }

                GC.Collect();//强制代码垃圾回收
            }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            
            if(errorStr.Length == 0)
            {
                string[] rows = resultStr.Split(';');
                foreach (string row in rows)
                {
                    if (row.Length > 0)
                    {
                        string[] cells = row.Split(',');
                        foreach (string cell in cells)
                        {
                            string[] keyvalue = cell.Split(':');
                            if (keyvalue.Length != 2)
                                continue;

                            if(keyvalue[0] == "speed")
                            {
                                double speed = Convert.ToDouble(keyvalue[1]);
                                statusText = "当前网速：";
                                if(speed > 1024 * 1024)
                                {
                                    speed /= 1024*1024;
                                    statusText += speed + " MByte/s";
                                }
                                else if(speed > 1024)
                                {
                                    speed /= 1024;
                                    statusText += speed + " KByte/s";
                                }
                                else
                                {
                                    statusText += speed + " Byte/s";
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                statusText = errorStr;
            }
        }

        private void Test(object obj)
        {
            IPAddress addr;
            if(IPAddress.TryParse(customInfo.IP, out addr))
                WorkServer.queryDevSpeed(customInfo.IP, Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate), true);
        }


    }
}
