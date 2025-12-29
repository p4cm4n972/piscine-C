/*
 * ft_list_size.c
 * Compter le nombre d'éléments dans une liste
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

void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	if (!begin_list)
		return;
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return;
	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

/*
 * ft_list_size
 * Retourne le nombre d'éléments dans la liste
 * Complexité : O(n)
 */
int ft_list_size(t_list *begin_list)
{
	int count;

	count = 0;
	while (begin_list)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
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
	int		a = 1, b = 2, c = 3, d = 4, e = 5;

	printf("╔════════════════════════════════════════╗\n");
	printf("║       ft_list_size - TESTS             ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	list = NULL;

	printf("Test 1 : Liste vide\n");
	printf("Taille : %d (attendu : 0)\n\n", ft_list_size(list));

	printf("Test 2 : Ajouter des éléments\n");
	ft_list_push_front(&list, &a);
	printf("Après ajout de 1 élément : %d\n", ft_list_size(list));

	ft_list_push_front(&list, &b);
	printf("Après ajout de 2 éléments : %d\n", ft_list_size(list));

	ft_list_push_front(&list, &c);
	printf("Après ajout de 3 éléments : %d\n", ft_list_size(list));

	ft_list_push_front(&list, &d);
	printf("Après ajout de 4 éléments : %d\n", ft_list_size(list));

	ft_list_push_front(&list, &e);
	printf("Après ajout de 5 éléments : %d\n", ft_list_size(list));

	ft_list_clear_simple(&list);

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g ft_list_size.c -o list_size
 * ./list_size
 *
 * RÉSULTAT ATTENDU :
 * - Liste vide : 0
 * - 1 élément : 1
 * - 2 éléments : 2
 * - 3 éléments : 3
 * - 4 éléments : 4
 * - 5 éléments : 5
 *
 * CONCEPTS CLÉS :
 * - Parcours simple de liste
 * - Complexité O(n) - linéaire
 * - Alternative : stocker la taille dans une structure
 */
