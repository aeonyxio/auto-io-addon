#include <napi.h>
#include "window.h"

Napi::Number getActiveWindowAPI(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t windowHandle = getActiveWindow();
	return Napi::Number::New(env, (double)windowHandle);
}

Napi::Array getWindowsAPI(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	std::vector<int64_t> windowHandles = getWindows();
	auto arr = Napi::Array::New(env, windowHandles.size());

	for (size_t idx = 0; idx < windowHandles.size(); ++idx)
	{
		arr[(uint32_t)idx] = windowHandles[idx];
	}

	return arr;
}

Napi::Object getWindowRectAPI(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t windowHandle = info[0].As<Napi::Number>().Int64Value();
	auto [x, y, width, height] = getWindowRect(windowHandle);

	Napi::Object obj = Napi::Object::New(env);
	obj.Set(Napi::String::New(env, "x"), Napi::Number::New(env, (double)x));
	obj.Set(Napi::String::New(env, "y"), Napi::Number::New(env, (double)y));
	obj.Set(Napi::String::New(env, "width"), Napi::Number::New(env, (double)width));
	obj.Set(Napi::String::New(env, "height"), Napi::Number::New(env, (double)height));

	return obj;
}

Napi::String getWindowTitleAPI(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t windowHandle = info[0].As<Napi::Number>().Int64Value();
	return Napi::String::New(env, getWindowTitle(windowHandle));
}

Napi::Value setActiveWindowAPI(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t windowHandle = info[0].As<Napi::Number>().Int64Value();

	setActiveWindow(windowHandle);
  	return info.Env().Undefined();
}