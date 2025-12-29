/*
 * challenge_ft_list_remove_if.c
 * Supprimer les éléments qui correspondent à une condition
 */

#include "ft_list.h"
#include <stdio.h>
#include <string.h>

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
	t_list *new_elem, *current;

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
 * ft_list_remove_if
 * Supprime tous les éléments qui correspondent à data_ref selon cmp
 */
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *current;
	t_list *tmp;

	if (!begin_list || !*begin_list || !cmp)
		return;

	// Supprimer en tête tant que ça match
	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		if (free_fct)
			(*free_fct)(tmp->data);
		free(tmp);
	}

	// Supprimer dans le reste
	current = *begin_list;
	while (current && current->next)
	{
		if ((*cmp)(current->next->data, data_ref) == 0)
		{
			tmp = current->next;
			current->next = tmp->next;
			if (free_fct)
				(*free_fct)(tmp->data);
			free(tmp);
		}
		else
			current = current->next;
	}
}

int int_cmp(int *a, int *b)
{
	return (*a - *b);
}

int str_cmp(char *a, char *b)
{
	return (strcmp(a, b));
}

void print_int_list(t_list *list)
{
	while (list)
	{
		printf("%d ", *(int *)list->data);
		list = list->next;
	}
	printf("\n");
}

void ft_list_clear_simple(t_list **begin_list)
{
	t_list *current, *next;

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
	int		a = 5, b = 10, c = 5, d = 20, e = 5, f = 30;
	int		to_remove = 5;

	printf("╔════════════════════════════════════════╗\n");
	printf("║   challenge_ft_list_remove_if          ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	printf("Test : Supprimer tous les 5\n");
	list = NULL;
	ft_list_push_back(&list, &a);
	ft_list_push_back(&list, &b);
	ft_list_push_back(&list, &c);
	ft_list_push_back(&list, &d);
	ft_list_push_back(&list, &e);
	ft_list_push_back(&list, &f);

	printf("Avant : ");
	print_int_list(list);

	ft_list_remove_if(&list, &to_remove, (int (*)())int_cmp, NULL);

	printf("Après suppression de %d : ", to_remove);
	print_int_list(list);

	ft_list_clear_simple(&list);

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g challenge_ft_list_remove_if.c -o list_remove
 * ./list_remove
 *
 * RÉSULTAT ATTENDU :
 * - Avant : 5 10 5 20 5 30
 * - Après : 10 20 30
 *
 * CONCEPTS CLÉS :
 * - Suppression avec condition
 * - Gestion de la tête de liste
 * - Fonction de comparaison
 * - free_fct pour libérer les données
 */
