#include "platform.h"

#include "core/platform_detection.h"

#ifdef HF_PLATFORM_WINDOWS

#include <Windows.h>
#include <windowsx.h>

void platform_print(const char* message, u8 color)
{
	HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	static u8 levels[7] = {
		BACKGROUND_RED,
		FOREGROUND_RED,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,
		FOREGROUND_GREEN,
		FOREGROUND_BLUE | FOREGROUND_GREEN,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
	};
	SetConsoleTextAttribute(console_handle, levels[color]);
	WriteConsoleA(console_handle, message, (DWORD)strlen(message), 0, 0);
	SetConsoleTextAttribute(console_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

#endif