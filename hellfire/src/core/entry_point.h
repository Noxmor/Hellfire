#ifndef HF_ENTRY_POINT_H
#define HF_ENTRY_POINT_H

#include <stdio.h>

#include "core/core.h"
#include "core/application.h"
#include "core/log.h"

extern Application* application_create(void);

int main(void)
{
	HF_CORE_LOG("Creating application...");
	Application* app = application_create();

	application_run(app);

	application_shutdown(app);

	return 0;
}

#endif