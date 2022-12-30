#ifndef HF_APPLICATION_H
#define HF_APPLICATION_H

#include "core/core.h"

typedef struct Application
{
	u64 width;
	u64 height;
	const char* title;
	u8 running;
} Application;

void application_run(Application* app);

void application_close(Application* app);

void application_shutdown(Application* app);

#endif