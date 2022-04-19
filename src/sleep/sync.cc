#include "sync.h"
#include <napi.h>
#include <chrono>
#include <thread>

Napi::Value SleepSync(const Napi::CallbackInfo& info) {
  uint32_t amount = info[0].As<Napi::Number>().Uint32Value();
  std::this_thread::sleep_for(std::chrono::nanoseconds(amount));

  return info.Env().Undefined();
}