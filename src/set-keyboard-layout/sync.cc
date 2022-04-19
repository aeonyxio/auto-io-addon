#include "sync.h"
#include <napi.h>
#include "set-keyboard-layout.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value SetKeyboardLayoutSync(const Napi::CallbackInfo& info) {
  auto country = info[0].As<Napi::Number>().Int32Value();
  
  SetKeyboardLayout(static_cast<Country>(country));

  return info.Env().Undefined();
}