#include <Windows.h>
#include <string>
#include "../common.h"

void SetKeyboardLayout (Country region)
{
  LPCSTR targetLanguage;

  switch(region){
      case Country::US: {
	      targetLanguage = "00000409";
        break;
      }
      case Country::UK: {
	      targetLanguage = "00000809";
        break;
      }
  }
  SendMessageW(HWND_BROADCAST, WM_INPUTLANGCHANGEREQUEST, 0, reinterpret_cast<LPARAM>(LoadKeyboardLayoutA(targetLanguage, KLF_ACTIVATE)));
}