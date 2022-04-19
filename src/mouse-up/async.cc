#include "async.h"
#include <napi.h>
#include "mouse-up.h"
#include "../common.h"

class MouseUpWorker : public Napi::AsyncWorker {
 public:
  MouseUpWorker(Napi::Function& callback, Mouse button)
      : Napi::AsyncWorker(callback), button(button) {}
  ~MouseUpWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    MouseUp(button);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
    Mouse button;
};

// Asynchronous access to the `Estimate()` function
Napi::Value MouseUpAsync(const Napi::CallbackInfo& info) {
  int button = info[0].As<Napi::Number>().Uint32Value();
  Napi::Function callback = info[1].As<Napi::Function>();
  MouseUpWorker* mouseUpWorker = new MouseUpWorker(callback, static_cast<Mouse>(button));
  mouseUpWorker->Queue();
  return info.Env().Undefined();
}