#include "async.h"
#include <napi.h>
#include "set-keyboard-layout.h"
#include "../common.h"

class SetKeyboardLayoutWorker : public Napi::AsyncWorker {
 public:
  SetKeyboardLayoutWorker(Napi::Function& callback, Country region)
      : Napi::AsyncWorker(callback), region(region) {}
  ~SetKeyboardLayoutWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    SetKeyboardLayout(region);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  Country region;
};

// Asynchronous access to the `Estimate()` function
Napi::Value SetKeyboardLayoutAsync(const Napi::CallbackInfo& info) {
  auto country = info[0].As<Napi::Number>().Int32Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  SetKeyboardLayoutWorker* mouseMoveWorker = new SetKeyboardLayoutWorker(callback, static_cast<Country>(country));
  mouseMoveWorker->Queue();

  return info.Env().Undefined();
}