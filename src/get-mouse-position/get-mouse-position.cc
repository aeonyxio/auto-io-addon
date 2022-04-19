#include <Windows.h>
#include <tuple>

std::tuple<int, int> GetMousePosition ()
{  
  POINT pnt;
  GetCursorPos(&pnt);
  return { pnt.x, pnt.y };
}
