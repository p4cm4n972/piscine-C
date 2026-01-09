/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** EXERCICE BONUS : Générateur de combinaisons
**
** Ce programme génère toutes les combinaisons de N chiffres dont la somme
** égale une valeur cible. Utilise la récursivité (backtracking).
**
** Concepts 42/Epitech :
** - Récursivité avec backtracking
** - Génération combinatoire
** - Optimisation par élagage (pruning)
**
** Exemple : pour n=3, target=6
** Sorties : 006, 015, 024, 033, 042, 051, 060, 105, 114, ...
*/

#include <unistd.h>

/*
** ft_putchar - Affiche un caractère
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** ft_putnbr - Affiche un nombre
*/
void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

/*
** ft_putstr - Affiche une chaîne
*/
void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

/*
** print_combination - Affiche une combinaison de chiffres
** @arr: tableau contenant la combinaison
** @n: taille de la combinaison
*/
void	print_combination(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar('0' + arr[i]);
		i++;
	}
	ft_putchar('\n');
}

/*
** count_combinations - Compte les combinaisons (sans afficher)
** @depth: profondeur actuelle (nombre de chiffres placés)
** @n: nombre total de chiffres à placer
** @target: somme cible
** @start: chiffre minimum à utiliser (0-9)
** @current_sum: somme actuelle
** Return: nombre de combinaisons trouvées
*/
int	count_combinations(int depth, int n, int target, int start, int sum)
{
	int	count;
	int	i;
	int	remaining;

	if (depth == n)
	{
		if (sum == target)
			return (1);
		return (0);
	}
	count = 0;
	i = start;
	while (i <= 9)
	{
		remaining = n - depth - 1;
		if (sum + i + remaining * 9 >= target && sum + i <= target)
			count += count_combinations(depth + 1, n, target, i, sum + i);
		i++;
	}
	return (count);
}

/*
** generate_combinations - Génère toutes les combinaisons récursivement
** @arr: tableau pour stocker la combinaison courante
** @depth: profondeur actuelle (nombre de chiffres placés)
** @n: nombre total de chiffres à placer
** @target: somme cible
** @start: chiffre minimum à utiliser (évite les doublons)
** @current_sum: somme actuelle des chiffres placés
**
** Algorithme : Backtracking avec optimisation
** 1. Si depth == n (tous les chiffres placés):
**    - Si sum == target: afficher la combinaison
**    - Sinon: backtrack
** 2. Pour chaque chiffre de start à 9:
**    - Placer le chiffre dans arr[depth]
**    - Récurser avec depth+1, start=i (éviter doublons)
**    - Élagage: si somme impossible, skip
**
** Optimisation (Pruning):
** - Si sum + i > target: inutile de continuer (impossible)
** - Si sum + i + (remaining * 9) < target: impossible d'atteindre target
*/
void	generate_combinations(int *arr, int depth, int n, int target,
								int start, int current_sum)
{
	int	i;
	int	remaining_slots;
	int	max_possible;
	int	min_needed;

	if (depth == n)
	{
		if (current_sum == target)
			print_combination(arr, n);
		return ;
	}
	i = start;
	while (i <= 9)
	{
		remaining_slots = n - depth - 1;
		max_possible = current_sum + i + (remaining_slots * 9);
		min_needed = current_sum + i;
		if (max_possible >= target && min_needed <= target)
		{
			arr[depth] = i;
			generate_combinations(arr, depth + 1, n, target, i,
				current_sum + i);
		}
		i++;
	}
}

/*
** Programme principal - Démo des combinaisons
**
** Génère et affiche toutes les combinaisons de 3 chiffres dont la somme = 6
** Puis affiche le compte total
*/
int	main(void)
{
	int	arr[10];
	int	n;
	int	target;
	int	count;

	n = 3;
	target = 6;
	ft_putstr("╔════════════════════════════════════════╗\n");
	ft_putstr("║    GÉNÉRATEUR DE COMBINAISONS          ║\n");
	ft_putstr("╚════════════════════════════════════════╝\n\n");
	ft_putstr("Combinaisons de ");
	ft_putnbr(n);
	ft_putstr(" chiffres dont la somme = ");
	ft_putnbr(target);
	ft_putstr("\n\n");
	generate_combinations(arr, 0, n, target, 0, 0);
	count = count_combinations(0, n, target, 0, 0);
	ft_putstr("\nTotal: ");
	ft_putnbr(count);
	ft_putstr(" combinaisons\n\n");
	ft_putstr("Algorithme: Backtracking avec élagage (pruning)\n");
	ft_putstr("Complexité: O(10^n) sans pruning, beaucoup moins avec\n");
	return (0);
}
