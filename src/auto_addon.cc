#include <napi.h>
#include "get-keyboard-layout/sync.h"
#include "get-keyboard-layout-list/sync.h"
#include "get-mouse-position/sync.h"
#include "highlight-screen/async.h"
#include "highlight-screen/sync.h"
#include "mouse-down/async.h"
#include "mouse-down/sync.h"
#include "mouse-move/async.h"
#include "mouse-move/sync.h"
#include "mouse-up/async.h"
#include "mouse-up/sync.h"
#include "key-down/async.h"
#include "key-down/sync.h"
#include "key-up/async.h"
#include "key-up/sync.h"
#include "unicode/async.h"
#include "unicode/sync.h"
#include "events/events-object.h"
#include "sleep/async.h"
#include "sleep/sync.h"
#include "set-keyboard-layout/async.h"
#include "set-keyboard-layout/sync.h"
#include "shutdown/shutdown-api.h"
#include "screen-capture/screen-capture-api.h"
#include "dpi-aware/dpi-aware-api.h"
#include "window/window-api.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "getKeyboardLayoutSync"),
              Napi::Function::New(env, GetKeyboardLayoutSync));
              
  exports.Set(Napi::String::New(env, "getKeyboardLayoutListSync"),
              Napi::Function::New(env, GetKeyboardLayoutListSync));

  exports.Set(Napi::String::New(env, "getMousePositionSync"),
              Napi::Function::New(env, GetMousePositionSync));

  exports.Set(Napi::String::New(env, "highlightScreenSync"),
              Napi::Function::New(env, HighlightScreenSync));
  exports.Set(Napi::String::New(env, "highlightScreenAsync"),
              Napi::Function::New(env, HighlightScreenAsync));

  exports.Set(Napi::String::New(env, "mouseDownSync"),
              Napi::Function::New(env, MouseDownSync));
  exports.Set(Napi::String::New(env, "mouseDownAsync"),
              Napi::Function::New(env, MouseDownAsync));

  exports.Set(Napi::String::New(env, "mouseMoveSync"),
              Napi::Function::New(env, MouseMoveSync));
  exports.Set(Napi::String::New(env, "mouseMoveAsync"),
              Napi::Function::New(env, MouseMoveAsync));

  exports.Set(Napi::String::New(env, "mouseUpSync"),
              Napi::Function::New(env, MouseUpSync));
  exports.Set(Napi::String::New(env, "mouseUpAsync"),
              Napi::Function::New(env, MouseUpAsync));

  exports.Set(Napi::String::New(env, "keyDownSync"),
              Napi::Function::New(env, KeyDownSync));
  exports.Set(Napi::String::New(env, "keyDownAsync"),
              Napi::Function::New(env, KeyDownAsync));

  exports.Set(Napi::String::New(env, "keyUpSync"),
              Napi::Function::New(env, KeyUpSync));
  exports.Set(Napi::String::New(env, "keyUpAsync"),
              Napi::Function::New(env, KeyUpAsync));

  exports.Set(Napi::String::New(env, "unicodeDownSync"),
              Napi::Function::New(env, UnicodeDownSync));
  exports.Set(Napi::String::New(env, "unicodeDownAsync"),
              Napi::Function::New(env, UnicodeDownAsync));

  exports.Set(Napi::String::New(env, "unicodeUpSync"),
              Napi::Function::New(env, UnicodeUpSync));
  exports.Set(Napi::String::New(env, "unicodeUpAsync"),
              Napi::Function::New(env, UnicodeUpAsync));
              
  exports.Set(Napi::String::New(env, "sleepSync"),
              Napi::Function::New(env, SleepSync));
  exports.Set(Napi::String::New(env, "sleepAsync"),
              Napi::Function::New(env, SleepAsync));
              
  exports.Set(Napi::String::New(env, "setKeyboardLayoutSync"),
              Napi::Function::New(env, SetKeyboardLayoutSync));
  exports.Set(Napi::String::New(env, "setKeyboardLayoutAsync"),
              Napi::Function::New(env, SetKeyboardLayoutAsync));
              
  exports.Set(Napi::String::New(env, "getActiveWindow"),
              Napi::Function::New(env, getActiveWindowAPI));
  exports.Set(Napi::String::New(env, "getWindows"),
              Napi::Function::New(env, getWindowsAPI));
  exports.Set(Napi::String::New(env, "getWindowRect"),
              Napi::Function::New(env, getWindowRectAPI));
  exports.Set(Napi::String::New(env, "getWindowTitle"),
              Napi::Function::New(env, getWindowTitleAPI));
  exports.Set(Napi::String::New(env, "setActiveWindow"),
              Napi::Function::New(env, setActiveWindowAPI));

  exports.Set(Napi::String::New(env, "screenCapture"),
              Napi::Function::New(env, screenCaptureApi));
  exports.Set(Napi::String::New(env, "screenCaptureSync"),
              Napi::Function::New(env, screenCaptureSyncApi));

  exports.Set(Napi::String::New(env, "dpiAware"),
              Napi::Function::New(env, dpiAwareApi));

  exports.Set(Napi::String::New(env, "shutdown"),
              Napi::Function::New(env, shutdownAPI));

  EventsObject::Init(env, exports);
  return exports;
}

NODE_API_MODULE(addon, Init)
