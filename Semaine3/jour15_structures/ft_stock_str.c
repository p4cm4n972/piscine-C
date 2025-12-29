/*
 * ft_stock_str.c
 * Structure pour stocker des chaînes avec leur taille
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_stock_str
{
	char	*str;
	char	*copy;
	int		size;
}	t_stock_str;

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *src)
{
	char *dup;
	int i;

	dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *arr;
	int i;

	arr = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!arr)
		return (NULL);

	i = 0;
	while (i < ac)
	{
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		arr[i].size = ft_strlen(av[i]);
		i++;
	}
	arr[i].str = NULL;
	return (arr);
}

void ft_show_tab(t_stock_str *arr)
{
	int i = 0;

	while (arr[i].str)
	{
		printf("[%d] str=\"%s\", copy=\"%s\", size=%d\n",
				i, arr[i].str, arr[i].copy, arr[i].size);
		i++;
	}
}

void ft_free_tab(t_stock_str *arr)
{
	int i = 0;

	while (arr[i].str)
	{
		free(arr[i].copy);
		i++;
	}
	free(arr);
}

int main(int ac, char **av)
{
	t_stock_str *tab;

	printf("╔════════════════════════════════════════╗\n");
	printf("║       ft_stock_str - Structure         ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	if (ac < 2)
	{
		printf("Usage: %s <arg1> <arg2> ...\n", av[0]);
		return (1);
	}

	tab = ft_strs_to_tab(ac - 1, av + 1);
	if (!tab)
		return (1);

	ft_show_tab(tab);
	ft_free_tab(tab);

	printf("\n✓ Mémoire libérée\n");
	return (0);
}

/* COMPILATION : gcc -Wall -Wextra -Werror -g ft_stock_str.c -o stock_str */
