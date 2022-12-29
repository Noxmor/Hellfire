#include "hellfire.h"

Application* application_create(void)
{
	Application* app = malloc(sizeof(Application));
	app->width = 1600;
	app->height = 900;
	app->title = "Hellfire-Editor";
	return app;
}