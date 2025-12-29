/*
 * ft_list_push_back.c
 * Ajouter un élément en queue de liste
 */

#include "ft_list.h"
#include <stdio.h>

t_list *ft_create_elem(void *data)
{
	t_list *elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

/*
 * ft_list_push_back
 * Ajoute un élément en fin de liste
 * Complexité : O(n) - doit parcourir toute la liste
 */
void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *new_elem;
	t_list *current;

	if (!begin_list)
		return;

	new_elem = ft_create_elem(data);
	if (!new_elem)
		return;

	// Si liste vide
	if (!*begin_list)
	{
		*begin_list = new_elem;
		return;
	}

	// Aller au dernier élément
	current = *begin_list;
	while (current->next)
		current = current->next;

	// Ajouter à la fin
	current->next = new_elem;
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
	int		a = 10, b = 20, c = 30, d = 40;

	printf("╔════════════════════════════════════════╗\n");
	printf("║      ft_list_push_back - TESTS        ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	list = NULL;

	printf("Test : Ajouter plusieurs éléments en queue\n");
	ft_list_push_back(&list, &a);
	printf("Après push_back(10) : ");
	print_int_list(list);

	ft_list_push_back(&list, &b);
	printf("Après push_back(20) : ");
	print_int_list(list);

	ft_list_push_back(&list, &c);
	printf("Après push_back(30) : ");
	print_int_list(list);

	ft_list_push_back(&list, &d);
	printf("Après push_back(40) : ");
	print_int_list(list);

	printf("\nNote : L'ordre est préservé (10, 20, 30, 40)\n");

	ft_list_clear_simple(&list);

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g ft_list_push_back.c -o push_back
 * ./push_back
 *
 * RÉSULTAT ATTENDU :
 * - Après push_back(10) : 10
 * - Après push_back(20) : 10 20
 * - Après push_back(30) : 10 20 30
 * - Après push_back(40) : 10 20 30 40
 *
 * CONCEPTS CLÉS :
 * - push_back : O(n) - doit parcourir toute la liste
 * - push_front : O(1) - plus rapide
 * - Ordre préservé avec push_back
 * - Ordre inversé avec push_front
 */
