/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* Prototypes */
int	ft_find_int(int *tab, int size, int n);
int	ft_binary_search(int *tab, int size, int target);

void	print_array(int *tab, int size)
{
	int	i;

	printf("[");
	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i < size - 1)
			printf(", ");
		i++;
	}
	printf("]");
}

void	test_linear_search(void)
{
	int	tab[] = {42, 17, 89, 3, 65, 28, 91, 54, 12, 76};
	int	size;
	int	result;

	size = 10;
	printf("╔══════════════════════════════════════════╗\n");
	printf("║      RECHERCHE LINÉAIRE - O(n)           ║\n");
	printf("╚══════════════════════════════════════════╝\n\n");
	printf("Tableau: ");
	print_array(tab, size);
	printf("\n\n");
	printf("Test 1: Chercher 65\n");
	result = ft_find_int(tab, size, 65);
	printf("  Résultat: index %d (attendu: 4) %s\n\n",
		result, result == 4 ? "OK" : "FAIL");
	printf("Test 2: Chercher 42 (premier élément)\n");
	result = ft_find_int(tab, size, 42);
	printf("  Résultat: index %d (attendu: 0) %s\n\n",
		result, result == 0 ? "OK" : "FAIL");
	printf("Test 3: Chercher 76 (dernier élément)\n");
	result = ft_find_int(tab, size, 76);
	printf("  Résultat: index %d (attendu: 9) %s\n\n",
		result, result == 9 ? "OK" : "FAIL");
	printf("Test 4: Chercher 100 (non présent)\n");
	result = ft_find_int(tab, size, 100);
	printf("  Résultat: %d (attendu: -1) %s\n\n",
		result, result == -1 ? "OK" : "FAIL");
}

void	test_binary_search(void)
{
	int	tab[] = {1, 5, 12, 23, 34, 45, 56, 67, 78, 89};
	int	size;
	int	result;

	size = 10;
	printf("╔══════════════════════════════════════════╗\n");
	printf("║      RECHERCHE BINAIRE - O(log n)        ║\n");
	printf("╚══════════════════════════════════════════╝\n\n");
	printf("Tableau (TRIÉ): ");
	print_array(tab, size);
	printf("\n\n");
	printf("Test 1: Chercher 34\n");
	result = ft_binary_search(tab, size, 34);
	printf("  Résultat: index %d (attendu: 4) %s\n\n",
		result, result == 4 ? "OK" : "FAIL");
	printf("Test 2: Chercher 1 (premier élément)\n");
	result = ft_binary_search(tab, size, 1);
	printf("  Résultat: index %d (attendu: 0) %s\n\n",
		result, result == 0 ? "OK" : "FAIL");
	printf("Test 3: Chercher 89 (dernier élément)\n");
	result = ft_binary_search(tab, size, 89);
	printf("  Résultat: index %d (attendu: 9) %s\n\n",
		result, result == 9 ? "OK" : "FAIL");
	printf("Test 4: Chercher 50 (non présent)\n");
	result = ft_binary_search(tab, size, 50);
	printf("  Résultat: %d (attendu: -1) %s\n\n",
		result, result == -1 ? "OK" : "FAIL");
	printf("Test 5: Chercher 45 (milieu exact)\n");
	result = ft_binary_search(tab, size, 45);
	printf("  Résultat: index %d (attendu: 5) %s\n\n",
		result, result == 5 ? "OK" : "FAIL");
}

void	compare_performance(void)
{
	printf("╔══════════════════════════════════════════╗\n");
	printf("║      COMPARAISON DES PERFORMANCES        ║\n");
	printf("╚══════════════════════════════════════════╝\n\n");
	printf("Pour un tableau de n éléments:\n\n");
	printf("+---------------+-------------+--------------+\n");
	printf("| Algorithme    | Complexité  | n=1000000    |\n");
	printf("+---------------+-------------+--------------+\n");
	printf("| Linéaire      | O(n)        | 1,000,000    |\n");
	printf("| Binaire       | O(log n)    | 20           |\n");
	printf("+---------------+-------------+--------------+\n\n");
	printf("La recherche binaire est ~50,000x plus rapide !\n");
	printf("MAIS elle nécessite un tableau TRIÉ.\n\n");
}

int	main(void)
{
	printf("\n");
	test_linear_search();
	test_binary_search();
	compare_performance();
	return (0);
}
