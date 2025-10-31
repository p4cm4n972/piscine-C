/*
** CHALLENGE : ft_list_reverse
**
** Inverse l'ordre des maillons d'une liste chaînée.
**
** Prototype :
** void ft_list_reverse(t_list **begin_list);
**
** Comportement :
** - Inverse la liste en place (sans allouer de nouveaux maillons)
** - Modifie les pointeurs next pour inverser l'ordre
** - Si la liste est vide ou a un seul élément, ne fait rien
**
** Exemple :
** Avant : [A -> B -> C -> D -> NULL]
** Après : [D -> C -> B -> A -> NULL]
**
** Complexité : O(n) où n = nombre de maillons
*/

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new;
	t_list	*current;

	new = ft_create_elem(data);
	if (!new)
		return;
	if (!*begin_list)
	{
		*begin_list = new;
		return;
	}
	current = *begin_list;
	while (current->next)
		current = current->next;
	current->next = new;
}

void	ft_list_reverse(t_list **begin_list)
{
	// TODO: Implémente l'inversion de liste
	// Algorithme avec 3 pointeurs :
	// 1. Initialiser : prev = NULL, current = *begin_list, next = NULL
	// 2. Tant que current != NULL :
	//    a) Sauvegarder le suivant : next = current->next
	//    b) Inverser le lien : current->next = prev
	//    c) Avancer : prev = current
	//    d) Avancer : current = next
	// 3. Mettre à jour la tête : *begin_list = prev
	//
	// Visualisation :
	// NULL <- A <- B <- C <- D
	//         ^              ^
	//        prev         current
}

void	print_list(t_list *list)
{
	printf("[");
	while (list)
	{
		printf("\"%s\"", (char *)list->data);
		if (list->next)
			printf(" -> ");
		list = list->next;
	}
	printf("]\n");
}

void	ft_list_clear(t_list **begin_list)
{
	t_list	*current;
	t_list	*next;

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

int	main(void)
{
	t_list	*list;

	printf("=== Test 1 : Liste simple ===\n");
	list = NULL;
	ft_list_push_back(&list, "A");
	ft_list_push_back(&list, "B");
	ft_list_push_back(&list, "C");
	ft_list_push_back(&list, "D");

	printf("Avant : ");
	print_list(list);

	ft_list_reverse(&list);

	printf("Après : ");
	print_list(list);
	printf("Attendu : [\"D\" -> \"C\" -> \"B\" -> \"A\"]\n");

	ft_list_clear(&list);

	printf("\n=== Test 2 : Liste avec 2 éléments ===\n");
	list = NULL;
	ft_list_push_back(&list, "First");
	ft_list_push_back(&list, "Second");

	printf("Avant : ");
	print_list(list);

	ft_list_reverse(&list);

	printf("Après : ");
	print_list(list);
	printf("Attendu : [\"Second\" -> \"First\"]\n");

	ft_list_clear(&list);

	printf("\n=== Test 3 : Liste avec 1 élément ===\n");
	list = NULL;
	ft_list_push_back(&list, "Alone");

	printf("Avant : ");
	print_list(list);

	ft_list_reverse(&list);

	printf("Après : ");
	print_list(list);
	printf("Attendu : [\"Alone\"] (inchangé)\n");

	ft_list_clear(&list);

	printf("\n=== Test 4 : Liste vide ===\n");
	list = NULL;

	printf("Avant : ");
	print_list(list);

	ft_list_reverse(&list);

	printf("Après : ");
	print_list(list);
	printf("Attendu : [] (vide)\n");

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 : Liste simple ===
** Avant : ["A" -> "B" -> "C" -> "D"]
** Après : ["D" -> "C" -> "B" -> "A"]
** Attendu : ["D" -> "C" -> "B" -> "A"]
**
** === Test 2 : Liste avec 2 éléments ===
** Avant : ["First" -> "Second"]
** Après : ["Second" -> "First"]
** Attendu : ["Second" -> "First"]
**
** === Test 3 : Liste avec 1 élément ===
** Avant : ["Alone"]
** Après : ["Alone"]
** Attendu : ["Alone"] (inchangé)
**
** === Test 4 : Liste vide ===
** Avant : []
** Après : []
** Attendu : [] (vide)
**
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror -g challenge_ft_list_reverse.c -o reverse
** valgrind --leak-check=full ./reverse
**
** 📚 THÉORIE :
** L'inversion de liste est un algorithme classique d'entretien !
**
** Approches possibles :
** 1. Itérative (O(n) temps, O(1) espace) - recommandée
** 2. Récursive (O(n) temps, O(n) espace stack)
** 3. Avec pile auxiliaire (O(n) temps, O(n) espace)
**
** Algorithme itératif avec 3 pointeurs :
**
** État initial :
** NULL    A -> B -> C -> D -> NULL
**  ^      ^
** prev  current
**
** Étape 1 : Sauvegarder next et inverser
** NULL <- A    B -> C -> D -> NULL
**         ^    ^
**        prev current
**
** Étape 2 :
** NULL <- A <- B    C -> D -> NULL
**              ^    ^
**            prev current
**
** Étape 3 :
** NULL <- A <- B <- C    D -> NULL
**                   ^    ^
**                 prev current
**
** Étape finale :
** NULL <- A <- B <- C <- D    NULL
**                        ^    ^
**                      prev current
**
** ⚠️ PIÈGES COURANTS :
** 1. Oublier de sauvegarder next avant d'inverser
** 2. Ne pas mettre à jour *begin_list à la fin
** 3. Gérer le cas liste vide ou 1 élément
**
** BONUS :
** - Chronomètre : < 30 min
** - Version récursive
** - ft_list_reverse_between(start, end) : inverse une partie
** - Vérifier que la liste est bien inversée (pas de cycle)
*/
