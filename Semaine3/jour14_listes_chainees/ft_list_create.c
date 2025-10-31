/*
** EXERCICE : ft_create_elem
**
** Crée un nouveau maillon de liste chaînée.
**
** Prototype :
** t_list *ft_create_elem(void *data);
**
** Comportement :
** - Alloue un nouveau maillon (t_list)
** - Initialise data avec le paramètre
** - Initialise next à NULL
** - Retourne le pointeur vers le nouveau maillon
** - Retourne NULL si malloc échoue
**
** Complexité : O(1)
*/

#include "ft_list.h"
#include <stdio.h>
#include <string.h>

t_list	*ft_create_elem(void *data)
{
	// TODO: Implémente ft_create_elem
	// 1. Allouer : t_list *elem = malloc(sizeof(t_list))
	// 2. Vérifier : if (!elem) return NULL
	// 3. Initialiser :
	//    elem->data = data
	//    elem->next = NULL
	// 4. Retourner elem

	return (NULL);
}

void	print_string(void *data)
{
	printf("%s", (char *)data);
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

int	main(void)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	printf("=== Test 1 : Créer un maillon ===\n");
	elem1 = ft_create_elem("Hello");
	if (elem1)
	{
		printf("Maillon créé\n");
		printf("  data = %s\n", (char *)elem1->data);
		printf("  next = %p (devrait être NULL)\n", (void *)elem1->next);
		free(elem1);
	}
	else
		printf("Erreur : malloc a échoué\n");

	printf("\n=== Test 2 : Créer plusieurs maillons ===\n");
	elem1 = ft_create_elem("First");
	elem2 = ft_create_elem("Second");
	elem3 = ft_create_elem("Third");

	if (elem1 && elem2 && elem3)
	{
		// Chaîner manuellement pour tester
		elem1->next = elem2;
		elem2->next = elem3;

		printf("Liste chaînée : ");
		print_list(elem1);

		// Libérer
		free(elem3);
		free(elem2);
		free(elem1);
	}

	printf("\n=== Test 3 : Maillon avec NULL ===\n");
	elem1 = ft_create_elem(NULL);
	if (elem1)
	{
		printf("Maillon créé avec data = NULL\n");
		printf("  data = %p\n", elem1->data);
		printf("  next = %p\n", (void *)elem1->next);
		free(elem1);
	}

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 : Créer un maillon ===
** Maillon créé
**   data = Hello
**   next = (nil) (devrait être NULL)
**
** === Test 2 : Créer plusieurs maillons ===
** Liste chaînée : ["First" -> "Second" -> "Third"]
**
** === Test 3 : Maillon avec NULL ===
** Maillon créé avec data = NULL
**   data = (nil)
**   next = (nil)
**
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror -g ft_list_create.c -o ft_list_create
** valgrind --leak-check=full ./ft_list_create
**
** 📚 THÉORIE :
** Un maillon (node) est l'élément de base d'une liste chaînée.
**
** Structure t_list :
** +--------+--------+
** | data   | next   |
** +--------+--------+
**    |         |
**    v         v
**  void*    t_list*
**
** Pourquoi void * ?
** - Permet de stocker n'importe quel type de données
** - Plus flexible qu'un int ou char *
** - Nécessite un cast lors de l'utilisation
**
** Liste chaînée vs Tableau :
**
** Tableau :
** - Taille fixe
** - Accès O(1) par index
** - Insertion/suppression O(n)
**
** Liste chaînée :
** - Taille dynamique
** - Accès O(n) par index
** - Insertion/suppression O(1) en tête
**
** ⚠️ IMPORTANT :
** - Toujours initialiser next à NULL
** - Un maillon isolé a next = NULL
** - Vérifier le retour de malloc
**
** BONUS :
** - Chronomètre : < 10 min
** - ft_create_elem_int(int n) : pour des entiers
** - ft_create_elem_copy(void *data, size_t size) : copie les données
*/
