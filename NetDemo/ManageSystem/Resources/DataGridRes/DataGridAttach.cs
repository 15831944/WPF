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



        public static object GetGridBeginEditFunc(DependencyObject obj)
        {
            return (object)obj.GetValue(GridBeginEditFuncProperty);
        }

        public static void SetGridBeginEditFunc(DependencyObject obj, object value)
        {
            obj.SetValue(GridBeginEditFuncProperty, value);
        }

        // Using a DependencyProperty as the backing store for GridBeginEditFunc.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty GridBeginEditFuncProperty =
    DependencyProperty.RegisterAttached("GridBeginEditFunc", typeof(object), typeof(DataGridAttach), new PropertyMetadata(null, OnGridBeginEditFuncChanged));

        private static void OnGridBeginEditFuncChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            DataGrid grid       = d as DataGrid;
            grid.BeginningEdit  += GridBeginEditFunc;
        }

        private static void GridBeginEditFunc(object sender, DataGridBeginningEditEventArgs e)
        {
            if (e.Column.DisplayIndex > 0) //第0列即使进入编辑状态，TextBlock也不能编辑
            {
                e.Cancel = true;
                return;
            }
        }


        public static object  GetbSelectAll(DependencyObject obj)
        {
            return (object )obj.GetValue(bSelectAllProperty);
        }

        public static void SetbSelectAll(DependencyObject obj, object  value)
        {
            obj.SetValue(bSelectAllProperty, value);
        }

        // Using a DependencyProperty as the backing store for bSelectAll.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty bSelectAllProperty =
    DependencyProperty.RegisterAttached("bSelectAll", typeof(object ), typeof(DataGridAttach), new PropertyMetadata(null, OnbSelectAllChanged));

        private static void OnbSelectAllChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            if(e.NewValue != null && e.OldValue != null)
            {
                if (e.NewValue != e.OldValue)
                {
                    DataGrid data = Common.GetParentObject<DataGrid>(d, "");
                    foreach(var item in data.Items)
                    {
                        item.GetType().GetProperty("bSel").SetValue(item, e.NewValue, null);
                    }
                }
            }
        }
    }
}
