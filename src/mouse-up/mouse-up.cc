#include <Windows.h>
#include "../common.h"

void MouseUp (Mouse mouse)
{  
  INPUT Input={0};
  Input.type = INPUT_MOUSE;

  switch(mouse){
      case Mouse::Left: {
        Input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        break;
      }
      case Mouse::Right: {
        Input.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
        break;
      }
      case Mouse::Middle: {
        Input.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
        break;
      }
  }

  ::SendInput(1, &Input, sizeof(INPUT));
}