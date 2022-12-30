#ifndef HF_ENTRY_POINT_H
#define HF_ENTRY_POINT_H

#include <stdio.h>

#include "core/core.h"
#include "core/application.h"
#include "core/log.h"

extern Application* application_create(void);

int main(void)
{
	logger_log("Creating application...\n");
	Application* app = application_create();

	logger_log("Running application...\n");
	application_run(app);

	logger_log("Shutting down application...\n");
	application_shutdown(app);
}

#endif