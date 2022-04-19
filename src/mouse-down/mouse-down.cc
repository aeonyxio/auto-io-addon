#include <Windows.h>
#include "../common.h"

void MouseDown (Mouse mouse)
{  
  INPUT Input={0};
  Input.type = INPUT_MOUSE;

  switch(mouse){
      case Mouse::Left: {
        Input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        break;
      }
      case Mouse::Right: {
        Input.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
        break;
      }
      case Mouse::Middle: {
        Input.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
        break;
      }
  }

  ::SendInput(1, &Input, sizeof(INPUT));
}