#include "sync.h"
#include <napi.h>
#include "key-down.h"
#include "../common.h"

Napi::Value KeyDownSync(const Napi::CallbackInfo& info) {
  auto key = info[0].As<Napi::Number>().Uint32Value();
  
  KeyDown(static_cast<Key>(key));

  return info.Env().Undefined();
}