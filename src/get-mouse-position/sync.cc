#include "sync.h"
#include <napi.h>
#include "get-mouse-position.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value GetMousePositionSync(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

  auto [x, y] = GetMousePosition();

	Napi::Object obj = Napi::Object::New(env);

	obj.Set("x", x);
	obj.Set("y", y);

	return obj;
}
