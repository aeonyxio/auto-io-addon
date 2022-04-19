#include "async.h"
#include <napi.h>
#include "key-up.h"
#include "../common.h"

class KeyUpWorker : public Napi::AsyncWorker {
 public:
  KeyUpWorker(Napi::Function& callback, int key)
      : Napi::AsyncWorker(callback), key(key) {}
  ~KeyUpWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    KeyUp(static_cast<Key>(key));
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  int key;
};

Napi::Value KeyUpAsync(const Napi::CallbackInfo& info) {
  auto key = info[0].As<Napi::Number>().Uint32Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  KeyUpWorker* keyUpWorker = new KeyUpWorker(callback, key);
  keyUpWorker->Queue();
  return info.Env().Undefined();
}