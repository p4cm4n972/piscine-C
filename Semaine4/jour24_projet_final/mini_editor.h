/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_EDITOR_H
# define MINI_EDITOR_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

/*
** PROJET FINAL : Mini Éditeur de Texte
**
** Un éditeur de texte en ligne de commande combinant tous les concepts :
** - Gestion de fichiers (open, read, write, close)
** - Allocation dynamique (malloc, realloc, free)
** - Listes chaînées (pour les lignes)
** - Manipulation de chaînes
** - Parsing de commandes
*/

# define MAX_LINE_LEN 4096
# define BUFFER_SIZE 4096

/*
** Structure pour une ligne de texte (liste chaînée)
*/
typedef struct s_line
{
	char			*content;
	int				len;
	struct s_line	*next;
	struct s_line	*prev;
}	t_line;

/*
** Structure pour le buffer de l'éditeur
*/
typedef struct s_editor
{
	t_line	*first;       /* Première ligne */
	t_line	*last;        /* Dernière ligne */
	t_line	*current;     /* Ligne courante */
	int		line_count;   /* Nombre de lignes */
	int		current_num;  /* Numéro de ligne courante */
	char	*filename;    /* Nom du fichier */
	int		modified;     /* Flag de modification */
}	t_editor;

/* ==================== Gestion des lignes ==================== */
t_line	*line_new(const char *content);
void	line_free(t_line *line);
void	line_insert_after(t_editor *ed, t_line *after, t_line *new);
void	line_delete(t_editor *ed, t_line *line);

/* ==================== Gestion de l'éditeur ==================== */
t_editor	*editor_new(void);
void		editor_free(t_editor *ed);
int			editor_load(t_editor *ed, const char *filename);
int			editor_save(t_editor *ed, const char *filename);

/* ==================== Commandes de l'éditeur ==================== */
void	cmd_print(t_editor *ed, int start, int end);
void	cmd_print_all(t_editor *ed);
void	cmd_goto(t_editor *ed, int line_num);
void	cmd_insert(t_editor *ed, const char *text);
void	cmd_append(t_editor *ed, const char *text);
void	cmd_delete(t_editor *ed, int line_num);
void	cmd_replace(t_editor *ed, int line_num, const char *text);
void	cmd_search(t_editor *ed, const char *pattern);
void	cmd_help(void);

/* ==================== Utilitaires ==================== */
char	*ft_strdup_ed(const char *s);
int		ft_strlen_ed(const char *s);
char	*ft_strchr_ed(const char *s, int c);
int		ft_atoi_ed(const char *s);
void	ft_putstr_ed(const char *s);

#endif
