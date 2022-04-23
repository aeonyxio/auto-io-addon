#include <napi.h>
#include <iostream>
// #include "screen-capture.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <unknwn.h>
#include <gdiplus.h>

//Visual Studio shortcut for adding library:
#pragma comment(lib, "Gdiplus.lib")

int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
    UINT  num = 0;          // number of image encoders
    UINT  size = 0;         // size of the image encoder array in bytes

    Gdiplus::GetImageEncodersSize(&num, &size);
    if(size == 0)
        return -1;  // Failure

    Gdiplus::ImageCodecInfo* pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
    if(pImageCodecInfo == NULL)
        return -1;  // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for(UINT j = 0; j < num; ++j)
    {
        if(wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
        {
            *pClsid = pImageCodecInfo[j].Clsid;
            free(pImageCodecInfo);
            return j;  // Success
        }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
}

void screenshot(POINT a, POINT b)
{
    int w = b.x - a.x;
    int h = b.y - a.y;

    if(w <= 0) return;
    if(h <= 0) return;

    HDC     hScreen = GetDC(HWND_DESKTOP);
    HDC     hDc = CreateCompatibleDC(hScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
    HGDIOBJ old_obj = SelectObject(hDc, hBitmap);
    BitBlt(hDc, 0, 0, w, h, hScreen, a.x, a.y, SRCCOPY);

    Gdiplus::Bitmap bitmap(hBitmap, NULL);
    CLSID clsid;

    GetEncoderClsid(L"image/png", &clsid);

    //GDI+ expects Unicode filenames
    bitmap.Save(L"c:\\test\\test.png", &clsid);

    SelectObject(hDc, old_obj);
    DeleteDC(hDc);
    ReleaseDC(HWND_DESKTOP, hScreen);
    DeleteObject(hBitmap);
}

int main()
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    RECT      rc;
    GetClientRect(GetDesktopWindow(), &rc);
    POINT a{ 0, 0 };
    POINT b{ 100, 100 };

    screenshot(a, b);

    Gdiplus::GdiplusShutdown(gdiplusToken);

    return 0;
}


Napi::Value screenCaptureApi(const Napi::CallbackInfo &info)
{
	Napi::Env env = info.Env();

	int64_t x = info[0].As<Napi::Number>().Int64Value();
	int64_t y = info[1].As<Napi::Number>().Int64Value();
	int64_t width = info[2].As<Napi::Number>().Int64Value();
	int64_t height = info[3].As<Napi::Number>().Int64Value();


    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    RECT      rc;
    GetClientRect(GetDesktopWindow(), &rc);
    POINT a{ 0, 0 };
    POINT b{ 100, 100 };

    screenshot(a, b);

    Gdiplus::GdiplusShutdown(gdiplusToken);

	// Napi::Buffer<char> buffer = Napi::Buffer<char>::Copy(env, (char *)bitmap->imageBuffer, bufferSize);

	// return buffer;
    return info.Env().Undefined();
}