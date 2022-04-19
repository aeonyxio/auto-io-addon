#include <Windows.h>
#include <ios>
#include "../common.h"
#include "../key/key.h"

void KeyDown (Key key)
{
  INPUT Input={0};
  Input.type = INPUT_KEYBOARD;
  Input.ki.dwFlags = 0;
	Input.ki.wVk = GetKeyCode(key);

  SendInput(1, &Input, sizeof(INPUT));
}