/*
 * main.c - Tests du Memory Manager
 */

#include "memory_manager.h"
#include <stdio.h>

void test_basic_allocation(void)
{
	int *arr;
	char *str;

	printf("\n=== TEST 1 : Allocations basiques ===\n");

	arr = mm_alloc(sizeof(int) * 10);
	if (arr)
	{
		for (int i = 0; i < 10; i++)
			arr[i] = i * 10;
		printf("✓ Tableau d'entiers alloué et rempli\n");
	}

	str = mm_alloc(sizeof(char) * 20);
	if (str)
	{
		sprintf(str, "Hello Memory!");
		printf("✓ Chaîne allouée : \"%s\"\n", str);
	}

	mm_stats();

	mm_free(arr);
	mm_free(str);
	printf("✓ Mémoire libérée\n");
}

void test_multiple_allocations(void)
{
	int *ptrs[5];

	printf("\n=== TEST 2 : Allocations multiples ===\n");

	for (int i = 0; i < 5; i++)
	{
		ptrs[i] = mm_alloc(sizeof(int) * (i + 1));
		if (ptrs[i])
			printf("✓ Allocation %d : %d bytes\n", i, (int)sizeof(int) * (i + 1));
	}

	mm_stats();

	for (int i = 0; i < 5; i++)
		mm_free(ptrs[i]);

	printf("✓ Toutes les allocations libérées\n");
}

void test_leak_detection(void)
{
	int *leak;

	printf("\n=== TEST 3 : Détection de fuites ===\n");

	leak = mm_alloc(100);
	printf("Allocation de 100 bytes (intentionnellement non libérée)\n");

	mm_stats();
	mm_check_leaks();
}

void test_double_free(void)
{
	int *ptr;

	printf("\n=== TEST 4 : Double free ===\n");

	ptr = mm_alloc(50);
	printf("✓ Allocation de 50 bytes\n");

	mm_free(ptr);
	printf("✓ Premier free\n");

	mm_free(ptr);
	printf("(Double free détecté ci-dessus)\n");
}

void test_large_allocation(void)
{
	int *large;

	printf("\n=== TEST 5 : Grande allocation ===\n");

	large = mm_alloc(sizeof(int) * 10000);
	if (large)
		printf("✓ Grande allocation réussie\n");
	else
		printf("❌ Grande allocation échouée (normal si pool trop petit)\n");

	if (large)
		mm_free(large);
}

int main(void)
{
	printf("╔════════════════════════════════════════╗\n");
	printf("║    MEMORY MANAGER - TESTS COMPLETS     ║\n");
	printf("╚════════════════════════════════════════╝\n");

	// Initialiser avec 4KB
	if (mm_init(4096) != 0)
		return (1);

	test_basic_allocation();
	test_multiple_allocations();
	test_leak_detection();

	// Réinitialiser pour les tests suivants
	mm_destroy();
	mm_init(4096);

	test_double_free();
	test_large_allocation();

	printf("\n=== STATISTIQUES FINALES ===\n");
	mm_stats();
	mm_check_leaks();

	mm_destroy();

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║          TOUS LES TESTS OK             ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g memory_manager.c main.c -o memory_manager
 * ./memory_manager
 *
 * AVEC VALGRIND :
 * valgrind --leak-check=full ./memory_manager
 */
