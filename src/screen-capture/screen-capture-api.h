#include <napi.h>

Napi::Value screenCaptureApi(const Napi::CallbackInfo& info);
Napi::Buffer<char> screenCaptureSyncApi(const Napi::CallbackInfo &info);