#include "memory_system.h"

#include <stdlib.h>
#include <string.h>

#include "core/log.h"

typedef struct MemorySystem
{
	u64 allocations;
	u64 tagged_allocations[HF_MEMORY_TAG_MAX];
} MemorySystem;

static MemorySystem memory_system;

void memory_system_init(void)
{
	HF_CORE_INFO("Initializing Memory System...");
	memset(&memory_system, 0, sizeof(memory_system));
	HF_CORE_INFO("Successfully initialized Memory System!");
}

void memory_system_shutdown(void)
{
	HF_CORE_INFO("Shutting down Memory System...");
	HF_CORE_INFO("Successfully shut down Memory System!");
}

void* memory_system_malloc(u64 size, MemoryTag tag)
{
	if (tag == HF_MEMORY_TAG_UNKNOWN)
		HF_CORE_WARN("[MemorySystem]: memory_system_malloc() called with tag HF_MEMORY_TAG_UNKNOWN!");
	
	memory_system.allocations += size;
	memory_system.tagged_allocations[tag] += size;

	return malloc(size);
}

void* memory_system_calloc(u64 count, u64 size, MemoryTag tag)
{
	if (tag == HF_MEMORY_TAG_UNKNOWN)
		HF_CORE_WARN("[MemorySystem]: memory_system_calloc() called with tag HF_MEMORY_TAG_UNKNOWN!");

	memory_system.allocations += size;
	memory_system.tagged_allocations[tag] += size;

	return calloc(count, size);
}

void memory_system_free(void* memory, u64 size, MemoryTag tag)
{
	if (tag == HF_MEMORY_TAG_UNKNOWN)
		HF_CORE_WARN("[MemorySystem]: memory_system_free() called with tag HF_MEMORY_TAG_UNKNOWN!");

	memory_system.allocations -= size;
	memory_system.tagged_allocations[tag] -= size;

	free(memory);
}