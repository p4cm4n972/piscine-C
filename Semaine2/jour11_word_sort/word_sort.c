/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_strlen - Calcule la longueur d'une chaîne
** @str: la chaîne à mesurer
** Return: le nombre de caractères (sans le '\0')
*/
int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
** ft_putstr - Affiche une chaîne sur la sortie standard
** @str: la chaîne à afficher
*/
void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

/*
** ft_strcmp - Compare deux chaînes caractère par caractère
** @s1: première chaîne
** @s2: deuxième chaîne
** Return: différence ASCII du premier caractère différent, ou 0 si égales
**
** Principe: Compare jusqu'à trouver une différence ou la fin d'une chaîne
** - Return < 0 si s1 < s2
** - Return > 0 si s1 > s2
** - Return 0 si s1 == s2
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
** ft_swap_str - Échange deux pointeurs de chaînes
** @a: pointeur vers le premier pointeur de chaîne
** @b: pointeur vers le deuxième pointeur de chaîne
**
** Note: On échange les pointeurs, pas les contenus des chaînes
** C'est plus efficace car argv pointe vers des zones en lecture seule
*/
void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** ft_sort_words - Trie un tableau de chaînes par ordre ASCII (bubble sort)
** @tab: tableau de pointeurs vers les chaînes
** @size: nombre d'éléments dans le tableau
**
** Algorithme: Bubble Sort
** - Complexité: O(n²) dans le pire cas
** - Stable: oui (ordre relatif des égaux préservé)
** - En place: oui (pas d'allocation supplémentaire)
**
** Principe:
** 1. Parcourir le tableau du début à l'avant-dernière position non triée
** 2. Pour chaque position, comparer avec l'élément suivant
** 3. Si mal ordonné, échanger
** 4. Répéter jusqu'à ce qu'aucun échange ne soit nécessaire
*/
void	ft_sort_words(char **tab, int size)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap_str(&tab[j], &tab[j + 1]);
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

/*
** ft_print_words - Affiche les mots séparés par des espaces
** @tab: tableau de mots
** @size: nombre de mots
*/
void	ft_print_words(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		if (i < size - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

/*
** Programme principal
**
** Usage: ./word_sort mot1 mot2 mot3 ...
** Affiche les mots triés par ordre alphabétique ASCII
**
** Exemples:
** ./word_sort pomme banane cerise   -> banane cerise pomme
** ./word_sort Zorro alice Bob       -> Bob Zorro alice (majuscules < minuscules)
** ./word_sort a A b B               -> A B a b
*/
int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Usage: ./word_sort mot1 [mot2] [mot3] ...\n");
		return (1);
	}
	ft_sort_words(argv + 1, argc - 1);
	ft_print_words(argv + 1, argc - 1);
	return (0);
}
