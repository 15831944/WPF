using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;
using System.Windows.Interactivity;

namespace ManageSystem
{
    public class NotificationObject : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public void RaisePropertyChanged(string propertyName)
        {
            if (this.PropertyChanged != null)
            {
                this.PropertyChanged(this, new PropertyChangedEventArgs(propertyName));
            }
        }
    }

    public class MyEventCommand : TriggerAction<DependencyObject>
    {

        /// <summary>
        /// 事件要绑定的命令
        /// </summary>
        public ICommand Command
        {
            get { return (ICommand)GetValue(CommandProperty); }
            set { SetValue(CommandProperty, value); }
        }

        // Using a DependencyProperty as the backing store for MsgName.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty CommandProperty =
            DependencyProperty.Register("Command", typeof(ICommand), typeof(MyEventCommand), new PropertyMetadata(null));

        /// <summary>
        /// 绑定命令的参数，保持为空就是事件的参数
        /// </summary>
        public object CommandParateter
        {
            get { return (object)GetValue(CommandParateterProperty); }
            set { SetValue(CommandParateterProperty, value); }
        }

        // Using a DependencyProperty as the backing store for CommandParateter.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty CommandParateterProperty =
            DependencyProperty.Register("CommandParateter", typeof(object), typeof(MyEventCommand), new PropertyMetadata(null));

        //执行事件
        protected override void Invoke(object parameter)
        {
            if (CommandParateter != null)
                parameter = CommandParateter;
            var cmd = Command;
            if (cmd != null)
                cmd.Execute(parameter);
        }
    }

    /// <summary> 
    /// delegate command for view model 
    /// </summary> 
    public class DelegateCommand<T> : ICommand
    {
        #region members
        /// <summary> 
        /// can execute function 
        /// </summary> 
        private readonly Func<T, bool> canExecute;

        /// <summary> 
        /// execute function 
        /// </summary> 
        private readonly Action<T> execute;

        #endregion

        /// <summary> 
        /// Initializes a new instance of the DelegateCommand class. 
        /// </summary> 
        /// <param name="execute">indicate an execute function</param> 
        public DelegateCommand(Action<T> execute)
            : this(execute, null)
        {
        }

        /// <summary> 
        /// Initializes a new instance of the DelegateCommand class. 
        /// </summary> 
        /// <param name="execute">execute function </param> 
        /// <param name="canExecute">can execute function</param> 
        public DelegateCommand(Action<T> execute, Func<T, bool> canExecute)
        {
            this.execute = execute;
            this.canExecute = canExecute;
        }

        /// <summary> 
        /// can executes event handler 
        /// </summary> 
        public event EventHandler CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        /// <summary> 
        /// implement of icommand can execute method 
        /// </summary> 
        /// <param name="parameter">parameter by default of icomand interface</param> 
        /// <returns>can execute or not</returns> 
        public bool CanExecute(object parameter)
        {
            if (this.canExecute == null)
            {
                return true;
            }

            return this.canExecute((T)parameter);
        }

        /// <summary> 
        /// implement of icommand interface execute method 
        /// </summary> 
        /// <param name="parameter">parameter by default of icomand interface</param> 
        public void Execute(object parameter)
        {
            this.execute((T)parameter);
        }
    }

    public class Common
    {
        public static T DeepCopy<T>(T obj)
        {
            //如果是字符串或值类型则直接返回
            if (obj is string || obj.GetType().IsValueType) return obj;

            object retval = Activator.CreateInstance(obj.GetType());
            FieldInfo[] fields = obj.GetType().GetFields(BindingFlags.Public | BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.Static);
            foreach (FieldInfo field in fields)
            {
                try { field.SetValue(retval, DeepCopy(field.GetValue(obj))); }
                catch { }
            }
            return (T)retval;
        }

        /// <summary>
        /// 将Unix时间戳转换为DateTime类型时间
        /// </summary>
        /// <param name="d">double 型数字</param>
        /// <returns>DateTime</returns>
        public static System.DateTime ConvertIntDateTime(double d)
        {
            System.DateTime time = System.DateTime.MinValue;
            System.DateTime startTime = TimeZone.CurrentTimeZone.ToLocalTime(new System.DateTime(1970, 1, 1));
            time = startTime.AddSeconds(d);
            return time;
        }

        /// <summary>
        /// 将c# DateTime时间格式转换为Unix时间戳格式
        /// </summary>
        /// <param name="time">时间</param>
        /// <returns>double</returns>
        public static double ConvertDateTimeInt(System.DateTime time)
        {
            double intResult = 0;
            System.DateTime startTime = TimeZone.CurrentTimeZone.ToLocalTime(new System.DateTime(1970, 1, 1));
            intResult = (time - startTime).TotalSeconds;
            return intResult;
        }

        public static long IpToInt(string ip)
        {
            char[] separator = new char[] { '.' };
            string[] items = ip.Split(separator);
            return long.Parse(items[0]) << 24
                    | long.Parse(items[1]) << 16
                    | long.Parse(items[2]) << 8 
                    | long.Parse(items[3]);
        }
        public static string IntToIp(long ipInt)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append((ipInt >> 24) & 0xFF).Append(".");
            sb.Append((ipInt >> 16) & 0xFF).Append(".");
            sb.Append((ipInt >> 8) & 0xFF).Append(".");
            sb.Append(ipInt & 0xFF);
            return sb.ToString();
        }

        public static DateTime FirstDayOfMonth(DateTime datetime)  
        {
            return datetime.AddDays(1 - datetime.Day);
        }

        public static DateTime LastDayOfMonth(DateTime datetime)
        {

            return datetime.AddDays(1 - datetime.Day).AddMonths(1).AddDays(-1);
        }

        public static DateTime FistDayOfWeek(DateTime datetime)
        {
            return DateTime.Now.AddDays(Convert.ToDouble((0 - Convert.ToInt16(DateTime.Now.DayOfWeek))));
        }

        public static DateTime LastDayOfWeek(DateTime datetime)
        {
            return DateTime.Now.AddDays(Convert.ToDouble((6 - Convert.ToInt16(DateTime.Now.DayOfWeek))));
        }

        public static DateTime FistDayOfYear(DateTime datetime)
        {
            return DateTime.Parse(datetime.ToString("yyyy-01-01"));
        }

        public static DateTime LastDayOfYear(DateTime datetime)
        {
            return DateTime.Parse(datetime.ToString("yyyy-01-01")).AddYears(1).AddDays(-1);
        }
        ///// <summary> 

        ///// 原型是 :HMODULE LoadLibrary(LPCTSTR lpFileName); 

        ///// </summary> 

        ///// <param name="lpFileName">DLL 文件名 </param> 

        ///// <returns> 函数库模块的句柄 </returns> 

        //[DllImport("kernel32.dll")]

        //public static extern IntPtr LoadLibrary(string lpFileName);  /// <summary> 

        ///// 原型是 : FARPROC GetProcAddress(HMODULE hModule, LPCWSTR lpProcName); 

        ///// </summary> 

        ///// <param name="hModule"> 包含需调用函数的函数库模块的句柄 </param> 

        ///// <param name="lpProcName"> 调用函数的名称 </param> 

        ///// <returns> 函数指针 </returns> 

        //[DllImport("kernel32.dll")]

        //public static extern IntPtr GetProcAddress(IntPtr hModule, string lpProcName);

        ///// 原型是 : BOOL FreeLibrary(HMODULE hModule); 

        ///// </summary> 

        ///// <param name="hModule"> 需释放的函数库模块的句柄 </param> 

        ///// <returns> 是否已释放指定的 Dll</returns> 

        //[DllImport("kernel32", EntryPoint="FreeLibrary", SetLastError=true)]

        //public static extern bool FreeLibrary(IntPtr hModule);
    }

    [System.Runtime.InteropServices.StructLayoutAttribute(System.Runtime.InteropServices.LayoutKind.Sequential)]
    public struct tagRECT
    {

        /// LONG->int
        public int left;

        /// LONG->int
        public int top;

        /// LONG->int
        public int right;

        /// LONG->int
        public int bottom;
    }

}
