#pragma once

#include <vector>
#include <string>

std::vector<int64_t> getWindows();
int64_t getActiveWindow();
std::string getWindowTitle(const int64_t windowHandle);
std::tuple<int64_t, int64_t, int64_t, int64_t> getWindowRect(const int64_t windowHandle);
void setActiveWindow(const int64_t windowHandle);