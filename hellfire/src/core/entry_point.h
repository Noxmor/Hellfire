#ifndef HF_ENTRY_POINT_H
#define HF_ENTRY_POINT_H

#include <stdlib.h>
#include <stdio.h>

#include "core/core.h"
#include "core/application.h"

extern Application* application_create(void);

int main(void)
{
	printf("Creating application...\n");
	Application* app = application_create();

	printf("Running application..\n");
	application_run(app);

	printf("Shutting down application...\n");
	free(app);
}

#endif