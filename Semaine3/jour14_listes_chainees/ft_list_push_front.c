/*
 * ft_list_push_front.c
 * Ajouter un élément en tête de liste
 *
 * Objectif : Comprendre l'insertion en tête
 */

#include "ft_list.h"
#include <stdio.h>
#include <string.h>

/*
 * ft_create_elem
 * Crée un nouveau maillon avec les données passées
 */
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
 * ft_list_push_front
 *
 * Ajoute un nouvel élément en TÊTE de la liste
 *
 * Paramètres :
 *   begin_list : Pointeur vers le premier élément (pointeur sur pointeur)
 *   data       : Données à insérer
 *
 * Algorithme :
 *   1. Créer un nouveau maillon
 *   2. Le nouveau maillon pointe vers l'ancien premier
 *   3. Mettre à jour begin_list pour pointer vers le nouveau
 *
 * Complexité : O(1) - constant
 */
void ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_elem;

	if (!begin_list)
		return;

	// Créer le nouveau maillon
	new_elem = ft_create_elem(data);
	if (!new_elem)
		return;

	// Le nouveau maillon pointe vers l'ancien premier
	new_elem->next = *begin_list;

	// Le nouveau devient le premier
	*begin_list = new_elem;
}

/*
 * VISUALISATION
 *
 * État initial :
 *   begin_list -> [A] -> [B] -> NULL
 *
 * Ajouter 'X' en tête :
 *
 * Étape 1 : Créer le nouveau maillon
 *   new_elem -> [X] -> NULL
 *
 * Étape 2 : new_elem->next = *begin_list
 *   new_elem -> [X] -> [A] -> [B] -> NULL
 *
 * Étape 3 : *begin_list = new_elem
 *   begin_list -> [X] -> [A] -> [B] -> NULL
 */

/*
 * Fonction helper pour afficher la liste
 */
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

/*
 * Libérer la liste
 */
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

/*
 * TESTS
 */
int main(void)
{
	t_list	*list;
	int		a = 10;
	int		b = 20;
	int		c = 30;
	int		d = 40;

	printf("╔════════════════════════════════════════╗\n");
	printf("║      ft_list_push_front - TESTS       ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	// Test 1 : Liste vide
	printf("Test 1 : Ajouter à une liste vide\n");
	list = NULL;
	ft_list_push_front(&list, &a);
	printf("Après push_front(10) : ");
	print_int_list(list);
	printf("\n");

	// Test 2 : Ajouter plusieurs éléments
	printf("Test 2 : Ajouter plusieurs éléments\n");
	ft_list_push_front(&list, &b);
	printf("Après push_front(20) : ");
	print_int_list(list);

	ft_list_push_front(&list, &c);
	printf("Après push_front(30) : ");
	print_int_list(list);

	ft_list_push_front(&list, &d);
	printf("Après push_front(40) : ");
	print_int_list(list);
	printf("Note : L'ordre est inversé (40, 30, 20, 10)\n\n");

	// Libérer
	ft_list_clear_simple(&list);

	// Test 3 : Liste de chaînes
	printf("Test 3 : Liste de chaînes\n");
	list = NULL;
	ft_list_push_front(&list, "Alice");
	ft_list_push_front(&list, "Bob");
	ft_list_push_front(&list, "Charlie");
	printf("Liste de noms : ");
	print_string_list(list);
	printf("\n");

	ft_list_clear_simple(&list);

	printf("╔════════════════════════════════════════╗\n");
	printf("║           TESTS RÉUSSIS                ║\n");
	printf("╚════════════════════════════════════════╝\n");

	return (0);
}

/*
 * COMPILATION ET TESTS
 *
 * gcc -Wall -Wextra -Werror -g ft_list_push_front.c -o push_front
 * ./push_front
 *
 * # Vérifier avec valgrind
 * valgrind --leak-check=full ./push_front
 *
 * RÉSULTAT ATTENDU :
 * - Après push_front(10) : 10
 * - Après push_front(20) : 20 10
 * - Après push_front(30) : 30 20 10
 * - Après push_front(40) : 40 30 20 10
 * - Liste de noms : "Charlie" "Bob" "Alice"
 *
 * CONCEPTS CLÉS :
 *
 * 1. POINTEUR SUR POINTEUR (**begin_list) :
 *    - Pour modifier la tête de liste, on doit passer l'adresse du pointeur
 *    - *begin_list donne le premier maillon
 *    - **begin_list donne la structure elle-même
 *
 * 2. INSERTION EN TÊTE :
 *    - Très rapide : O(1)
 *    - Pas besoin de parcourir la liste
 *    - 3 opérations seulement
 *
 * 3. ORDRE INVERSÉ :
 *    - Si on push_front(1), push_front(2), push_front(3)
 *    - On obtient : 3 -> 2 -> 1
 *    - Le dernier ajouté est en première position
 *
 * 4. COMPARAISON AVEC push_back :
 *    - push_front : O(1) - rapide
 *    - push_back  : O(n) - doit aller au bout
 *
 * 5. CAS PARTICULIERS :
 *    - Liste vide : new_elem->next = NULL, *begin_list = new_elem
 *    - begin_list == NULL : protection nécessaire
 */
