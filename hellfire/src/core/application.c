#include "application.h"

#include <stdio.h>
#include <stdlib.h>

void application_run(Application* app)
{
	app->running = HF_TRUE;
	while (app->running)
	{
		printf("Application is running...\n");
		break;
	}
}
void application_close(Application* app)
{
	app->running = HF_FALSE;
}

void application_shutdown(Application* app)
{
	free(app);
}