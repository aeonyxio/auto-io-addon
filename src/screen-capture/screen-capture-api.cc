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

std::tuple<char*, int> screenshot(POINT a, POINT b)
{
    int w = b.x - a.x;
    int h = b.y - a.y;

    HDC     hScreen = GetDC(HWND_DESKTOP);
    HDC     hDc = CreateCompatibleDC(hScreen);
    HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
    HGDIOBJ old_obj = SelectObject(hDc, hBitmap);
    BitBlt(hDc, 0, 0, w, h, hScreen, a.x, a.y, SRCCOPY);

    Gdiplus::Bitmap bitmap(hBitmap, NULL);


	//write to IStream
	IStream* istream = nullptr;
	HRESULT hr = CreateStreamOnHGlobal(NULL, TRUE, &istream);
	CLSID clsid_png;
	CLSIDFromString(L"{557cf406-1a04-11d3-9a73-0000f81ef32e}", &clsid_png);
	bitmap.Save(istream, &clsid_png);

	//get memory handle associated with istream
	HGLOBAL hg = NULL;
	GetHGlobalFromStream(istream, &hg);

	//copy IStream to buffer
	int bufsize = GlobalSize(hg);
	char *buffer = new char[bufsize];

	//lock & unlock memory
	LPVOID ptr = GlobalLock(hg);
	memcpy(buffer, ptr, bufsize);
	GlobalUnlock(hg);

	//release will automatically free the memory allocated in CreateStreamOnHGlobal 
	istream->Release();

    SelectObject(hDc, old_obj);
    DeleteDC(hDc);
    ReleaseDC(HWND_DESKTOP, hScreen);
    DeleteObject(hBitmap);

	return { buffer, bufsize };
}

std::tuple<char*, int> getScreenshot()
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    RECT      rc;
    GetClientRect(GetDesktopWindow(), &rc);
    POINT a{ 0, 0 };
    POINT b{ 100, 100 };

    auto [buffer, bufferSize] = screenshot(a, b);

    Gdiplus::GdiplusShutdown(gdiplusToken);

    return {buffer, bufferSize};
}


Napi::Buffer<char> screenCaptureApi(const Napi::CallbackInfo &info)
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

    auto [buffer, bufferSize] = screenshot(a, b);

    Gdiplus::GdiplusShutdown(gdiplusToken);

	Napi::Buffer<char> response = Napi::Buffer<char>::Copy(env, buffer, bufferSize);

	// return buffer;
    return response;
}