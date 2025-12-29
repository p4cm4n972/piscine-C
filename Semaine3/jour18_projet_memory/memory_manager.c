/*
 * memory_manager.c - Implémentation du Memory Manager
 */

#include "memory_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static t_memory_manager g_mm = {NULL, 0, NULL, 0, 0, 0, 0};

size_t mm_align(size_t size)
{
	return ((size + ALIGNMENT - 1) & ~(ALIGNMENT - 1));
}

int mm_init(size_t size)
{
	if (g_mm.pool)
	{
		printf("❌ Memory manager déjà initialisé\n");
		return (-1);
	}

	g_mm.pool_size = mm_align(size);
	g_mm.pool = malloc(g_mm.pool_size);
	if (!g_mm.pool)
	{
		printf("❌ Échec allocation du pool\n");
		return (-1);
	}

	// Créer le premier bloc (tout le pool est libre)
	g_mm.free_list = (t_block_header *)g_mm.pool;
	g_mm.free_list->size = g_mm.pool_size - sizeof(t_block_header);
	g_mm.free_list->is_free = 1;
	g_mm.free_list->next = NULL;

	g_mm.allocated = 0;
	g_mm.freed = 0;
	g_mm.alloc_count = 0;
	g_mm.free_count = 0;

	printf("✓ Memory manager initialisé (%zu bytes)\n", g_mm.pool_size);
	return (0);
}

void *mm_alloc(size_t size)
{
	t_block_header	*current;
	t_block_header	*new_block;
	size_t			aligned_size;
	void			*ptr;

	if (!g_mm.pool)
	{
		printf("❌ Memory manager non initialisé\n");
		return (NULL);
	}

	aligned_size = mm_align(size);
	current = g_mm.free_list;

	// Chercher un bloc libre suffisamment grand (first-fit)
	while (current)
	{
		if (current->is_free && current->size >= aligned_size)
		{
			// Bloc trouvé
			current->is_free = 0;

			// Si le bloc est trop grand, le diviser
			if (current->size >= aligned_size + sizeof(t_block_header) + ALIGNMENT)
			{
				new_block = (t_block_header *)((char *)current + sizeof(t_block_header) + aligned_size);
				new_block->size = current->size - aligned_size - sizeof(t_block_header);
				new_block->is_free = 1;
				new_block->next = current->next;

				current->size = aligned_size;
				current->next = new_block;
			}

			g_mm.allocated += current->size;
			g_mm.alloc_count++;

			ptr = (void *)((char *)current + sizeof(t_block_header));
			return (ptr);
		}
		current = current->next;
	}

	printf("❌ Pas assez de mémoire (demandé: %zu bytes)\n", size);
	return (NULL);
}

void mm_free(void *ptr)
{
	t_block_header *header;

	if (!ptr)
		return;

	if (!g_mm.pool)
	{
		printf("❌ Memory manager non initialisé\n");
		return;
	}

	header = (t_block_header *)((char *)ptr - sizeof(t_block_header));

	if (header->is_free)
	{
		printf("⚠️  Double free détecté!\n");
		return;
	}

	header->is_free = 1;
	g_mm.freed += header->size;
	g_mm.free_count++;
}

void mm_stats(void)
{
	t_block_header *current;
	int free_blocks = 0;
	int used_blocks = 0;
	size_t free_memory = 0;

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║      MEMORY MANAGER STATISTICS         ║\n");
	printf("╚════════════════════════════════════════╝\n");

	printf("Pool size       : %zu bytes\n", g_mm.pool_size);
	printf("Allocated total : %zu bytes\n", g_mm.allocated);
	printf("Freed total     : %zu bytes\n", g_mm.freed);
	printf("Current usage   : %zu bytes\n", g_mm.allocated - g_mm.freed);
	printf("Allocations     : %d\n", g_mm.alloc_count);
	printf("Frees           : %d\n", g_mm.free_count);

	current = g_mm.free_list;
	while (current)
	{
		if (current->is_free)
		{
			free_blocks++;
			free_memory += current->size;
		}
		else
			used_blocks++;
		current = current->next;
	}

	printf("Free blocks     : %d (%zu bytes)\n", free_blocks, free_memory);
	printf("Used blocks     : %d\n", used_blocks);
	printf("════════════════════════════════════════\n\n");
}

int mm_check_leaks(void)
{
	size_t leaks = g_mm.allocated - g_mm.freed;

	printf("╔════════════════════════════════════════╗\n");
	printf("║         LEAK DETECTION                 ║\n");
	printf("╚════════════════════════════════════════╝\n");

	if (leaks == 0)
	{
		printf("✓ Aucune fuite détectée\n");
		return (0);
	}
	else
	{
		printf("❌ Fuites détectées : %zu bytes\n", leaks);
		return (1);
	}
}

void mm_destroy(void)
{
	if (g_mm.pool)
	{
		free(g_mm.pool);
		g_mm.pool = NULL;
		g_mm.free_list = NULL;
		printf("✓ Memory manager détruit\n");
	}
}
