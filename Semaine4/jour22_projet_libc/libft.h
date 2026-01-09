/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** ==========================================================================
** LIBFT - Bibliothèque C standard réimplémentée
** ==========================================================================
**
** Cette bibliothèque réimplémente les fonctions essentielles de la libc
** avec le préfixe ft_ (for-two / fourty-two).
**
** Partie 1 : Fonctions libc
** Partie 2 : Fonctions supplémentaires
** Bonus    : Listes chaînées
**
** Compilation : make / make bonus / make re
** ==========================================================================
*/

/* ======================== PARTIE 1 : LIBC ======================== */

/* --- Fonctions de test de caractères (ctype.h) --- */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* --- Fonctions de manipulation de chaînes (string.h) --- */
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);

/* --- Fonctions de manipulation mémoire (string.h) --- */
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* --- Fonctions de conversion (stdlib.h) --- */
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

/* ======================== PARTIE 2 : ADDITIONAL ======================== */

/* --- Allocation et manipulation de chaînes --- */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);

/* --- Application de fonctions sur chaînes --- */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* --- Fonctions d'écriture sur file descriptor --- */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* ======================== BONUS : LISTES CHAÎNÉES ======================== */

/*
** Structure de liste chaînée
** - content: pointeur vers les données (void* pour généricité)
** - next: pointeur vers le maillon suivant
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* --- Création et ajout --- */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);

/* --- Accès et taille --- */
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

/* --- Suppression --- */
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));

/* --- Itération et transformation --- */
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
