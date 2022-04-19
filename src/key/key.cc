#include <windows.h>
#include "../common.h"

WORD GetKeyCode(Key key){
  WORD res;

  switch(key){
      case Key::KEYBOARD_CANCEL: {
	      res = 0x03;
        break;
      }
      case Key::KEYBOARD_XBUTTON1: {
	      res = 0x05;
        break;
      }
      case Key::KEYBOARD_XBUTTON2: {
	      res = 0x06;
        break;
      }
      case Key::KEYBOARD_BACK: {
	      res = 0x08;
        break;
      }
      case Key::KEYBOARD_TAB: {
	      res = 0x09;
        break;
      }
      case Key::KEYBOARD_CLEAR: {
	      res = 0x0C;
        break;
      }
      case Key::KEYBOARD_RETURN: {
	      res = 0x0D;
        break;
      }
      case Key::KEYBOARD_SHIFT: {
	      res = 0x10;
        break;
      }
      case Key::KEYBOARD_CONTROL: {
	      res = 0x11;
        break;
      }
      case Key::KEYBOARD_MENU: {
	      res = 0x12;
        break;
      }
      case Key::KEYBOARD_PAUSE: {
	      res = 0x13;
        break;
      }
      case Key::KEYBOARD_CAPITAL: {
	      res = 0x14;
        break;
      }
      case Key::KEYBOARD_KANA: {
	      res = 0x15;
        break;
      }
      case Key::KEYBOARD_HANGUL: {
	      res = 0x15;
        break;
      }
      case Key::KEYBOARD_IME_ON: {
	      res = 0x16;
        break;
      }
      case Key::KEYBOARD_JUNJA: {
	      res = 0x17;
        break;
      }
      case Key::KEYBOARD_FINAL: {
	      res = 0x18;
        break;
      }
      case Key::KEYBOARD_HANJA: {
	      res = 0x19;
        break;
      }
      case Key::KEYBOARD_KANJI: {
	      res = 0x19;
        break;
      }
      case Key::KEYBOARD_IME_OFF: {
	      res = 0x1A;
        break;
      }
      case Key::KEYBOARD_ESCAPE: {
	      res = 0x1B;
        break;
      }
      case Key::KEYBOARD_CONVERT: {
	      res = 0x1C;
        break;
      }
      case Key::KEYBOARD_NONCONVERT: {
	      res = 0x1D;
        break;
      }
      case Key::KEYBOARD_ACCEPT: {
	      res = 0x1E;
        break;
      }
      case Key::KEYBOARD_MODECHANGE: {
	      res = 0x1F;
        break;
      }
      case Key::KEYBOARD_SPACE: {
	      res = 0x20;
        break;
      }
      case Key::KEYBOARD_PRIOR: {
	      res = 0x21;
        break;
      }
      case Key::KEYBOARD_NEXT: {
	      res = 0x22;
        break;
      }
      case Key::KEYBOARD_END: {
	      res = 0x23;
        break;
      }
      case Key::KEYBOARD_HOME: {
	      res = 0x24;
        break;
      }
      case Key::KEYBOARD_LEFT: {
	      res = 0x25;
        break;
      }
      case Key::KEYBOARD_UP: {
	      res = 0x26;
        break;
      }
      case Key::KEYBOARD_RIGHT: {
	      res = 0x27;
        break;
      }
      case Key::KEYBOARD_DOWN: {
	      res = 0x28;
        break;
      }
      case Key::KEYBOARD_SELECT: {
	      res = 0x29;
        break;
      }
      case Key::KEYBOARD_PRINT: {
	      res = 0x2A;
        break;
      }
      case Key::KEYBOARD_EXECUTE: {
	      res = 0x2B;
        break;
      }
      case Key::KEYBOARD_SNAPSHOT: {
	      res = 0x2C;
        break;
      }
      case Key::KEYBOARD_INSERT: {
	      res = 0x2D;
        break;
      }
      case Key::KEYBOARD_DELETE: {
	      res = 0x2E;
        break;
      }
      case Key::KEYBOARD_HELP: {
	      res = 0x2F;
        break;
      }
      case Key::KEYBOARD_0: {
	      res = 0x30;
        break;
      }
      case Key::KEYBOARD_1: {
	      res = 0x31;
        break;
      }
      case Key::KEYBOARD_2: {
	      res = 0x32;
        break;
      }
      case Key::KEYBOARD_3: {
	      res = 0x33;
        break;
      }
      case Key::KEYBOARD_4: {
	      res = 0x34;
        break;
      }
      case Key::KEYBOARD_5: {
	      res = 0x35;
        break;
      }
      case Key::KEYBOARD_6: {
	      res = 0x36;
        break;
      }
      case Key::KEYBOARD_7: {
	      res = 0x37;
        break;
      }
      case Key::KEYBOARD_8: {
	      res = 0x38;
        break;
      }
      case Key::KEYBOARD_9: {
	      res = 0x39;
        break;
      }
      case Key::KEYBOARD_A: {
	      res = 0x41;
        break;
      }
      case Key::KEYBOARD_B: {
	      res = 0x42;
        break;
      }
      case Key::KEYBOARD_C: {
	      res = 0x43;
        break;
      }
      case Key::KEYBOARD_D: {
	      res = 0x44;
        break;
      }
      case Key::KEYBOARD_E: {
	      res = 0x45;
        break;
      }
      case Key::KEYBOARD_F: {
	      res = 0x46;
        break;
      }
      case Key::KEYBOARD_G: {
	      res = 0x47;
        break;
      }
      case Key::KEYBOARD_H: {
	      res = 0x48;
        break;
      }
      case Key::KEYBOARD_I: {
	      res = 0x49;
        break;
      }
      case Key::KEYBOARD_J: {
	      res = 0x4A;
        break;
      }
      case Key::KEYBOARD_K: {
	      res = 0x4B;
        break;
      }
      case Key::KEYBOARD_L: {
	      res = 0x4C;
        break;
      }
      case Key::KEYBOARD_M: {
	      res = 0x4D;
        break;
      }
      case Key::KEYBOARD_N: {
	      res = 0x4E;
        break;
      }
      case Key::KEYBOARD_O: {
	      res = 0x4F;
        break;
      }
      case Key::KEYBOARD_P: {
	      res = 0x50;
        break;
      }
      case Key::KEYBOARD_Q: {
	      res = 0x51;
        break;
      }
      case Key::KEYBOARD_R: {
	      res = 0x52;
        break;
      }
      case Key::KEYBOARD_S: {
	      res = 0x53;
        break;
      }
      case Key::KEYBOARD_T: {
	      res = 0x54;
        break;
      }
      case Key::KEYBOARD_U: {
	      res = 0x55;
        break;
      }
      case Key::KEYBOARD_V: {
	      res = 0x56;
        break;
      }
      case Key::KEYBOARD_W: {
	      res = 0x57;
        break;
      }
      case Key::KEYBOARD_X: {
	      res = 0x58;
        break;
      }
      case Key::KEYBOARD_Y: {
	      res = 0x59;
        break;
      }
      case Key::KEYBOARD_Z: {
	      res = 0x5A;
        break;
      }
      case Key::KEYBOARD_LWIN: {
	      res = 0x5B;
        break;
      }
      case Key::KEYBOARD_RWIN: {
	      res = 0x5C;
        break;
      }
      case Key::KEYBOARD_APPS: {
	      res = 0x5D;
        break;
      }
      case Key::KEYBOARD_SLEEP: {
	      res = 0x5F;
        break;
      }
      case Key::KEYBOARD_NUMPAD0: {
	      res = 0x60;
        break;
      }
      case Key::KEYBOARD_NUMPAD1: {
	      res = 0x61;
        break;
      }
      case Key::KEYBOARD_NUMPAD2: {
	      res = 0x62;
        break;
      }
      case Key::KEYBOARD_NUMPAD3: {
	      res = 0x63;
        break;
      }
      case Key::KEYBOARD_NUMPAD4: {
	      res = 0x64;
        break;
      }
      case Key::KEYBOARD_NUMPAD5: {
	      res = 0x65;
        break;
      }
      case Key::KEYBOARD_NUMPAD6: {
	      res = 0x66;
        break;
      }
      case Key::KEYBOARD_NUMPAD7: {
	      res = 0x67;
        break;
      }
      case Key::KEYBOARD_NUMPAD8: {
	      res = 0x68;
        break;
      }
      case Key::KEYBOARD_NUMPAD9: {
	      res = 0x69;
        break;
      }
      case Key::KEYBOARD_MULTIPLY: {
	      res = 0x6A;
        break;
      }
      case Key::KEYBOARD_ADD: {
	      res = 0x6B;
        break;
      }
      case Key::KEYBOARD_SEPARATOR: {
	      res = 0x6C;
        break;
      }
      case Key::KEYBOARD_SUBTRACT: {
	      res = 0x6D;
        break;
      }
      case Key::KEYBOARD_DECIMAL: {
	      res = 0x6E;
        break;
      }
      case Key::KEYBOARD_DIVIDE: {
	      res = 0x6F;
        break;
      }
      case Key::KEYBOARD_F1: {
	      res = 0x70;
        break;
      }
      case Key::KEYBOARD_F2: {
	      res = 0x71;
        break;
      }
      case Key::KEYBOARD_F3: {
	      res = 0x72;
        break;
      }
      case Key::KEYBOARD_F4: {
	      res = 0x73;
        break;
      }
      case Key::KEYBOARD_F5: {
	      res = 0x74;
        break;
      }
      case Key::KEYBOARD_F6: {
	      res = 0x75;
        break;
      }
      case Key::KEYBOARD_F7: {
	      res = 0x76;
        break;
      }
      case Key::KEYBOARD_F8: {
	      res = 0x77;
        break;
      }
      case Key::KEYBOARD_F9: {
	      res = 0x78;
        break;
      }
      case Key::KEYBOARD_F10: {
	      res = 0x79;
        break;
      }
      case Key::KEYBOARD_F11: {
	      res = 0x7A;
        break;
      }
      case Key::KEYBOARD_F12: {
	      res = 0x7B;
        break;
      }
      case Key::KEYBOARD_F13: {
	      res = 0x7C;
        break;
      }
      case Key::KEYBOARD_F14: {
	      res = 0x7D;
        break;
      }
      case Key::KEYBOARD_F15: {
	      res = 0x7E;
        break;
      }
      case Key::KEYBOARD_F16: {
	      res = 0x7F;
        break;
      }
      case Key::KEYBOARD_F17: {
	      res = 0x80;
        break;
      }
      case Key::KEYBOARD_F18: {
	      res = 0x81;
        break;
      }
      case Key::KEYBOARD_F19: {
	      res = 0x82;
        break;
      }
      case Key::KEYBOARD_F20: {
	      res = 0x83;
        break;
      }
      case Key::KEYBOARD_F21: {
	      res = 0x84;
        break;
      }
      case Key::KEYBOARD_F22: {
	      res = 0x85;
        break;
      }
      case Key::KEYBOARD_F23: {
	      res = 0x86;
        break;
      }
      case Key::KEYBOARD_F24: {
	      res = 0x87;
        break;
      }
      case Key::KEYBOARD_NUMLOCK: {
	      res = 0x90;
        break;
      }
      case Key::KEYBOARD_SCROLL: {
	      res = 0x91;
        break;
      }
      case Key::KEYBOARD_LSHIFT: {
	      res = 0xA0;
        break;
      }
      case Key::KEYBOARD_RSHIFT: {
	      res = 0xA1;
        break;
      }
      case Key::KEYBOARD_LCONTROL: {
	      res = 0xA2;
        break;
      }
      case Key::KEYBOARD_RCONTROL: {
	      res = 0xA3;
        break;
      }
      case Key::KEYBOARD_LMENU: {
	      res = 0xA4;
        break;
      }
      case Key::KEYBOARD_RMENU: {
	      res = 0xA5;
        break;
      }
      case Key::KEYBOARD_BROWSER_BACK: {
	      res = 0xA6;
        break;
      }
      case Key::KEYBOARD_BROWSER_FORWARD: {
	      res = 0xA7;
        break;
      }
      case Key::KEYBOARD_BROWSER_REFRESH: {
	      res = 0xA8;
        break;
      }
      case Key::KEYBOARD_BROWSER_STOP: {
	      res = 0xA9;
        break;
      }
      case Key::KEYBOARD_BROWSER_SEARCH: {
	      res = 0xAA;
        break;
      }
      case Key::KEYBOARD_BROWSER_FAVORITES: {
	      res = 0xAB;
        break;
      }
      case Key::KEYBOARD_BROWSER_HOME: {
	      res = 0xAC;
        break;
      }
      case Key::KEYBOARD_VOLUME_MUTE: {
	      res = 0xAD;
        break;
      }
      case Key::KEYBOARD_VOLUME_DOWN: {
	      res = 0xAE;
        break;
      }
      case Key::KEYBOARD_VOLUME_UP: {
	      res = 0xAF;
        break;
      }
      case Key::KEYBOARD_MEDIA_NEXT_TRACK: {
	      res = 0xB0;
        break;
      }
      case Key::KEYBOARD_MEDIA_PREV_TRACK: {
	      res = 0xB1;
        break;
      }
      case Key::KEYBOARD_MEDIA_STOP: {
	      res = 0xB2;
        break;
      }
      case Key::KEYBOARD_MEDIA_PLAY_PAUSE: {
	      res = 0xB3;
        break;
      }
      case Key::KEYBOARD_LAUNCH_MAIL: {
	      res = 0xB4;
        break;
      }
      case Key::KEYBOARD_LAUNCH_MEDIA_SELECT: {
	      res = 0xB5;
        break;
      }
      case Key::KEYBOARD_LAUNCH_APP1: {
	      res = 0xB6;
        break;
      }
      case Key::KEYBOARD_LAUNCH_APP2: {
	      res = 0xB7;
        break;
      }
      case Key::KEYBOARD_OEM_1: {
	      res = 0xBA;
        break;
      }
      case Key::KEYBOARD_OEM_PLUS: {
	      res = 0xBB;
        break;
      }
      case Key::KEYBOARD_OEM_COMMA: {
	      res = 0xBC;
        break;
      }
      case Key::KEYBOARD_OEM_MINUS: {
	      res = 0xBD;
        break;
      }
      case Key::KEYBOARD_OEM_PERIOD: {
	      res = 0xBE;
        break;
      }
      case Key::KEYBOARD_OEM_2: {
	      res = 0xBF;
        break;
      }
      case Key::KEYBOARD_OEM_3: {
	      res = 0xC0;
        break;
      }
      case Key::KEYBOARD_OEM_4: {
	      res = 0xDB;
        break;
      }
      case Key::KEYBOARD_OEM_5: {
	      res = 0xDC;
        break;
      }
      case Key::KEYBOARD_OEM_6: {
	      res = 0xDD;
        break;
      }
      case Key::KEYBOARD_OEM_7: {
	      res = 0xDE;
        break;
      }
      case Key::KEYBOARD_OEM_8: {
	      res = 0xDF;
        break;
      }
      case Key::KEYBOARD_OEM_102: {
	      res = 0xE2;
        break;
      }
      case Key::KEYBOARD_PROCESSKEY: {
	      res = 0xE5;
        break;
      }
      case Key::KEYBOARD_ATTN: {
	      res = 0xF6;
        break;
      }
      case Key::KEYBOARD_CRSEL: {
	      res = 0xF7;
        break;
      }
      case Key::KEYBOARD_EXSEL: {
	      res = 0xF8;
        break;
      }
      case Key::KEYBOARD_EREOF: {
	      res = 0xF9;
        break;
      }
      case Key::KEYBOARD_PLAY: {
	      res = 0xFA;
        break;
      }
      case Key::KEYBOARD_ZOOM: {
	      res = 0xFB;
        break;
      }
      case Key::KEYBOARD_NONAME: {
	      res = 0xFC;
        break;
      }
      case Key::KEYBOARD_PA1: {
	      res = 0xFD;
        break;
      }
      case Key::KEYBOARD_OEM_CLEAR: {
	      res = 0xFE;
        break;
      }
  }

  return res;
}