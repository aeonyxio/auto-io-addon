#include "async.h"
#include <napi.h>
#include "mouse-down.h"
#include "../common.h"

class MouseDownWorker : public Napi::AsyncWorker {
 public:
  MouseDownWorker(Napi::Function& callback, Mouse button)
      : Napi::AsyncWorker(callback), button(button) {}
  ~MouseDownWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    MouseDown(button);
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
Napi::Value MouseDownAsync(const Napi::CallbackInfo& info) {
  int button = info[0].As<Napi::Number>().Uint32Value();
  Napi::Function callback = info[1].As<Napi::Function>();
  MouseDownWorker* mouseDownWorker = new MouseDownWorker(callback, static_cast<Mouse>(button));
  mouseDownWorker->Queue();
  return info.Env().Undefined();
}