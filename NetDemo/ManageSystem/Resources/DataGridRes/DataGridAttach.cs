using ManageSystem.Server;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.Resources.DataGridRes
{
    public class DataGridAttach : DependencyObject
    {
        public static object GetGeneratColumnObj(DependencyObject obj)
        {
            return (object)obj.GetValue(GeneratColumnObjProperty);
        }

        public static void SetGeneratColumnObj(DependencyObject obj, object value)
        {
            obj.SetValue(GeneratColumnObjProperty, value);
        }

        // Using a DependencyProperty as the backing store for GeneratColumnObj.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty GeneratColumnObjProperty =
    DependencyProperty.RegisterAttached("GeneratColumnObj", typeof(object), typeof(DataGridAttach), new PropertyMetadata(null, OnGeneratColumnObjChanged));

        private static void OnGeneratColumnObjChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            DataGrid grid   = d as DataGrid;
            grid.AutoGeneratingColumn += FunctionServer.DG1_AutoGeneratingColumn;
        }

    }
}
