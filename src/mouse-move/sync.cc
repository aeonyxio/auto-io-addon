#include "sync.h"
#include <napi.h>
#include "mouse-move.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value MouseMoveSync(const Napi::CallbackInfo& info) {
  int x = info[0].As<Napi::Number>().Int32Value();
  int y = info[1].As<Napi::Number>().Int32Value();
  
  MouseMove(x, y);

  return info.Env().Undefined();
}