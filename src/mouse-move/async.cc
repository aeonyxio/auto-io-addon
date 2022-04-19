#include "async.h"
#include <napi.h>
#include "mouse-move.h"
#include "../common.h"

class MouseMoveWorker : public Napi::AsyncWorker {
 public:
  MouseMoveWorker(Napi::Function& callback, int x, int y)
      : Napi::AsyncWorker(callback), x(x), y(y) {}
  ~MouseMoveWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    MouseMove(x, y);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  int x;
  int y;
};

// Asynchronous access to the `Estimate()` function
Napi::Value MouseMoveAsync(const Napi::CallbackInfo& info) {
  int x = info[0].As<Napi::Number>().Int32Value();
  int y = info[1].As<Napi::Number>().Int32Value();
  Napi::Function callback = info[2].As<Napi::Function>();

  MouseMoveWorker* mouseMoveWorker = new MouseMoveWorker(callback, x, y);
  mouseMoveWorker->Queue();

  return info.Env().Undefined();
}