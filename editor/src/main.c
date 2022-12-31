#include <hellfire.h>

Application* application_create(void)
{
	Application* app = memory_system_malloc(sizeof(Application), HF_MEMORY_TAG_UNKNOWN);
	app->width = 1600;
	app->height = 900;
	app->title = "Hellfire-Editor";
	return app;
}