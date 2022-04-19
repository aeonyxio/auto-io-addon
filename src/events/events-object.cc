#include "events-object.h"
#include <Windows.h>
#include <functional>

Napi::Object EventsObject::Init(Napi::Env env, Napi::Object exports) {
  Napi::Function func =
      DefineClass(env,
                  "EventsObject",
                  {InstanceMethod("start", &EventsObject::Start),
                   InstanceMethod("stop", &EventsObject::Stop),
                  //  InstanceMethod("callEmit", &EventsObject::CallEmit)
                   });

  Napi::FunctionReference* constructor = new Napi::FunctionReference();
  *constructor = Napi::Persistent(func);
  env.SetInstanceData(constructor);

  exports.Set("EventsObject", func);
  return exports;
}

EventsObject::EventsObject(const Napi::CallbackInfo& info)
    : Napi::ObjectWrap<EventsObject>(info) {
  Napi::Env env = info.Env();

  Napi::Function emit = info[0].As<Napi::Function>();
  this->emit_ = emit;
}

Napi::Value EventsObject::Start(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  
  // this->hook = SetWindowsHookEx(
	// 	WH_KEYBOARD_LL, // low-level keyboard input events
	// 	std::bind(&EventsObject::HookProcedure, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3), // pointer to the hook procedure
	// 	GetModuleHandle(NULL), // A handle to the DLL containing the hook procedure 
	// 	NULL //desktop apps, if this parameter is zero
	// 	);

  this->emit_.Call({Napi::String::New(env, "start")});

  return info.Env().Undefined();;
}

void EventsObject::HookProcedure() {


}

Napi::Value EventsObject::Stop(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  
  UnhookWindowsHookEx(this->hook);
  this->emit_.Call({Napi::String::New(env, "end")});

  return info.Env().Undefined();
}

// Napi::Value CallEmit(const Napi::CallbackInfo& info) {
//   return info.Env().Undefined();
// }