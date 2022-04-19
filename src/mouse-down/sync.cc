#include "sync.h"
#include <napi.h>
#include "mouse-down.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value MouseDownSync(const Napi::CallbackInfo& info) {
  // expect a number as the first argument
  int button = info[0].As<Napi::Number>().Uint32Value();
  
  MouseDown(static_cast<Mouse>(button));

  return info.Env().Undefined();
}