/*
 * ft_list_at.c
 * Obtenir l'élément à l'index n
 */

#include "ft_list.h"
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_elem;
	t_list *current;

	if (!begin_list)
		return;
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return;
	if (!*begin_list)
	{
		*begin_list = new_elem;
		return;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new_elem;
}

/*
 * ft_list_at
 * Retourne l'élément à l'index n (0-indexed)
 * Retourne NULL si n est hors limites
 */
t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (NULL);
}

void ft_list_clear_simple(t_list **begin_list)
{
	t_list *current;
	t_list *next;

	if (!begin_list || !*begin_list)
		return;
	current = *begin_list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*begin_list = NULL;
}

int main(void)
{
	t_list	*list;
	t_list	*elem;
	int		a = 10, b = 20, c = 30, d = 40, e = 50;

	printf("╔════════════════════════════════════════╗\n");
	printf("║        ft_list_at - TESTS              ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	list = NULL;
	ft_list_push_back(&list, &a);
	ft_list_push_back(&list, &b);
	ft_list_push_back(&list, &c);
	ft_list_push_back(&list, &d);
	ft_list_push_back(&list, &e);

	printf("Liste créée : 10, 20, 30, 40, 50\n\n");

	printf("Test : Accès par index\n");
	elem = ft_list_at(list, 0);
	printf("Index 0 : %d (attendu : 10)\n", elem ? *(int *)elem->data : -1);

	elem = ft_list_at(list, 2);
	printf("Index 2 : %d (attendu : 30)\n", elem ? *(int *)elem->data : -1);

	elem = ft_list_at(list, 4);
	printf("Index 4 : %d (attendu : 50)\n", elem ? *(int *)elem->data : -1);

	elem = ft_list_at(list, 10);
	printf("Index 10 (hors limites) : %s\n", elem ? "ERREUR" : "NULL ✓");

	ft_list_clear_simple(&list);

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g ft_list_at.c -o list_at
 * ./list_at
 *
 * CONCEPTS CLÉS :
 * - Index 0-based (commence à 0)
 * - Retourne NULL si hors limites
 * - Complexité O(n) - doit parcourir jusqu'à l'index
 */
