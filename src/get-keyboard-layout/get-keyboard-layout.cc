#include <Windows.h>
#include <napi.h>
#include <tuple>
#include "../common.h"

std::tuple<Country, std::string> GetKeyboardLayout ()
{  
  Country layout;
  char currentLanguage[KL_NAMELENGTH];
  GetKeyboardLayoutNameA(currentLanguage);
  std::string str = currentLanguage;

  if(str == "00000409"){
    layout = Country::US;
  } else if(str == "00000809"){
    layout = Country::UK;
  }else{
    layout = Country::UNKNOWN;
  }

  return {layout, str};
}
