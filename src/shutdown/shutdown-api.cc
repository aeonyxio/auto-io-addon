#include <napi.h>
#include "shutdown.h"

Napi::Value shutdownAPI(const Napi::CallbackInfo& info) {
  Shutdown();

  return info.Env().Undefined();
}