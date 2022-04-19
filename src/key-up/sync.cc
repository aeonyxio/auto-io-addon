#include "sync.h"
#include <napi.h>
#include "key-up.h"
#include "../common.h"

Napi::Value KeyUpSync(const Napi::CallbackInfo& info) {
  auto key = info[0].As<Napi::Number>().Uint32Value();
  
  KeyUp(static_cast<Key>(key));

  return info.Env().Undefined();
}