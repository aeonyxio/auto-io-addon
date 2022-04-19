#include "async.h"
#include <napi.h>
#include "highlight-screen.h"
#include "../common.h"

class HighlightScreenWorker : public Napi::AsyncWorker {
 public:
  HighlightScreenWorker(Napi::Function& callback, int32_t x, int32_t y, int32_t width, int32_t height, long duration, float opacity)
      : Napi::AsyncWorker(callback), x(x), y(y), width(width), height(height), duration(duration), opacity(opacity) {}
  ~HighlightScreenWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    HighlightScreen(x, y, width, height, duration, opacity);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  int32_t x;
  int32_t y;
  int32_t width;
  int32_t height;
  long duration;
  float opacity;
};

// Asynchronous access to the `Estimate()` function
Napi::Value HighlightScreenAsync(const Napi::CallbackInfo& info) {
  auto x = info[0].As<Napi::Number>().Int32Value();
  auto y = info[1].As<Napi::Number>().Int32Value();
  auto width = info[2].As<Napi::Number>().Int32Value();
  auto height = info[3].As<Napi::Number>().Int32Value();
  auto duration = info[4].As<Napi::Number>().Int64Value();
  auto opacity = info[5].As<Napi::Number>().FloatValue();
  Napi::Function callback = info[6].As<Napi::Function>();

  HighlightScreenWorker* highlightScreenWorker = new HighlightScreenWorker(callback, x, y, width, height, static_cast<long>(duration), opacity);
  highlightScreenWorker->Queue();
  return info.Env().Undefined();
}