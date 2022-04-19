#include "sync.h"
#include <napi.h>
#include "mouse-up.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value MouseUpSync(const Napi::CallbackInfo& info) {
  // expect a number as the first argument
  int button = info[0].As<Napi::Number>().Uint32Value();
  MouseUp(static_cast<Mouse>(button));

  return info.Env().Undefined();
}