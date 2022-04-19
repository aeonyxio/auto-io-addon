#include "sync.h"
#include <napi.h>
#include <iostream>
#include "get-keyboard-layout-list.h"
#include "../common.h"

// Simple synchronous access to the `Estimate()` function
Napi::Value GetKeyboardLayoutListSync(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

    auto layouts = GetKeyboardLayoutList();

    Napi::Array napiArr = Napi::Array::New(info.Env(), layouts.size());

	for (int i = 0; i < layouts.size(); i++) { // for each
		std::string layout = layouts[i];
		std::cout << i << ". " << layout << std::endl; // log
		napiArr[i] = Napi::String::New(info.Env(), layout);
	}

	return napiArr;
}
