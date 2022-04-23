#include "window.h"
#include <windows.h>
#include <iostream>

/**
 * Documentation regarding the `EnumWindowsProc` already seems a bit stale (https://docs.microsoft.com/en-us/previous-versions/windows/desktop/legacy/ms633498(v=vs.85))
 * We should keep this in mind for the future, just in case there should be any deprecations or strange behaviour
 */
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lparam) {
    std::vector<int64_t>* windowHandles = reinterpret_cast<std::vector<int64_t>*>(lparam);
    if (windowHandles != nullptr) {
        windowHandles->push_back(reinterpret_cast<int64_t>(hwnd));
    }
    return TRUE;
}

std::vector<int64_t> getWindows() {
    std::vector<int64_t> windowHandles;

    EnumWindows (&EnumWindowsProc, reinterpret_cast<LPARAM>(&windowHandles));

    return windowHandles;
}

int64_t getActiveWindow() {
    HWND foregroundWindow = GetForegroundWindow();
    if (IsWindow(foregroundWindow)) {
        return reinterpret_cast<int64_t>(foregroundWindow);
    }
    return -1;
}

std::tuple<int64_t, int64_t, int64_t, int64_t> getWindowRect(const int64_t windowHandle) {
    HWND hWnd = reinterpret_cast<HWND>(windowHandle);
    RECT windowRect;
    if (IsWindow(hWnd) && GetWindowRect(hWnd, &windowRect)) {
        return {windowRect.left, windowRect.top, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top};
    }
    return {0, 0, 0, 0};
}

std::string getWindowTitle(const int64_t windowHandle) {
    HWND hWnd = reinterpret_cast<HWND>(windowHandle);
	size_t len = GetWindowTextLengthA(hWnd) + 1;
	if (len != 0)
	{
		char *text = (char *)malloc(len);
		len = GetWindowTextA(hWnd, text, static_cast<int>(len));
		return std::string(text, len);
	}
	return std::string();
}

void setActiveWindow(const int64_t windowHandle) {
    HWND hWnd = reinterpret_cast<HWND>(windowHandle);
    if (IsWindow(hWnd)) {
        ShowWindow(hWnd, SW_RESTORE);
        SetForegroundWindow(hWnd);
    }
}