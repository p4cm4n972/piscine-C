/*
** CHALLENGE : ft_merge_sort
**
** Implémente l'algorithme Merge Sort (tri fusion) de John von Neumann (1945).
** Algorithme stable et prévisible, toujours O(n log n).
**
** Prototype :
** void ft_merge_sort(int *tab, int left, int right);
**
** Principe :
** 1. Diviser le tableau en deux moitiés
** 2. Trier récursivement chaque moitié
** 3. Fusionner les deux moitiés triées
**
** Complexité :
** - Toujours : O(n log n) - meilleur, moyen et pire cas
** - Espace : O(n) - nécessite un tableau temporaire
** - Stable : conserve l'ordre relatif des éléments égaux
**
** Exemple :
** {5, 2, 9, 1, 7, 6} -> {1, 2, 5, 6, 7, 9}
*/

#include <stdio.h>
#include <stdlib.h>

void	ft_merge(int *tab, int left, int mid, int right)
{
	// TODO: Implémente la fusion de deux sous-tableaux triés
	// 1. Calcule les tailles : n1 = mid - left + 1, n2 = right - mid
	// 2. Crée deux tableaux temporaires L[n1] et R[n2]
	// 3. Copie les données dans L et R
	// 4. Fusionne L et R dans tab :
	//    - Compare L[i] et R[j]
	//    - Place le plus petit dans tab[k]
	// 5. Copie les éléments restants (s'il y en a)
	//
	// Astuce : utilise malloc pour les tableaux temporaires
	// N'oublie pas le free !
}

void	ft_merge_sort(int *tab, int left, int right)
{
	// TODO: Implémente Merge Sort
	// 1. Cas de base : si left >= right, retourner
	// 2. Calculer le milieu : mid = left + (right - left) / 2
	// 3. Trier récursivement la moitié gauche : ft_merge_sort(tab, left, mid)
	// 4. Trier récursivement la moitié droite : ft_merge_sort(tab, mid+1, right)
	// 5. Fusionner les deux moitiés : ft_merge(tab, left, mid, right)
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
	int	tab5[] = {1};
	int	tab6[] = {2, 1};

	printf("=== Test 1 ===\n");
	printf("Avant : ");
	print_array(tab1, 6);
	ft_merge_sort(tab1, 0, 5);
	printf("Après : ");
	print_array(tab1, 6);

	printf("\n=== Test 2 ===\n");
	printf("Avant : ");
	print_array(tab2, 6);
	ft_merge_sort(tab2, 0, 5);
	printf("Après : ");
	print_array(tab2, 6);

	printf("\n=== Test 3 ===\n");
	printf("Avant : ");
	print_array(tab3, 7);
	ft_merge_sort(tab3, 0, 6);
	printf("Après : ");
	print_array(tab3, 7);

	printf("\n=== Test 4 (avec négatifs) ===\n");
	printf("Avant : ");
	print_array(tab4, 7);
	ft_merge_sort(tab4, 0, 6);
	printf("Après : ");
	print_array(tab4, 7);

	printf("\n=== Test 5 (un élément) ===\n");
	printf("Avant : ");
	print_array(tab5, 1);
	ft_merge_sort(tab5, 0, 0);
	printf("Après : ");
	print_array(tab5, 1);

	printf("\n=== Test 6 (deux éléments) ===\n");
	printf("Avant : ");
	print_array(tab6, 2);
	ft_merge_sort(tab6, 0, 1);
	printf("Après : ");
	print_array(tab6, 2);

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
** === Test 5 (un élément) ===
** Avant : 1
** Après : 1
**
** === Test 6 (deux éléments) ===
** Avant : 2 1
** Après : 1 2
**
** BONUS :
** - Chronomètre : < 40 min
** - Version bottom-up (itérative, sans récursion)
** - Compare avec Quick Sort sur 100000 éléments
** - Vérifie qu'il n'y a pas de fuites mémoire avec valgrind
**
** 📚 THÉORIE :
** Merge Sort est un algorithme "divide and conquer" stable.
**
** Avantages :
** - Complexité garantie O(n log n) dans tous les cas
** - Stable (conserve l'ordre relatif)
** - Prédictible, pas de pire cas en O(n²)
** - Excellent pour trier des listes chaînées (pas besoin de malloc)
**
** Inconvénients :
** - Nécessite O(n) d'espace supplémentaire
** - Plus lent que Quick Sort en pratique (sur tableaux)
** - Pas de tri "en place"
**
** Utilisations :
** - Tri de fichiers énormes (tri externe)
** - Listes chaînées
** - Python (Timsort est basé sur Merge Sort)
** - Java (pour trier des objets)
*/
