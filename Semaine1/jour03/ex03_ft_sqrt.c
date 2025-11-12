/* ex03_ft_sqrt.c - Racine carrée entière */

/*
** ÉNONCÉ : Retourner racine carrée entière ou 0 si non entière
** sqrt(16) = 4
** sqrt(17) = 0 (pas de racine entière)
*/

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	i = 0;
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

/*
** 🔗 JS : Math.sqrt(nb)
**
** Optimisation : Binary Search O(log n)
** function sqrt(x) {
**     if (x < 2) return x;
**     let left = 1, right = Math.floor(x / 2);
**     while (left <= right) {
**         const mid = Math.floor((left + right) / 2);
**         if (mid * mid === x) return mid;
**         if (mid * mid < x) left = mid + 1;
**         else right = mid - 1;
**     }
**     return 0;
** }
**
** LeetCode #69 - Sqrt(x)
*/

#include <stdio.h>

int	main(void)
{
	printf("=== Test ft_sqrt ===\n");
	printf("sqrt(16) = %d (expected: 4)\n", ft_sqrt(16));
	printf("sqrt(25) = %d (expected: 5)\n", ft_sqrt(25));
	printf("sqrt(17) = %d (expected: 0)\n", ft_sqrt(17));
	printf("sqrt(0) = %d (expected: 0)\n", ft_sqrt(0));
	printf("sqrt(1) = %d (expected: 1)\n", ft_sqrt(1));
	printf("sqrt(100) = %d (expected: 10)\n", ft_sqrt(100));
	printf("sqrt(-4) = %d (expected: 0)\n", ft_sqrt(-4));
	return (0);
}
