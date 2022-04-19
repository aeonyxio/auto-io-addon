#include <Windows.h>
#include <napi.h>
#include <tuple>
#include <iostream>
#include "../common.h"

std::vector<std::string> GetKeyboardLayoutList ()
{
	  std::vector<HKL> hklArr;
	  std::vector<std::string> listStr;

		int cnt = GetKeyboardLayoutList(0, 0);
		hklArr.resize(cnt);
		listStr.resize(cnt);
		GetKeyboardLayoutList(cnt, &hklArr[0]);
    
  if(cnt > 0)
  {
      for (int i = 0; i < cnt; i++)
      {
          if (ActivateKeyboardLayout(hklArr[i], KLF_SETFORPROCESS))
          {
              char pName[MAX_PATH];
              
              if (GetKeyboardLayoutNameA(pName))
              {
                  std::cout << i << "[" << pName << "]" << std::endl; // log
                  listStr[i] = std::string(pName);
              }
          }
      }
  }

    return listStr;
}
