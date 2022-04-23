#include <napi.h>

Napi::Number getActiveWindowAPI(const Napi::CallbackInfo &info);
Napi::Array getWindowsAPI(const Napi::CallbackInfo &info);
Napi::Object getWindowRectAPI(const Napi::CallbackInfo &info);
Napi::String getWindowTitleAPI(const Napi::CallbackInfo &info);
Napi::Value setActiveWindowAPI(const Napi::CallbackInfo &info);