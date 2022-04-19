#include "async.h"
#include <napi.h>
#include <chrono>
#include "../common.h"

class SleepWorker : public Napi::AsyncWorker {
 public:
  SleepWorker(Napi::Function& callback, uint32_t amount)
      : Napi::AsyncWorker(callback), amount(amount) {}
  ~SleepWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    std::this_thread::sleep_for(std::chrono::nanoseconds(amount));
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
    uint32_t amount;
};

Napi::Value SleepAsync(const Napi::CallbackInfo& info) {
  uint32_t amount = info[0].As<Napi::Number>().Uint32Value();
  Napi::Function callback = info[1].As<Napi::Function>();
  
  std::this_thread::sleep_for(std::chrono::nanoseconds(amount));

  SleepWorker* sleepWorker = new SleepWorker(callback, amount);
  sleepWorker->Queue();
  return info.Env().Undefined();
}