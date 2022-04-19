#include "async.h"
#include <napi.h>
#include "key-down.h"
#include "../common.h"

class KeyDownWorker : public Napi::AsyncWorker {
 public:
  KeyDownWorker(Napi::Function& callback, int key)
      : Napi::AsyncWorker(callback), key(key) {}
  ~KeyDownWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    KeyDown(static_cast<Key>(key));
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

Napi::Value KeyDownAsync(const Napi::CallbackInfo& info) {
  auto key = info[0].As<Napi::Number>().Uint32Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  KeyDownWorker* keyDownWorker = new KeyDownWorker(callback, key);
  keyDownWorker->Queue();
  return info.Env().Undefined();
}