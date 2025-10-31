/*
** EXERCICE : ft_malloc_basics
**
** Exemples de base d'utilisation de malloc, calloc, realloc et free.
** Ce fichier contient plusieurs petits exercices pour comprendre l'allocation dynamique.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
** EXERCICE 1 : Allouer un tableau d'entiers
*/
void example_malloc_array(void)
{
	int *arr;
	int size = 5;
	int i;

	printf("=== EXERCICE 1 : malloc tableau ===\n");

	// Allouer le tableau
	arr = malloc(sizeof(int) * size);
	if (!arr)
	{
		printf("Erreur malloc\n");
		return;
	}

	// Initialiser
	for (i = 0; i < size; i++)
		arr[i] = i * 10;

	// Afficher
	printf("Tableau : ");
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// Libérer
	free(arr);
	printf("Mémoire libérée\n\n");
}

/*
** EXERCICE 2 : Différence malloc vs calloc
*/
void example_malloc_vs_calloc(void)
{
	int *arr1, *arr2;
	int size = 5;
	int i;

	printf("=== EXERCICE 2 : malloc vs calloc ===\n");

	// malloc : mémoire NON initialisée
	arr1 = malloc(sizeof(int) * size);
	printf("malloc (NON initialisé) : ");
	for (i = 0; i < size; i++)
		printf("%d ", arr1[i]);  // Valeurs aléatoires !
	printf("\n");

	// calloc : mémoire initialisée à 0
	arr2 = calloc(size, sizeof(int));
	printf("calloc (initialisé à 0) : ");
	for (i = 0; i < size; i++)
		printf("%d ", arr2[i]);  // Tous à 0
	printf("\n");

	free(arr1);
	free(arr2);
	printf("Mémoire libérée\n\n");
}

/*
** EXERCICE 3 : Utilisation de realloc
*/
void example_realloc(void)
{
	int *arr;
	int old_size = 3;
	int new_size = 6;
	int i;

	printf("=== EXERCICE 3 : realloc ===\n");

	// Allocation initiale
	arr = malloc(sizeof(int) * old_size);
	for (i = 0; i < old_size; i++)
		arr[i] = i + 1;

	printf("Tableau initial (taille %d) : ", old_size);
	for (i = 0; i < old_size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	// Redimensionner
	arr = realloc(arr, sizeof(int) * new_size);
	if (!arr)
	{
		printf("Erreur realloc\n");
		return;
	}

	// Initialiser les nouveaux éléments
	for (i = old_size; i < new_size; i++)
		arr[i] = i + 1;

	printf("Tableau agrandi (taille %d) : ", new_size);
	for (i = 0; i < new_size; i++)
		printf("%d ", arr[i]);
	printf("\n");

	free(arr);
	printf("Mémoire libérée\n\n");
}

/*
** EXERCICE 4 : Allocation de chaîne de caractères
*/
void example_string_allocation(void)
{
	char *str;
	int len = 20;

	printf("=== EXERCICE 4 : Allocation de chaîne ===\n");

	// Allouer
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		printf("Erreur malloc\n");
		return;
	}

	// Copier une chaîne
	strcpy(str, "Hello malloc!");
	printf("Chaîne : %s\n", str);

	// Modifier
	str[0] = 'h';  // "hello malloc!"
	printf("Modifiée : %s\n", str);

	// Libérer
	free(str);
	printf("Mémoire libérée\n\n");
}

/*
** EXERCICE 5 : Tableau 2D (matrice)
*/
void example_2d_array(void)
{
	int **matrix;
	int rows = 3;
	int cols = 4;
	int i, j;

	printf("=== EXERCICE 5 : Tableau 2D ===\n");

	// Allouer les lignes
	matrix = malloc(sizeof(int *) * rows);
	if (!matrix)
		return;

	// Allouer chaque colonne
	for (i = 0; i < rows; i++)
	{
		matrix[i] = malloc(sizeof(int) * cols);
		if (!matrix[i])
			return;
	}

	// Initialiser
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			matrix[i][j] = i * cols + j;

	// Afficher
	printf("Matrice %dx%d :\n", rows, cols);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}

	// Libérer (dans l'ordre inverse !)
	for (i = 0; i < rows; i++)
		free(matrix[i]);
	free(matrix);
	printf("Mémoire libérée\n\n");
}

/*
** EXERCICE 6 : Erreurs courantes
*/
void example_common_errors(void)
{
	int *ptr;

	printf("=== EXERCICE 6 : Erreurs courantes ===\n");

	// ERREUR 1 : Utiliser sans allouer
	// ptr[0] = 42;  // ❌ SEGFAULT ! ptr non initialisé

	// CORRECT : Toujours allouer d'abord
	ptr = malloc(sizeof(int) * 5);
	if (ptr)
	{
		ptr[0] = 42;  // ✅ OK
		printf("ptr[0] = %d\n", ptr[0]);

		// ERREUR 2 : Oublier de free
		// return;  // ❌ FUITE MÉMOIRE !

		// CORRECT : Toujours free
		free(ptr);  // ✅ OK
		printf("Mémoire libérée correctement\n");

		// ERREUR 3 : Utiliser après free
		// ptr[0] = 10;  // ❌ USE AFTER FREE !

		// ERREUR 4 : Double free
		// free(ptr);  // ❌ DOUBLE FREE !
	}

	printf("\n");
}

int main(void)
{
	example_malloc_array();
	example_malloc_vs_calloc();
	example_realloc();
	example_string_allocation();
	example_2d_array();
	example_common_errors();

	printf("=== Tous les tests réussis ! ===\n");
	printf("\nTest avec valgrind :\n");
	printf("valgrind --leak-check=full ./ft_malloc_basics\n");
	printf("Résultat attendu : no leaks are possible\n");

	return (0);
}

/*
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror -g ft_malloc_basics.c -o ft_malloc_basics
** valgrind --leak-check=full ./ft_malloc_basics
**
** 📚 THÉORIE :
**
** malloc(size)
** - Alloue 'size' octets
** - Retourne un pointeur vers la mémoire
** - Mémoire NON initialisée (valeurs aléatoires)
** - Retourne NULL si échec
**
** calloc(n, size)
** - Alloue n éléments de 'size' octets
** - Initialise tout à 0
** - Équivalent à malloc + memset(0)
**
** realloc(ptr, new_size)
** - Redimensionne un bloc mémoire
** - Copie les anciennes données
** - Peut déplacer le bloc en mémoire
** - Si ptr == NULL, équivalent à malloc
**
** free(ptr)
** - Libère la mémoire allouée
** - Après free, ptr est invalide
** - Ne jamais free deux fois le même pointeur
**
** ⚠️ RÈGLES D'OR :
** 1. Toujours vérifier si malloc a réussi (if (!ptr))
** 2. Toujours free ce qui a été alloué
** 3. Ne jamais utiliser après free
** 4. Ne jamais double free
** 5. Initialiser les pointeurs (ou à NULL)
**
** ORDRE DE LIBÉRATION :
** Pour un tableau 2D :
** 1. Libérer chaque ligne : for (i = 0; i < rows; i++) free(matrix[i])
** 2. Libérer le tableau : free(matrix)
**
** OUTILS :
** - valgrind : détecte les fuites et erreurs mémoire
** - gcc -fsanitize=address : AddressSanitizer (détection en temps réel)
*/
