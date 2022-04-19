#include "async.h"
#include <napi.h>
#include "unicode.h"
#include "../common.h"

class UnicodeDownWorker : public Napi::AsyncWorker {
 public:
  UnicodeDownWorker(Napi::Function& callback, std::string unicode_string)
      : Napi::AsyncWorker(callback), unicode_string(unicode_string) {}
  ~UnicodeDownWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    UnicodeDown(unicode_string);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  std::string unicode_string;
};

Napi::Value UnicodeDownAsync(const Napi::CallbackInfo& info) {
	std::string unicode_string = info[0].As<Napi::String>();
  Napi::Function callback = info[1].As<Napi::Function>();

  UnicodeDownWorker* keyDownWorker = new UnicodeDownWorker(callback, unicode_string);
  keyDownWorker->Queue();
  return info.Env().Undefined();
}

class UnicodeUpWorker : public Napi::AsyncWorker {
 public:
  UnicodeUpWorker(Napi::Function& callback, std::string unicode_string)
      : Napi::AsyncWorker(callback), unicode_string(unicode_string) {}
  ~UnicodeUpWorker() {}

  // Executed inside the worker-thread.
  // It is not safe to access JS engine data structure
  // here, so everything we need for input and output
  // should go on `this`.
  void Execute() { 
    UnicodeUp(unicode_string);
  }

  // Executed when the async work is complete
  // this function will be run inside the main event loop
  // so it is safe to use JS engine data again
  void OnOK() {
    Callback().Call({Env().Undefined()});
  }

 private:
  std::string unicode_string;
};

Napi::Value UnicodeUpAsync(const Napi::CallbackInfo& info) {
	std::string unicode_string = info[0].As<Napi::String>();
  Napi::Function callback = info[1].As<Napi::Function>();

  UnicodeUpWorker* keyUpWorker = new UnicodeUpWorker(callback, unicode_string);
  keyUpWorker->Queue();
  return info.Env().Undefined();
}