#include <Windows.h>
#include <ios>
#include <sstream>
#include <codecvt>
#include "../common.h"
#include "../key/key.h"

int hex_value(const std::string_view str) {
    std::stringstream stream{};
    stream << std::hex << str;
    int parsed;
    stream >> parsed;
    return parsed;
}

// std::string map_to_utf8(const int val) {
//     std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> converter;
//     return converter.to_bytes(static_cast<char32_t>(val));
// }

void UnicodeDown (std::string unicode_char)
{
  KEYBDINPUT kb={0};
  INPUT Input={0};

  kb.wScan = hex_value(unicode_char);
  kb.dwFlags = KEYEVENTF_UNICODE;
  Input.type = INPUT_KEYBOARD;
  Input.ki = kb;
  ::SendInput(1,&Input,sizeof(Input));
}

void UnicodeUp (std::string unicode_char)
{
  KEYBDINPUT kb={0};
  INPUT Input={0};

  kb.wScan = hex_value(unicode_char);
  kb.dwFlags = KEYEVENTF_UNICODE|KEYEVENTF_KEYUP;
  Input.type = INPUT_KEYBOARD;
  Input.ki = kb;
  ::SendInput(1,&Input,sizeof(Input));

  SendInput(1, &Input, sizeof(INPUT));
}