#include <napi.h>
#include <tuple>
#include <iostream>
#include "screen-capture.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <unknwn.h>
#include <gdiplus.h>
#include <tuple>
#include <shellscalingapi.h>

//Visual Studio shortcut for adding library:
#pragma comment(lib, "Gdiplus.lib")
#pragma comment(lib, "SHCore")
#pragma comment(lib, "UXTheme")
#pragma comment(lib, "shell32")
#pragma comment(lib, "WINDOWSCODECS")
using namespace Napi;

Napi::Buffer<char> screenCaptureSyncApi(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t x = info[0].As<Napi::Number>().Int64Value();
	int64_t y = info[1].As<Napi::Number>().Int64Value();
	int64_t width = info[2].As<Napi::Number>().Int64Value();
	int64_t height = info[3].As<Napi::Number>().Int64Value();

    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    auto [buffer, bufferSize] = screenshot((int)x, (int)y, (int)width, (int)height);
    Gdiplus::GdiplusShutdown(gdiplusToken);

	Napi::Buffer<char> response = Napi::Buffer<char>::Copy(env, buffer, bufferSize);

	// return buffer;
    return response;
}

class ScreenCaptureWorker : public Napi::AsyncWorker {
 public:
  ScreenCaptureWorker(Napi::Function& callback, int x, int y, int width, int height)
      : Napi::AsyncWorker(callback), x(x), y(y), width(width), height(height) {}
  ~ScreenCaptureWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
    auto [bufferResponse, sizeResponse] = screenshot(x, y, width, height);
    buffer = bufferResponse;
    bufferSize = sizeResponse;
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    HandleScope scope(Env());
     Napi::Buffer<char> tempBuffer = Napi::Buffer<char>::Copy(Env(), buffer, bufferSize);
    Gdiplus::GdiplusShutdown(gdiplusToken);
    Callback().Call({Env().Null(), tempBuffer});
  }

 private:
  int x;
  int y;
  int width;
  int height;
  char* buffer;
  int bufferSize;
  ULONG_PTR gdiplusToken;;
};

Napi::Value screenCaptureApi(const Napi::CallbackInfo& info) {
	int64_t x = info[0].As<Napi::Number>().Int64Value();
	int64_t y = info[1].As<Napi::Number>().Int64Value();
	int64_t width = info[2].As<Napi::Number>().Int64Value();
	int64_t height = info[3].As<Napi::Number>().Int64Value();
    Napi::Function callback = info[4].As<Napi::Function>();

  ScreenCaptureWorker* screenCaptureWorker = new ScreenCaptureWorker(callback, (int)x, (int)y, (int)width, (int)height);
  screenCaptureWorker->Queue();

  return info.Env().Undefined();
}