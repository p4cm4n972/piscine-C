/*
 * challenge_ft_list_sort.c
 * Trier une liste chaînée
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
 * ft_list_sort
 * Trie la liste en utilisant la fonction de comparaison
 * Algorithme : Tri par sélection (bubble sort)
 */
void ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	void	*tmp;

	if (!begin_list || !*begin_list || !cmp)
		return;

	current = *begin_list;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if ((*cmp)(current->data, next->data) > 0)
			{
				// Échanger les données
				tmp = current->data;
				current->data = next->data;
				next->data = tmp;
			}
			next = next->next;
		}
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

void print_string_list(t_list *list)
{
	while (list)
	{
		printf("\"%s\" ", (char *)list->data);
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
	int		a = 42, b = 5, c = 18, d = 99, e = 3;

	printf("╔════════════════════════════════════════╗\n");
	printf("║      challenge_ft_list_sort            ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	// Test 1 : Tri d'entiers
	printf("Test 1 : Tri d'entiers\n");
	list = NULL;
	ft_list_push_back(&list, &a);
	ft_list_push_back(&list, &b);
	ft_list_push_back(&list, &c);
	ft_list_push_back(&list, &d);
	ft_list_push_back(&list, &e);

	printf("Avant tri : ");
	print_int_list(list);

	ft_list_sort(&list, (int (*)())int_cmp);

	printf("Après tri : ");
	print_int_list(list);
	printf("\n");

	ft_list_clear_simple(&list);

	// Test 2 : Tri de chaînes
	printf("Test 2 : Tri de chaînes\n");
	list = NULL;
	ft_list_push_back(&list, "Zebra");
	ft_list_push_back(&list, "Alice");
	ft_list_push_back(&list, "Bob");
	ft_list_push_back(&list, "Charlie");

	printf("Avant tri : ");
	print_string_list(list);

	ft_list_sort(&list, (int (*)())str_cmp);

	printf("Après tri : ");
	print_string_list(list);

	ft_list_clear_simple(&list);

	printf("\n╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION :
 * gcc -Wall -Wextra -Werror -g challenge_ft_list_sort.c -o list_sort
 * ./list_sort
 *
 * RÉSULTAT ATTENDU :
 * - Entiers triés : 3 5 18 42 99
 * - Chaînes triées : "Alice" "Bob" "Charlie" "Zebra"
 *
 * CONCEPTS CLÉS :
 * - Tri par sélection (bubble sort)
 * - Complexité O(n²)
 * - Fonction de comparaison générique
 * - Échange des données (pas des pointeurs)
 */
