#include <napi.h>
#include <iostream>
// #include "screen-capture.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <unknwn.h>
#include <gdiplus.h>
#include <shellscalingapi.h>
#include <iostream>

//Visual Studio shortcut for adding library:
#pragma comment(lib, "Gdiplus.lib")
#pragma comment(lib, "SHCore")
#pragma comment(lib, "UXTheme")
#pragma comment(lib, "shell32")
#pragma comment(lib, "WINDOWSCODECS")

Napi::Value dpiAwareApi(const Napi::CallbackInfo &info){
    SetProcessDpiAwareness(PROCESS_PER_MONITOR_DPI_AWARE);
    return info.Env().Undefined();
}
