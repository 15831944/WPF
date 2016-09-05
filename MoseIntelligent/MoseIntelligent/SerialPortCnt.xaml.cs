using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using DataProcessLib;
using System.Collections.ObjectModel;
using System.Threading;
using System.Diagnostics;
using System.IO;

namespace MoseIntelligent
{
    /// <summary>
    /// SerialPortCnt.xaml 的交互逻辑
    /// </summary>
    public partial class SerialPortCnt : UserControl
    {
        SerialPort _serialPort;
        public _IProcessDataEvents_OnProcessDataCompleteEventHandler _OnOtherProcessDataCompleteDelegate;    //给调用者一个处理数据的机会

        Task _task = new Task(() => { });
        bool _beSerialReady = false;
        static ProcessDataClass _processDataCom = new ProcessDataClass();

        public SerialPortCnt()
        {
            InitializeComponent();
            _serialPort = FindResource("_serialPort") as SerialPort;
            _processDataCom.OnProcessDataComplete += OnProcessDataCompleteEvent;

            InitPortsList();


            _task.Start();
            //AcceptButton = _buttonCheck;
        }

        //methods
        public void InitPortsList()
        {
            _serialPort.Close();
            _beSerialReady = false;

            //_listViewPorts.BeginInit();
            ObservableCollection<SerialPortInfo> serialPortList = new ObservableCollection<SerialPortInfo>();
            string[] portNames = SerialPort.GetPortNames();


            foreach (string portName in portNames)
            {
                SerialPortInfo portInfo = new SerialPortInfo();
                portInfo.SerialPortName = portName;
                portInfo.bConnect = false;

                serialPortList.Add(portInfo);
            }
            //_listViewPorts.ItemsSource = serialPortList;
            //_listViewPorts.EndInit();
            _listGrid.DataContext = serialPortList;
        }

        //events
        private void _buttonCheck_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                _serialPort.Close();
                InitPortsList();

                //状态处理
                _beSerialReady = false;
            }
            catch (Exception ex)
            {

            }
        }

        private void _buttonConnect_Click(object sender, RoutedEventArgs e)
        {
            if (_listViewPorts.SelectedItems.Count > 0)
            {
                int index = (int)_listViewPorts.SelectedIndex;
                try
                {
                    ObservableCollection<SerialPortInfo> serialPortList = _listViewPorts.ItemsSource as ObservableCollection<SerialPortInfo>;
                    if (_serialPort.IsOpen)
                    {
                        _serialPort.Close();
                        foreach (SerialPortInfo infoItem in serialPortList)
                        {//全部重置为未连接
                            infoItem.bConnect = false;
                        }
                    }

                    //打开端口
                    _serialPort.PortName = serialPortList[index].SerialPortName;
                    _serialPort.Open();
                    if (_serialPort.IsOpen)
                    {
                        serialPortList[index].bConnect = true;
                        this.Dispatcher.BeginInvoke(new ThreadStart(() =>
                        {
                            byte[] shake0 = CreateSerialDataFF(1);
                            WriteSerialData(shake0);
                        }));
                        serialPortList[index].bConnect = true;
                    }

                    //状态处理
                    _beSerialReady = false;
                }
                catch (System.Exception ex)
                {
                    //状态处理
                    MessageBox.Show(ex.Message);
                }
            }
            else
            {
                MessageBox.Show("未选中任何端口");
            }
        }

        public static void processSerialData(Task task, object data)
        {//为了使用TASK
            _processDataCom.ProcessData(0, data);
            Debug.WriteLine(String.Format("当前线程数 {0} is doing something", Process.GetCurrentProcess().Threads.Count));
        }

        private void _serialPort_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                int len = _serialPort.BytesToRead;
                if (len > 0)
                {
                    //MessageBox.Show("收到数据了！");

                    byte[] readBuf = new byte[len];
                    _serialPort.Read(readBuf, 0, len);
                    if (len >= 4096)
                        len = 4096;
                    _task = _task.ContinueWith(processSerialData, readBuf, TaskContinuationOptions.LongRunning);
                }
            }
            catch (System.Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void _serialPort_PinChanged(object sender, SerialPinChangedEventArgs e)
        {

        }
        public string GetProcessWorkPath(int processID)
        {
            return _processDataCom.GetProcessWorkPath32_64(processID);
        }

        public void OnProcessDataCompleteEvent(uint flag, object result)
        {
            if (flag == 0)  //任何时候都可以打印日志
            {
                string printBytes = result as string;
                _textBoxLog.Dispatcher.BeginInvoke(new ThreadStart(() =>
                {
                    //if (_textBoxLog.Lines.Count() > 300)
                    //    _textBoxLog.Text = printByteso + Environment.NewLine;
                    //else
                    _textBoxLog.AppendText(printBytes + Environment.NewLine);
                    _textBoxLog.ScrollToEnd();
                }));
            }

            if (flag == 0xFF && _beSerialReady == false) //初始化握手
            {
                byte[] shake1 = result as byte[];
                if (shake1.Count() == 19 && shake1[3] == 2)
                {
                    byte[] shake2 = CreateSerialDataFF(3);
                    if (WriteSerialData(shake2))
                        _beSerialReady = true;
                }
            }

            //if(_beSerialReady)  //只有握手成功之后才可以处理数据
            {
                if (_OnOtherProcessDataCompleteDelegate != null)
                    _OnOtherProcessDataCompleteDelegate(flag, result);
            }
        }

        public bool WriteSerialData(byte[] data)
        {
            try
            {
                _serialPort.Write(data, 0, data.Count());
            }
            catch (Exception ex)
            {
                return false;
            }
            return true;
        }
        public byte[] CreateSerialHeader(byte frameId, byte frameCnt)
        {
            byte ConstDataLow = 0xaa;
            byte ConstDataHigh = 0x55;
            byte FrameId = frameId;
            byte FrameCnt = frameCnt;

            byte[] data = { ConstDataLow, ConstDataHigh, FrameId, FrameCnt };
            return data;
        }

        public byte[] CreateSerialDataFF(byte shakeID)
        {
            byte[] dataHeader = CreateSerialHeader(0xFF, shakeID);

            // frme body
            int UsrID = 0x00;
            int MyAirID = 0x00;
            ushort AirFirmwareInfo = 0;
            ushort AirHardwareInfo = 0;
            byte Resv0 = 0;
            byte Resv1 = 0;
            byte Sum8 = 0;

            MemoryStream strem = new MemoryStream();
            BinaryWriter writer = new BinaryWriter(strem);
            writer.Write(dataHeader);
            writer.Write(UsrID);
            writer.Write(MyAirID);
            writer.Write(AirFirmwareInfo);
            writer.Write(AirHardwareInfo);
            writer.Write(Resv0);
            writer.Write(Resv1);
            writer.Write(Sum8);

            byte[] byteData = strem.ToArray();
            byteData[byteData.Length - 1] = GlobalConfig.CalcSum8(byteData);
            return byteData;
        }

        public byte[] CreateSerialData80(
            bool bCtrl0, bool bShift0, bool bAlt0, byte key0,
            bool bCtrl1, bool bShift1, bool bAlt1, byte key1,
            ushort appName, ushort randomCode, byte keyType
            )
        {
            byte[] dataHeader = CreateSerialHeader(0x80, 0);

            // frme body
            int UsrID = 0x00;
            byte Ctr_Alt_Shift0 = 0;
            byte Key0 = key0;
            byte Ctr_Alt_Shift1 = 0;
            byte Key1 = key1;
            ushort AppName = appName;
            ushort RandomCode = 0;
            byte KeyType = keyType;
            byte Resv1 = 0;
            byte Sum8 = 0;

            if (bCtrl0) Ctr_Alt_Shift0 |= 0x01;
            if (bShift0) Ctr_Alt_Shift0 |= 0x02;
            if (bAlt0) Ctr_Alt_Shift0 |= 0x04;
            if (bCtrl1) Ctr_Alt_Shift1 |= 0x01;
            if (bShift1) Ctr_Alt_Shift1 |= 0x02;
            if (bAlt1) Ctr_Alt_Shift1 |= 0x04;

            MemoryStream strem = new MemoryStream();
            BinaryWriter writer = new BinaryWriter(strem);
            writer.Write(dataHeader);
            writer.Write(UsrID);
            writer.Write(Ctr_Alt_Shift0);
            writer.Write(Key0);
            writer.Write(Ctr_Alt_Shift1);
            writer.Write(Key1);
            writer.Write(AppName);
            writer.Write(RandomCode);
            writer.Write(KeyType);
            writer.Write(Resv1);
            writer.Write(Sum8);

            byte[] byteData = strem.ToArray();
            byteData[byteData.Length - 1] = GlobalConfig.CalcSum8(byteData);
            return byteData;
        }
    }
}
