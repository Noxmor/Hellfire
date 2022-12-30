#include "log.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdarg.h>

#include "core/core.h"

void logger_log(const char* message, ...)
{
	__builtin_va_list args = 0;
	va_start(args, message);

	u64 len = vsnprintf(NULL, 0, message, args);
	char* formatted_message = malloc(len + 1);
	vsprintf(formatted_message, message, args);
	va_end(args);
	vprintf(formatted_message, args);

	time_t now = time(0);
	char* time_str = ctime(&now);
	time_str[strlen(time_str) - 1] = '\0';

	printf("[%s]: %s", time_str, formatted_message);
}