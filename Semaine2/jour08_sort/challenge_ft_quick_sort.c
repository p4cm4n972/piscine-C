/*
** CHALLENGE : ft_quick_sort
**
** Implémente l'algorithme Quick Sort (tri rapide) de Tony Hoare (1960).
** C'est l'un des algorithmes de tri les plus utilisés en pratique.
**
** Prototype :
** void ft_quick_sort(int *tab, int left, int right);
**
** Principe :
** 1. Choisir un pivot (élément de référence)
** 2. Partitionner : éléments < pivot à gauche, > pivot à droite
** 3. Trier récursivement les deux partitions
**
** Complexité :
** - Moyenne : O(n log n)
** - Pire cas : O(n²) si tableau déjà trié et pivot = premier élément
** - Espace : O(log n) à cause de la récursion
**
** Exemple :
** {5, 2, 9, 1, 7, 6} -> {1, 2, 5, 6, 7, 9}
*/

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_partition(int *tab, int left, int right)
{
	// TODO: Implémente la fonction de partition
	// 1. Choisir le pivot (par exemple, le dernier élément : tab[right])
	// 2. Initialiser l'index du plus petit élément (i = left - 1)
	// 3. Parcourir de left à right-1
	//    - Si tab[j] <= pivot, incrémenter i et échanger tab[i] avec tab[j]
	// 4. Échanger tab[i+1] avec le pivot
	// 5. Retourner i+1 (position finale du pivot)

	return (0); // À remplacer
}

void	ft_quick_sort(int *tab, int left, int right)
{
	// TODO: Implémente Quick Sort
	// 1. Cas de base : si left >= right, retourner
	// 2. Partitionner le tableau et obtenir l'index du pivot
	// 3. Trier récursivement la partie gauche (left à pivot-1)
	// 4. Trier récursivement la partie droite (pivot+1 à right)
}

void	print_array(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}

int	main(void)
{
	int	tab1[] = {5, 2, 9, 1, 7, 6};
	int	tab2[] = {10, 7, 8, 9, 1, 5};
	int	tab3[] = {64, 34, 25, 12, 22, 11, 90};
	int	tab4[] = {3, 0, 2, 5, -1, 4, 1};

	printf("=== Test 1 ===\n");
	printf("Avant : ");
	print_array(tab1, 6);
	ft_quick_sort(tab1, 0, 5);
	printf("Après : ");
	print_array(tab1, 6);

	printf("\n=== Test 2 ===\n");
	printf("Avant : ");
	print_array(tab2, 6);
	ft_quick_sort(tab2, 0, 5);
	printf("Après : ");
	print_array(tab2, 6);

	printf("\n=== Test 3 ===\n");
	printf("Avant : ");
	print_array(tab3, 7);
	ft_quick_sort(tab3, 0, 6);
	printf("Après : ");
	print_array(tab3, 7);

	printf("\n=== Test 4 (avec négatifs) ===\n");
	printf("Avant : ");
	print_array(tab4, 7);
	ft_quick_sort(tab4, 0, 6);
	printf("Après : ");
	print_array(tab4, 7);

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Avant : 5 2 9 1 7 6
** Après : 1 2 5 6 7 9
**
** === Test 2 ===
** Avant : 10 7 8 9 1 5
** Après : 1 5 7 8 9 10
**
** === Test 3 ===
** Avant : 64 34 25 12 22 11 90
** Après : 11 12 22 25 34 64 90
**
** === Test 4 (avec négatifs) ===
** Avant : 3 0 2 5 -1 4 1
** Après : -1 0 1 2 3 4 5
**
** BONUS :
** - Chronomètre : < 30 min
** - Implémente une version optimisée avec pivot médian
** - Compare les performances avec bubble_sort sur 10000 éléments
** - Visualise le nombre d'appels récursifs
**
** 📚 THÉORIE :
** Quick Sort est un algorithme "divide and conquer" (diviser pour régner).
** Il est très efficace en pratique grâce à sa bonne utilisation du cache.
** C'est l'algorithme utilisé par la fonction qsort() de la libc.
**
** Stratégies de choix du pivot :
** - Premier élément (simple mais mauvais si tableau déjà trié)
** - Dernier élément (idem)
** - Médian de 3 (début, milieu, fin) - meilleur en pratique
** - Aléatoire - garantit O(n log n) en moyenne
*/
