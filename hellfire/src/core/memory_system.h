#ifndef HF_MEMORY_SYSTEM_H
#define HF_MEMORY_SYSTEM_H

#include "core/core.h"

typedef enum MemoryTag
{
	HF_MEMORY_TAG_UNKNOWN = 0,

	HF_MEMORY_TAG_MAX
} MemoryTag;

void memory_system_init(void);

void memory_system_shutdown(void);

void* memory_system_malloc(u64 size, MemoryTag tag);

void* memory_system_calloc(u64 count, u64 size, MemoryTag tag);

void memory_system_free(void* memory, u64 size, MemoryTag tag);

#endif