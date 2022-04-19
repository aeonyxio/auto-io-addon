#include "sync.h"
#include <napi.h>
#include "unicode.h"
#include "../common.h"

Napi::Value UnicodeDownSync(const Napi::CallbackInfo& info) {
	std::string unicode_string = info[0].As<Napi::String>();
  
  UnicodeDown(unicode_string);

  return info.Env().Undefined();
}

Napi::Value UnicodeUpSync(const Napi::CallbackInfo& info) {
	std::string unicode_string = info[0].As<Napi::String>();
  
  UnicodeUp(unicode_string);

  return info.Env().Undefined();
}