#include <napi.h>
#include <Windows.h>

class EventsObject : public Napi::ObjectWrap<EventsObject> {
 public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  EventsObject(const Napi::CallbackInfo& info);

 private:
  Napi::Value Start(const Napi::CallbackInfo& info);
  Napi::Value Stop(const Napi::CallbackInfo& info);
  // Napi::Value CallEmit(const Napi::CallbackInfo& info);

  void HookProcedure();

  Napi::Function emit_;
  HHOOK hook;
};
