#include "sync.h"
#include <napi.h>
#include "highlight-screen.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value HighlightScreenSync(const Napi::CallbackInfo& info) {
  auto x = info[0].As<Napi::Number>().Int32Value();
  auto y = info[1].As<Napi::Number>().Int32Value();
  auto width = info[2].As<Napi::Number>().Int32Value();
  auto height = info[3].As<Napi::Number>().Int32Value();
  auto duration = info[4].As<Napi::Number>().Int64Value();
  auto opacity = info[5].As<Napi::Number>().FloatValue();
  Napi::Function callback = info[6].As<Napi::Function>();
  HighlightScreen(x, y, width, height, static_cast<long>(duration), opacity);

  return info.Env().Undefined();
}