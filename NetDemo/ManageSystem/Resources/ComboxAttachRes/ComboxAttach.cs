using ManageSystem.Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.Resources.ComboxAttachRes
{
    class ComboxAttach : DependencyObject
    {
        public static object GetAttachUpdate(DependencyObject obj)
        {
            return (object)obj.GetValue(AttachUpdateProperty);
        }

        public static void SetAttachUpdate(DependencyObject obj, object value)
        {
            obj.SetValue(AttachUpdateProperty, value);
        }

        // Using a DependencyProperty as the backing store for AttachUpdate.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty AttachUpdateProperty =
    DependencyProperty.RegisterAttached("AttachUpdate", typeof(object), typeof(ComboxAttach), new PropertyMetadata(null, OnAttachUpdateChanged));

        private static void OnAttachUpdateChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            try
            {
                RUANJIANBAOModel model                              = e.NewValue as RUANJIANBAOModel;
                ComboBox combobox                                   = d as ComboBox;
                SHEBEIGUANLIModel modeldevice                       = combobox.DataContext as SHEBEIGUANLIModel;
          
                modeldevice.operateinfomodel.operatedisplayText     = model.Banbenhao;
            }
            catch { }
        }
    }
}
