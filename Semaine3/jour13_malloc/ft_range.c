/*
** EXERCICE : ft_range
**
** Crée un tableau d'entiers contenant toutes les valeurs entre min et max (exclu).
**
** Prototype :
** int *ft_range(int min, int max);
**
** Comportement :
** - Alloue dynamiquement un tableau d'entiers
** - Remplit avec les valeurs de min à max-1
** - Retourne NULL si min >= max
** - Retourne NULL si malloc échoue
**
** Exemples :
** ft_range(0, 5) -> [0, 1, 2, 3, 4]
** ft_range(-3, 2) -> [-3, -2, -1, 0, 1]
** ft_range(5, 3) -> NULL
**
** Complexité : O(n) où n = max - min
*/

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	// TODO: Implémente ft_range
	// 1. Vérifier que min < max, sinon return NULL
	// 2. Calculer la taille : size = max - min
	// 3. Allouer : int *range = malloc(sizeof(int) * size)
	// 4. Vérifier malloc : if (!range) return NULL
	// 5. Remplir avec une boucle :
	//    for (i = 0; i < size; i++)
	//        range[i] = min + i;
	// 6. Retourner range

	return (NULL);
}

void	print_array(int *arr, int size)
{
	int	i;

	printf("[");
	i = 0;
	while (i < size)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf("]\n");
}

int	main(void)
{
	int	*range;
	int	size;

	printf("=== Test 1 : range(0, 5) ===\n");
	range = ft_range(0, 5);
	if (range)
	{
		size = 5 - 0;
		print_array(range, size);
		free(range);
	}
	else
		printf("NULL\n");

	printf("\n=== Test 2 : range(-3, 2) ===\n");
	range = ft_range(-3, 2);
	if (range)
	{
		size = 2 - (-3);
		print_array(range, size);
		free(range);
	}
	else
		printf("NULL\n");

	printf("\n=== Test 3 : range(5, 10) ===\n");
	range = ft_range(5, 10);
	if (range)
	{
		size = 10 - 5;
		print_array(range, size);
		free(range);
	}
	else
		printf("NULL\n");

	printf("\n=== Test 4 : range(5, 3) - invalide ===\n");
	range = ft_range(5, 3);
	if (range)
	{
		printf("Erreur : devrait retourner NULL\n");
		free(range);
	}
	else
		printf("NULL (correct)\n");

	printf("\n=== Test 5 : range(10, 10) - égaux ===\n");
	range = ft_range(10, 10);
	if (range)
	{
		printf("Erreur : devrait retourner NULL\n");
		free(range);
	}
	else
		printf("NULL (correct)\n");

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 : range(0, 5) ===
** [0, 1, 2, 3, 4]
**
** === Test 2 : range(-3, 2) ===
** [-3, -2, -1, 0, 1]
**
** === Test 3 : range(5, 10) ===
** [5, 6, 7, 8, 9]
**
** === Test 4 : range(5, 3) - invalide ===
** NULL (correct)
**
** === Test 5 : range(10, 10) - égaux ===
** NULL (correct)
**
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror -g ft_range.c -o ft_range
** valgrind --leak-check=full ./ft_range
**
** Résultat valgrind attendu :
** All heap blocks were freed -- no leaks are possible
**
** 📚 THÉORIE :
** ft_range est utile pour créer rapidement des séquences d'entiers.
** C'est similaire à range() en Python.
**
** Utilisations courantes :
** - Initialiser des indices
** - Créer des tableaux de test
** - Itérations avec valeurs spécifiques
**
** Calcul de la taille :
** Si min = 5 et max = 10, on a les valeurs [5, 6, 7, 8, 9]
** Soit 5 éléments = max - min = 10 - 5 = 5
**
** ⚠️ ATTENTION :
** - max est EXCLU (comme dans Python range(0, 5) = [0,1,2,3,4])
** - Toujours vérifier min < max avant d'allouer
** - N'oublie pas le free après utilisation !
**
** BONUS :
** - Chronomètre : < 15 min
** - ft_range_step(min, max, step) : avec pas personnalisé
** - ft_range_reverse(max, min) : ordre décroissant
*/
