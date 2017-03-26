using ManageSystem.Model;
using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Threading;

namespace ManageSystem.ViewModel.DeviceViewModel
{
    public class AbnormalViewModel : NotificationObject
    {
        public QueryTableCallBackDelegate   _querytablecallbackdelegate = null;

        public DelegateCommand<object> QueryCommand { get; set; }
        public DelegateCommand<object> ExportExcelCommand { get; set; }
        public DelegateCommand<object> ExportTXTCommand { get; set; }


        private ObservableCollection<SHEBEIYICHANGSHUJUModel> _tableList;
        public ObservableCollection<SHEBEIYICHANGSHUJUModel> tableList
        {
            get
            {
                return _tableList;
            }
            set
            {
                _tableList = value;
                this.RaisePropertyChanged("tableList");
            }
        }

        private SHEBEIYICHANGSHUJUModel _customInfo;
        public SHEBEIYICHANGSHUJUModel customInfo
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


        public AbnormalViewModel()
        {
            _querytablecallbackdelegate         = new QueryTableCallBackDelegate(QueryTableCallBack);
            QueryCommand                        = new DelegateCommand<object>(Query);
            ExportExcelCommand                  = new DelegateCommand<object>(ExportExcel);
            ExportTXTCommand                    = new DelegateCommand<object>(ExportTXT);

            _tableList                          = new ObservableCollection<SHEBEIYICHANGSHUJUModel>();
            _customInfo                         = new SHEBEIYICHANGSHUJUModel();
        }

        private void ExportTXT(object obj)
        {
            System.Windows.Forms.SaveFileDialog opf = new System.Windows.Forms.SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.txt|*.txt|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filepath = opf.FileName;
                StreamWriter writer = new StreamWriter(filepath);

                Type type = typeof(SHEBEIYICHANGSHUJUModel);
                int rowCount = tableList.Count + 1;  //DataTable行数+GirdHead
                int colCount = type.GetProperties().Count(); //DataTable列数
                FieldInfo[] members = type.GetFields();
                PropertyInfo[] info = type.GetProperties();
                //利用二维数组批量写入
                string[,] arr = new string[rowCount, colCount];

                for (int j = 0; j < rowCount; j++)
                {
                    for (int k = 0; k < info.Count(); ++k)
                    {
                        System.Reflection.PropertyInfo item = (System.Reflection.PropertyInfo)info.ElementAt(k);

                        if (j == 0)
                        {
                            writer.Write(FunctionServer._columnNameMap[item.Name] + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Int32"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Int64"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("String"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else if (item.PropertyType.Name.StartsWith("Boolean"))
                        {
                            writer.Write(item.GetValue(tableList[j -1], null) + "\t");
                        }
                        else
                        {
                            ;
                        }
                    }
                    writer.WriteLine();
                }
                writer.Close();
            }
        }

        private void ExportExcel(object obj)
        {
            System.Windows.Forms.SaveFileDialog opf = new System.Windows.Forms.SaveFileDialog();
            opf.FileName = DateTime.Now.ToString("yyyyMMddHHmmss");
            opf.Filter = "*.xls|*.xls|所有文件(*.*)|*.*";
            if (opf.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                string filepath = opf.FileName;

                new Thread(() => {

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
                    Type type = typeof(SHEBEIYICHANGSHUJUModel);
                    int rowCount = tableList.Count + 1;  //DataTable行数+GirdHead
                    int colCount = type.GetProperties().Count(); //DataTable列数
                    FieldInfo[] members = type.GetFields();
                    PropertyInfo[] info = type.GetProperties();
                    //利用二维数组批量写入
                    string[,] arr = new string[rowCount, colCount];

                    for (int j = 0; j < rowCount; j++)
                    {
                        for (int k = 0; k < info.Count(); ++k)
                        {
                            System.Reflection.PropertyInfo item = (System.Reflection.PropertyInfo)info.ElementAt(k);

                            if (j == 0)
                            {
                                arr[j, k] = FunctionServer._columnNameMap[item.Name];
                            }
                            else if (item.PropertyType.Name.StartsWith("Int32"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("Int64"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("String"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else if (item.PropertyType.Name.StartsWith("Boolean"))
                            {
                                arr[j, k] += item.GetValue(tableList[j -1], null);
                            }
                            else
                            {
                                ;
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

                }).Start();
            }
        }

        public void QueryTableCallBack(string resultStr, string errorStr)
        {
            Type type = typeof(SHEBEIYICHANGSHUJUModel);

            if (type == null)
                return;

            System.Reflection.PropertyInfo[] properties = type.GetProperties(System.Reflection.BindingFlags.Instance | System.Reflection.BindingFlags.Public);

            string[] rows = resultStr.Split(';');
            foreach (string row in rows)
            {
                if (row.Length > 0)
                {
                    var model= Activator.CreateInstance(type);

                    string[] cells = row.Split(',');
                    foreach (string cell in cells)
                    {
                        string[] keyvalue = cell.Split(':');
                        if (keyvalue.Length != 2 || keyvalue[1] == null || keyvalue[1].Length == 0)
                            continue;

                        foreach (System.Reflection.PropertyInfo item in properties)
                        {
                            if (item.Name == keyvalue[0])
                            {
                                if (item.PropertyType.Name.StartsWith("Int32"))
                                {
                                    item.SetValue(model, Convert.ToInt32(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("Int64"))
                                {
                                    item.SetValue(model, Convert.ToInt64(keyvalue[1]), null);
                                }
                                else if (item.PropertyType.Name.StartsWith("String"))
                                {
                                    switch (item.Name)
                                    {
                                        case "Chengshibianhao":
                                        case "Jubianhao":
                                        case "Shiyongdanweibianhao":
                                        case "Shebeibaifangweizhi":
                                        case "Qianzhuzhonglei":
                                        case "ZhikaZhuangtai":
                                        case "Zhengjianleixing":
                                        case "Xingbie":
                                        case "Yewuleixing":
                                        case "Yichangleixing":
                                            if (MainWindowViewModel._yingshelList.Keys.Contains(Convert.ToInt32(keyvalue[1])))
                                                item.SetValue(model, MainWindowViewModel._yingshelList[Convert.ToInt32(keyvalue[1])], null);
                                            break;
                                        case "Riqi":
                                        case "Chushengriqi":
                                        case "Jiaoyiriqi":
                                            DateTime datetime = Common.ConvertIntDateTime(Convert.ToInt64(keyvalue[1]));
                                            item.SetValue(model, datetime.ToShortDateString(), null);
                                            break;
                                        case "IP":
                                            if (keyvalue[1].Length > 0)
                                                item.SetValue(model, Common.IntToIp(IPAddress.NetworkToHostOrder(Convert.ToInt32(keyvalue[1]))), null);
                                            break;
                                        default:
                                            item.SetValue(model, keyvalue[1], null);
                                            break;
                                    }
                                }
                                else if (item.PropertyType.Name.StartsWith("Boolean"))
                                {
                                    item.SetValue(model, Convert.ToBoolean(Convert.ToInt32(keyvalue[1])), null);
                                }
                                else
                                {
                                    ;
                                }
                                break;
                            }
                        }
                    }

                    Application.Current.Dispatcher.BeginInvoke(
                    new Action<object>((modeltemp) =>
                    {
                        tableList.Add(modeltemp as SHEBEIYICHANGSHUJUModel);
                    }), model);
                }
            }
        }

        public void Query(object obj)
        {
            tableList.Clear();
            WorkServer.QueryTable("select * from Shebeiyichangshuju", Marshal.GetFunctionPointerForDelegate(_querytablecallbackdelegate));
        }

        public void DoLogon()
        {
            Query(null);
        }
    }
}
