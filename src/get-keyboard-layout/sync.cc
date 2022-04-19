#include "sync.h"
#include <napi.h>
#include "get-keyboard-layout.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value GetKeyboardLayoutSync(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

    auto [layout, raw] = GetKeyboardLayout();

	Napi::Object obj = Napi::Object::New(env);

	obj.Set("layout", static_cast<int>(layout));
	obj.Set("raw", raw);

	return obj;
}
