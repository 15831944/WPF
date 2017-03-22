using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.Resources.WebBrowserAttach
{
    public class WebBrowserAttach : DependencyObject
    {    
        public static string GetUrl(DependencyObject obj)
        {
            return (string)obj.GetValue(UrlProperty);
        }

        public static void SetUrl(DependencyObject obj, string value)
        {
            obj.SetValue(UrlProperty, value);
        }

        // Using a DependencyProperty as the backing store for Url.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty UrlProperty =
    DependencyProperty.RegisterAttached("Url", typeof(string), typeof(WebBrowserAttach), new PropertyMetadata("", OnUrlChanged));

        private static void OnUrlChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var webbrowser = d as WebBrowser;

            string url = e.NewValue as string;
            if(url != null && url != "")
                webbrowser.Navigate(url);
        }



        public static string GetxmlData(DependencyObject obj)
        {
            return (string)obj.GetValue(xmlDataProperty);
        }

        public static void SetxmlData(DependencyObject obj, string value)
        {
            obj.SetValue(xmlDataProperty, value);
        }

        // Using a DependencyProperty as the backing store for xmlData.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty xmlDataProperty =
    DependencyProperty.RegisterAttached("xmlData", typeof(string), typeof(WebBrowserAttach), new PropertyMetadata("", OnxmlDataChanged));

        private static void OnxmlDataChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var webbrowser = d as WebBrowser;

            string xmlData = e.NewValue as string;
            if (xmlData != null && xmlData != "")
                webbrowser.InvokeScript("LoadData", xmlData);
        }



        public static object GetObjectForScript(DependencyObject obj)
        {
            return (object)obj.GetValue(ObjectForScriptProperty);
        }

        public static void SetObjectForScript(DependencyObject obj, object value)
        {
            obj.SetValue(ObjectForScriptProperty, value);
        }

        // Using a DependencyProperty as the backing store for ObjectForScript.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty ObjectForScriptProperty =
    DependencyProperty.RegisterAttached("ObjectForScript", typeof(object), typeof(WebBrowserAttach), new PropertyMetadata(null, OnObjectForScriptChanged));

        private static void OnObjectForScriptChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var webbrowser = d as WebBrowser; 
            webbrowser.ObjectForScripting = e.NewValue;
        }
    }
}
