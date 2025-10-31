#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

/*
** Structure de liste chaînée simple
**
** data : pointeur vers les données (void * pour être générique)
** next : pointeur vers le maillon suivant (NULL si dernier)
*/
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

/*
** Fonctions de base pour les listes chaînées
*/

// Créer un nouveau maillon
t_list	*ft_create_elem(void *data);

// Ajouter en tête de liste
void	ft_list_push_front(t_list **begin_list, void *data);

// Ajouter en queue de liste
void	ft_list_push_back(t_list **begin_list, void *data);

// Compter le nombre d'éléments
int		ft_list_size(t_list *begin_list);

// Obtenir le dernier élément
t_list	*ft_list_last(t_list *begin_list);

// Obtenir l'élément à l'index n
t_list	*ft_list_at(t_list *begin_list, unsigned int nbr);

// Afficher la liste (pour debug)
void	ft_list_print(t_list *begin_list, void (*print_data)(void *));

// Libérer toute la liste
void	ft_list_clear(t_list **begin_list, void (*free_fct)(void *));

/*
** Fonctions avancées (challenges)
*/

// Inverser la liste
void	ft_list_reverse(t_list **begin_list);

// Supprimer un élément selon une condition
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));

// Trier la liste
void	ft_list_sort(t_list **begin_list, int (*cmp)());

// Fusionner deux listes triées
void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);

#endif
