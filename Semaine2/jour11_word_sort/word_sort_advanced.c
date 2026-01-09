/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_sort_advanced.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/*
** Structure pour stocker les options de tri
** - reverse: tri décroissant si activé
** - ignore_case: ignore la casse si activé
** - numeric: tri numérique si activé
** - unique: n'affiche que les valeurs uniques
*/
typedef struct s_options
{
	int	reverse;
	int	ignore_case;
	int	numeric;
	int	unique;
}	t_options;

/*
** ==================== FONCTIONS UTILITAIRES ====================
*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + n % 10);
}

/*
** ft_tolower - Convertit un caractère en minuscule
*/
char	ft_tolower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
** ft_isdigit - Vérifie si un caractère est un chiffre
*/
int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

/*
** ft_atoi - Convertit une chaîne en entier
*/
int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
** ==================== FONCTIONS DE COMPARAISON ====================
*/

/*
** ft_strcmp_case - Compare deux chaînes (sensible à la casse)
*/
int	ft_strcmp_case(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
** ft_strcmp_nocase - Compare deux chaînes (insensible à la casse)
*/
int	ft_strcmp_nocase(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		i++;
	return ((unsigned char)ft_tolower(s1[i])
		- (unsigned char)ft_tolower(s2[i]));
}

/*
** ft_strcmp_numeric - Compare deux chaînes numériquement
*/
int	ft_strcmp_numeric(char *s1, char *s2)
{
	return (ft_atoi(s1) - ft_atoi(s2));
}

/*
** ft_compare - Fonction de comparaison principale avec options
** @s1, s2: chaînes à comparer
** @opts: options de tri
** Return: résultat de la comparaison (modifié si reverse)
*/
int	ft_compare(char *s1, char *s2, t_options *opts)
{
	int	result;

	if (opts->numeric)
		result = ft_strcmp_numeric(s1, s2);
	else if (opts->ignore_case)
		result = ft_strcmp_nocase(s1, s2);
	else
		result = ft_strcmp_case(s1, s2);
	if (opts->reverse)
		return (-result);
	return (result);
}

/*
** ==================== FONCTIONS DE TRI ====================
*/

void	ft_swap_str(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** ft_sort_words_advanced - Tri avec options (Quick Sort pour efficacité)
** @tab: tableau de mots
** @left: index de début
** @right: index de fin
** @opts: options de tri
**
** Algorithme: Quick Sort
** - Complexité moyenne: O(n log n)
** - En place: oui
*/
void	ft_quicksort(char **tab, int left, int right, t_options *opts)
{
	int		i;
	int		j;
	char	*pivot;

	if (left >= right)
		return ;
	pivot = tab[(left + right) / 2];
	i = left;
	j = right;
	while (i <= j)
	{
		while (ft_compare(tab[i], pivot, opts) < 0)
			i++;
		while (ft_compare(tab[j], pivot, opts) > 0)
			j--;
		if (i <= j)
		{
			ft_swap_str(&tab[i], &tab[j]);
			i++;
			j--;
		}
	}
	ft_quicksort(tab, left, j, opts);
	ft_quicksort(tab, i, right, opts);
}

/*
** ==================== FONCTIONS D'AFFICHAGE ====================
*/

/*
** ft_are_equal - Vérifie si deux chaînes sont égales selon les options
*/
int	ft_are_equal(char *s1, char *s2, t_options *opts)
{
	if (opts->ignore_case)
		return (ft_strcmp_nocase(s1, s2) == 0);
	return (ft_strcmp_case(s1, s2) == 0);
}

/*
** ft_print_words_unique - Affiche les mots en évitant les doublons
*/
void	ft_print_words_unique(char **tab, int size, t_options *opts)
{
	int	i;

	if (size == 0)
		return ;
	ft_putstr(tab[0]);
	i = 1;
	while (i < size)
	{
		if (!ft_are_equal(tab[i], tab[i - 1], opts))
		{
			ft_putchar('\n');
			ft_putstr(tab[i]);
		}
		i++;
	}
	ft_putchar('\n');
}

/*
** ft_print_words - Affiche tous les mots (un par ligne)
*/
void	ft_print_words(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** ==================== PARSING DES OPTIONS ====================
*/

/*
** ft_is_option - Vérifie si l'argument est une option
*/
int	ft_is_option(char *arg)
{
	return (arg[0] == '-' && arg[1] && !ft_isdigit(arg[1]));
}

/*
** ft_parse_option - Parse une option et met à jour la structure
** Return: 1 si option valide, 0 sinon
*/
int	ft_parse_option(char *arg, t_options *opts)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'r')
			opts->reverse = 1;
		else if (arg[i] == 'i')
			opts->ignore_case = 1;
		else if (arg[i] == 'n')
			opts->numeric = 1;
		else if (arg[i] == 'u')
			opts->unique = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

/*
** ft_init_options - Initialise les options à zéro
*/
void	ft_init_options(t_options *opts)
{
	opts->reverse = 0;
	opts->ignore_case = 0;
	opts->numeric = 0;
	opts->unique = 0;
}

/*
** ==================== AFFICHAGE DE L'AIDE ====================
*/

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./word_sort_advanced [OPTIONS] mot1 [mot2] ...\n\n");
	ft_putstr("Trie les mots passés en argument.\n\n");
	ft_putstr("OPTIONS:\n");
	ft_putstr("  -r    Tri inverse (décroissant)\n");
	ft_putstr("  -i    Ignore la casse (a == A)\n");
	ft_putstr("  -n    Tri numérique (10 > 9 > 2)\n");
	ft_putstr("  -u    Unique (supprime les doublons)\n");
	ft_putstr("\nLes options peuvent être combinées: -ri, -rn, -riu\n\n");
	ft_putstr("EXEMPLES:\n");
	ft_putstr("  ./word_sort_advanced pomme banane cerise\n");
	ft_putstr("  -> banane cerise pomme\n\n");
	ft_putstr("  ./word_sort_advanced -r pomme banane cerise\n");
	ft_putstr("  -> pomme cerise banane\n\n");
	ft_putstr("  ./word_sort_advanced -i Alice bob CHARLIE\n");
	ft_putstr("  -> Alice bob CHARLIE\n\n");
	ft_putstr("  ./word_sort_advanced -n 10 2 9 100 1\n");
	ft_putstr("  -> 1 2 9 10 100\n\n");
	ft_putstr("  ./word_sort_advanced -u a b a c b\n");
	ft_putstr("  -> a b c\n");
}

/*
** ==================== PROGRAMME PRINCIPAL ====================
*/

int	main(int argc, char **argv)
{
	t_options	opts;
	int			word_start;
	int			word_count;
	int			i;

	ft_init_options(&opts);
	word_start = 1;
	i = 1;
	while (i < argc && ft_is_option(argv[i]))
	{
		if (!ft_parse_option(argv[i], &opts))
		{
			ft_putstr("Erreur: option invalide '");
			ft_putstr(argv[i]);
			ft_putstr("'\n");
			return (1);
		}
		word_start++;
		i++;
	}
	word_count = argc - word_start;
	if (word_count == 0)
	{
		ft_print_usage();
		return (0);
	}
	ft_quicksort(argv + word_start, 0, word_count - 1, &opts);
	if (opts.unique)
		ft_print_words_unique(argv + word_start, word_count, &opts);
	else
		ft_print_words(argv + word_start, word_count);
	return (0);
}
