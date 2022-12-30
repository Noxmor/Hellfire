#include "application.h"

#include <stdio.h>
#include <stdlib.h>

#include "core/log.h"

void application_run(Application* app)
{
	app->running = HF_TRUE;
	while (app->running)
	{
		HF_CORE_INFO("Running application...");
		break;
	}
}
void application_close(Application* app)
{
	HF_CORE_INFO("Closing application...");
	app->running = HF_FALSE;
}

void application_shutdown(Application* app)
{
	HF_CORE_INFO("Shutting down application...");
	free(app);
}