#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#include "core/core.h"

void logger_log(const char* name, const char* message, ...)
{
	__builtin_va_list args = 0;
	va_start(args, message);

	u64 len = vsnprintf(NULL, 0, message, args);
	char* formatted_message = malloc(len + 1);
	vsprintf(formatted_message, message, args);
	va_end(args);

	time_t now = time(0);
	struct tm* time_info = localtime(&now);

	printf("[%02d:%02d:%02d] %s: %s\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec, name, formatted_message);
}