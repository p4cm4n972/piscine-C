/*
** CHALLENGE : ft_max
**
** Retourne la plus grande valeur d'un tableau d'entiers.
**
** Prototype :
** int ft_max(int *tab, int size);
**
** Exemples :
** {1, 5, 3, 9, 2} -> 9
** {-10, -5, -20} -> -5
** {42} -> 42
**
** Contraintes :
** - Si size <= 0, retourner 0
** - Parcourir le tableau avec un pointeur
*/

#include <stdio.h>

int	ft_max(int *tab, int size)
{
	// TODO: À toi de coder !
	// Astuce :
	// 1. Vérifie que size > 0
	// 2. Initialise max avec la première valeur du tableau
	// 3. Parcours le reste du tableau
	// 4. Met à jour max si tu trouves une valeur plus grande

	return (0);
}

int	main(void)
{
	int tab1[] = {1, 5, 3, 9, 2};
	int tab2[] = {-10, -5, -20};
	int tab3[] = {42};
	int tab4[] = {100, 99, 98, 97, 200, 50};

	printf("Test 1: max de {1, 5, 3, 9, 2} = %d (attendu: 9)\n",
		ft_max(tab1, 5));
	printf("Test 2: max de {-10, -5, -20} = %d (attendu: -5)\n",
		ft_max(tab2, 3));
	printf("Test 3: max de {42} = %d (attendu: 42)\n",
		ft_max(tab3, 1));
	printf("Test 4: max de {100, 99, 98, 97, 200, 50} = %d (attendu: 200)\n",
		ft_max(tab4, 6));
	printf("Test 5: tableau vide (size=0) = %d (attendu: 0)\n",
		ft_max(tab1, 0));

	return (0);
}

/*
** BONUS :
** - Chronomètre : < 10 min
** - Complexité : O(n)
** - Variante : ft_min (trouve le minimum)
*/
