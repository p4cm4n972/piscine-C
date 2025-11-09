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
	int	max;
	int	i;

	if (size <= 0)
		return (0);
	max = tab[0];
	i = 1;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
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
** 🔗 JS :
** // Built-in
** Math.max(...arr);
** Math.max.apply(null, arr);
**
** // Reduce
** const max = arr.reduce((max, val) => Math.max(max, val), arr[0]);
**
** // Manual
** function findMax(arr) {
**     if (!arr.length) return null;
**     let max = arr[0];
**     for (let i = 1; i < arr.length; i++) {
**         if (arr[i] > max) max = arr[i];
**     }
**     return max;
** }
**
** Interview : Edge cases (empty array, all negatives)
** Variante : Min, MinMax (return both), Kth largest
** LeetCode #215 - Kth Largest Element
*/
