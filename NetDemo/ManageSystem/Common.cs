using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Windows;
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
}
