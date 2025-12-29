/*
 * challenge_ft_realloc_safe.c
 * Wrapper sécurisé pour realloc
 *
 * Objectif : Gérer realloc de manière sûre
 *
 * PROBLÈME AVEC realloc() :
 * Si realloc échoue, il retourne NULL mais ne libère PAS le bloc original.
 * Si on fait : ptr = realloc(ptr, new_size)
 * et que realloc échoue, on perd la référence au bloc original = FUITE MÉMOIRE
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * VERSION NON SÉCURISÉE (❌ MAUVAIS)
 * Si realloc échoue, on perd ptr
 */
void example_unsafe_realloc(void)
{
	int		*ptr;
	size_t	i;

	printf("=== EXEMPLE UNSAFE (❌) ===\n");

	ptr = malloc(sizeof(int) * 5);
	if (!ptr)
		return;

	// Remplir
	for (i = 0; i < 5; i++)
		ptr[i] = i;

	printf("Avant realloc : ");
	for (i = 0; i < 5; i++)
		printf("%d ", ptr[i]);
	printf("\n");

	// ❌ DANGEREUX : si realloc échoue, ptr devient NULL
	// et on perd la référence au bloc original
	ptr = realloc(ptr, sizeof(int) * 10);

	if (!ptr)
	{
		printf("❌ ERREUR : realloc a échoué ET on a perdu le bloc original\n");
		// FUITE MÉMOIRE : impossible de free le bloc original
		return;
	}

	printf("Après realloc réussi\n");
	free(ptr);
}

/*
 * ft_realloc_safe
 *
 * Wrapper sécurisé pour realloc
 * Si realloc échoue, on garde la référence au bloc original
 *
 * Paramètres :
 *   ptr      : Pointeur vers le bloc à redimensionner
 *   old_size : Ancienne taille en bytes
 *   new_size : Nouvelle taille en bytes
 *
 * Retour :
 *   Pointeur vers le nouveau bloc (ou NULL si échec, mais ptr reste intact)
 */
void *ft_realloc_safe(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	// Si ptr est NULL, realloc se comporte comme malloc
	if (!ptr)
		return (malloc(new_size));

	// Si new_size est 0, realloc se comporte comme free
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	// Tenter le realloc
	new_ptr = realloc(ptr, new_size);

	// Si realloc a échoué, ptr est toujours valide
	if (!new_ptr)
	{
		// On pourrait logger une erreur ici
		printf("⚠️  realloc a échoué, bloc original préservé\n");
		return (NULL);
	}

	// Succès
	return (new_ptr);
}

/*
 * VERSION SÉCURISÉE (✅ BON)
 */
void example_safe_realloc(void)
{
	int		*ptr;
	int		*new_ptr;
	size_t	i;

	printf("\n=== EXEMPLE SAFE (✅) ===\n");

	ptr = malloc(sizeof(int) * 5);
	if (!ptr)
		return;

	// Remplir
	for (i = 0; i < 5; i++)
		ptr[i] = i;

	printf("Avant realloc : ");
	for (i = 0; i < 5; i++)
		printf("%d ", ptr[i]);
	printf("\n");

	// ✅ BON : on utilise une variable temporaire
	new_ptr = ft_realloc_safe(ptr, sizeof(int) * 5, sizeof(int) * 10);

	if (!new_ptr)
	{
		printf("⚠️  realloc a échoué MAIS on a toujours ptr\n");
		printf("On peut encore utiliser le bloc original :\n");
		for (i = 0; i < 5; i++)
			printf("%d ", ptr[i]);
		printf("\n");
		free(ptr); // ✅ On peut libérer proprement
		return;
	}

	// Succès : mettre à jour ptr
	ptr = new_ptr;

	// Remplir les nouvelles cases
	for (i = 5; i < 10; i++)
		ptr[i] = i;

	printf("Après realloc réussi : ");
	for (i = 0; i < 10; i++)
		printf("%d ", ptr[i]);
	printf("\n");

	free(ptr);
}

/*
 * ft_realloc_copy
 *
 * Alternative : réimplémenter realloc avec malloc + memcpy + free
 * Plus sûr mais moins performant (toujours une copie)
 */
void *ft_realloc_copy(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!ptr)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	// Allouer nouveau bloc
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	// Copier les données (minimum entre old et new)
	copy_size = (old_size < new_size) ? old_size : new_size;
	memcpy(new_ptr, ptr, copy_size);

	// Libérer l'ancien bloc
	free(ptr);

	return (new_ptr);
}

/*
 * Exemple d'utilisation avec tableau dynamique
 */
typedef struct s_dynamic_array
{
	int		*data;
	size_t	size;
	size_t	capacity;
}	t_dynamic_array;

t_dynamic_array *create_array(void)
{
	t_dynamic_array *arr;

	arr = malloc(sizeof(t_dynamic_array));
	if (!arr)
		return (NULL);

	arr->capacity = 4;
	arr->size = 0;
	arr->data = malloc(sizeof(int) * arr->capacity);

	if (!arr->data)
	{
		free(arr);
		return (NULL);
	}

	return (arr);
}

int push_back(t_dynamic_array *arr, int value)
{
	int		*new_data;
	size_t	new_capacity;

	if (!arr)
		return (-1);

	// Si plein, doubler la capacité
	if (arr->size >= arr->capacity)
	{
		new_capacity = arr->capacity * 2;
		new_data = ft_realloc_safe(arr->data,
									arr->capacity * sizeof(int),
									new_capacity * sizeof(int));

		if (!new_data)
			return (-1); // Échec, mais arr->data est toujours valide

		arr->data = new_data;
		arr->capacity = new_capacity;
		printf("  ↗ Capacité doublée : %zu -> %zu\n",
				arr->capacity / 2, arr->capacity);
	}

	arr->data[arr->size] = value;
	arr->size++;
	return (0);
}

void print_array(t_dynamic_array *arr)
{
	size_t i;

	if (!arr)
		return;

	printf("  Array [size=%zu, capacity=%zu] : ", arr->size, arr->capacity);
	for (i = 0; i < arr->size; i++)
		printf("%d ", arr->data[i]);
	printf("\n");
}

void free_array(t_dynamic_array *arr)
{
	if (!arr)
		return;
	free(arr->data);
	free(arr);
}

void example_dynamic_array(void)
{
	t_dynamic_array	*arr;
	int				i;

	printf("\n=== EXEMPLE DYNAMIC ARRAY ===\n");

	arr = create_array();
	if (!arr)
	{
		printf("Erreur création\n");
		return;
	}

	printf("Création array vide\n");
	print_array(arr);

	// Ajouter 10 éléments
	printf("\nAjout de 10 éléments :\n");
	for (i = 0; i < 10; i++)
	{
		push_back(arr, i * 10);
		if (i == 3 || i == 7 || i == 9)
			print_array(arr);
	}

	free_array(arr);
	printf("Mémoire libérée\n");
}

/*
 * MAIN
 */
int main(void)
{
	printf("╔════════════════════════════════════════════╗\n");
	printf("║    CHALLENGE : ft_realloc_safe             ║\n");
	printf("╚════════════════════════════════════════════╝\n\n");

	example_unsafe_realloc();
	example_safe_realloc();
	example_dynamic_array();

	printf("\n╔════════════════════════════════════════════╗\n");
	printf("║              TESTS RÉUSSIS                 ║\n");
	printf("╚════════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION ET TESTS
 *
 * gcc -Wall -Wextra -Werror -g challenge_ft_realloc_safe.c -o realloc_safe
 * ./realloc_safe
 *
 * # Vérifier avec valgrind
 * valgrind --leak-check=full ./realloc_safe
 *
 * CONCEPTS CLÉS :
 *
 * 1. PROBLÈME avec realloc :
 *    ptr = realloc(ptr, new_size);
 *    Si realloc échoue, ptr devient NULL et on perd le bloc original
 *
 * 2. SOLUTION :
 *    new_ptr = realloc(ptr, new_size);
 *    if (!new_ptr) {
 *        // ptr est toujours valide
 *        free(ptr);
 *    } else {
 *        ptr = new_ptr;
 *    }
 *
 * 3. WRAPPER SÉCURISÉ :
 *    - Utiliser une variable temporaire
 *    - Vérifier le retour
 *    - Garder la référence au bloc original si échec
 *
 * 4. CAS PARTICULIERS :
 *    - realloc(NULL, size)  → équivalent à malloc(size)
 *    - realloc(ptr, 0)      → équivalent à free(ptr)
 *
 * 5. ALTERNATIVE :
 *    - malloc + memcpy + free
 *    - Plus sûr mais moins performant
 *    - Toujours une copie mémoire
 *
 * 6. UTILISATION PRATIQUE :
 *    - Tableaux dynamiques
 *    - Buffers redimensionnables
 *    - Doubler la capacité quand plein
 */
