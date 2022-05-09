#include <napi.h>
#include <tuple>
#include "screen-capture.h"
using namespace Napi;

Napi::Buffer<char> screenCaptureSyncApi(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t x = info[0].As<Napi::Number>().Int64Value();
	int64_t y = info[1].As<Napi::Number>().Int64Value();
	int64_t width = info[2].As<Napi::Number>().Int64Value();
	int64_t height = info[3].As<Napi::Number>().Int64Value();

    auto [buffer, bufferSize] = screenshot((int)x, (int)y, (int)width, (int)height);

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
    auto [bufferResponse, sizeResponse] = screenshot(x, y, width, height);
    buffer = bufferResponse;
    bufferSize = sizeResponse;
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    HandleScope scope(Env());
    Callback().Call({Napi::Buffer<char>::Copy(Env(), buffer, bufferSize)});
  }

 private:
  int x;
  int y;
  int width;
  int height;
  char* buffer;
  int bufferSize;
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