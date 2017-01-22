using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace NetDemo
{
    class Common
    {
        /// <summary> 

        /// 原型是 :HMODULE LoadLibrary(LPCTSTR lpFileName); 

        /// </summary> 

        /// <param name="lpFileName">DLL 文件名 </param> 

        /// <returns> 函数库模块的句柄 </returns> 

        [DllImport("kernel32.dll")]

        public static extern IntPtr LoadLibrary(string lpFileName);  /// <summary> 

        /// 原型是 : FARPROC GetProcAddress(HMODULE hModule, LPCWSTR lpProcName); 

        /// </summary> 

        /// <param name="hModule"> 包含需调用函数的函数库模块的句柄 </param> 

        /// <param name="lpProcName"> 调用函数的名称 </param> 

        /// <returns> 函数指针 </returns> 

        [DllImport("kernel32.dll")]

        public static extern IntPtr GetProcAddress(IntPtr hModule, string lpProcName);

        /// 原型是 : BOOL FreeLibrary(HMODULE hModule); 

        /// </summary> 

        /// <param name="hModule"> 需释放的函数库模块的句柄 </param> 

        /// <returns> 是否已释放指定的 Dll</returns> 

        [DllImport("kernel32", EntryPoint="FreeLibrary", SetLastError=true)]

       public static extern bool FreeLibrary(IntPtr hModule); 
    }
}
