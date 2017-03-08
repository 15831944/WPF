using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Windows.Controls;

namespace ManageSystem.Resources.WebBrowserAttach
{
    class WebBrowserAttach : DependencyObject
    {
        private delegate void NavigateDelegate(string url);
        private static  NavigateDelegate _delegate;
        
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
            var pb = d as WebBrowser;

            string url = e.NewValue as string;
            if(url != null && url != "")
                pb.Navigate(url);
        }

        public static bool GetbAttach(DependencyObject obj)
        {
            return (bool)obj.GetValue(bAttachProperty);
        }

        public static void SetbAttach(DependencyObject obj, bool value)
        {
            obj.SetValue(bAttachProperty, value);
        }

        // Using a DependencyProperty as the backing store for bAttach.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty bAttachProperty =
    DependencyProperty.RegisterAttached("bAttach", typeof(bool), typeof(WebBrowserAttach), new PropertyMetadata(false, OnIsAttachChanged));

         private static void OnIsAttachChanged(DependencyObject d, DependencyPropertyChangedEventArgs e)
        {
            var pb = d as WebBrowser;
            if (pb == null)
            {
                return;
            }

            _delegate = pb.Navigate;
        }
    }
}
