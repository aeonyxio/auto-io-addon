#include <napi.h>
#include "shutdown.h"

Napi::Value ShutdownAPI(const Napi::CallbackInfo& info) {
  Shutdown();

  return info.Env().Undefined();
}