#include <Windows.h>
#include <ios>
#include "../common.h"
#include "../key/key.h"

void KeyUp (Key key)
{
  INPUT Input={0};
  Input.type = INPUT_KEYBOARD;
  Input.ki.dwFlags = KEYEVENTF_KEYUP;
	Input.ki.wVk = GetKeyCode(key);

  SendInput(1, &Input, sizeof(INPUT));
}