/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_editor.h"

/* ==================== UTILITAIRES ==================== */

int	ft_strlen_ed(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup_ed(const char *s)
{
	char	*dup;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = ft_strlen_ed(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strchr_ed(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int	ft_atoi_ed(const char *s)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result * sign);
}

void	ft_putstr_ed(const char *s)
{
	if (s)
		write(1, s, ft_strlen_ed(s));
}

/* ==================== GESTION DES LIGNES ==================== */

t_line	*line_new(const char *content)
{
	t_line	*line;

	line = malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	if (content)
		line->content = ft_strdup_ed(content);
	else
		line->content = ft_strdup_ed("");
	line->len = ft_strlen_ed(line->content);
	line->next = NULL;
	line->prev = NULL;
	return (line);
}

void	line_free(t_line *line)
{
	if (!line)
		return ;
	if (line->content)
		free(line->content);
	free(line);
}

void	line_insert_after(t_editor *ed, t_line *after, t_line *new)
{
	if (!ed || !new)
		return ;
	if (!after)
	{
		new->next = ed->first;
		if (ed->first)
			ed->first->prev = new;
		ed->first = new;
		if (!ed->last)
			ed->last = new;
	}
	else
	{
		new->next = after->next;
		new->prev = after;
		if (after->next)
			after->next->prev = new;
		after->next = new;
		if (after == ed->last)
			ed->last = new;
	}
	ed->line_count++;
	ed->modified = 1;
}

void	line_delete(t_editor *ed, t_line *line)
{
	if (!ed || !line)
		return ;
	if (line->prev)
		line->prev->next = line->next;
	else
		ed->first = line->next;
	if (line->next)
		line->next->prev = line->prev;
	else
		ed->last = line->prev;
	if (ed->current == line)
	{
		if (line->next)
			ed->current = line->next;
		else
			ed->current = line->prev;
	}
	line_free(line);
	ed->line_count--;
	ed->modified = 1;
}

/* ==================== GESTION DE L'ÉDITEUR ==================== */

t_editor	*editor_new(void)
{
	t_editor	*ed;

	ed = malloc(sizeof(t_editor));
	if (!ed)
		return (NULL);
	ed->first = NULL;
	ed->last = NULL;
	ed->current = NULL;
	ed->line_count = 0;
	ed->current_num = 0;
	ed->filename = NULL;
	ed->modified = 0;
	return (ed);
}

void	editor_free(t_editor *ed)
{
	t_line	*line;
	t_line	*next;

	if (!ed)
		return ;
	line = ed->first;
	while (line)
	{
		next = line->next;
		line_free(line);
		line = next;
	}
	if (ed->filename)
		free(ed->filename);
	free(ed);
}

static void	remove_newline(char *s)
{
	int	len;

	len = ft_strlen_ed(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

int	editor_load(t_editor *ed, const char *filename)
{
	FILE	*fp;
	char	buffer[MAX_LINE_LEN];
	t_line	*new_line;

	if (!ed || !filename)
		return (-1);
	fp = fopen(filename, "r");
	if (!fp)
		return (-1);
	while (fgets(buffer, MAX_LINE_LEN, fp))
	{
		remove_newline(buffer);
		new_line = line_new(buffer);
		if (new_line)
			line_insert_after(ed, ed->last, new_line);
	}
	fclose(fp);
	if (ed->filename)
		free(ed->filename);
	ed->filename = ft_strdup_ed(filename);
	ed->current = ed->first;
	ed->current_num = 1;
	ed->modified = 0;
	return (0);
}

int	editor_save(t_editor *ed, const char *filename)
{
	FILE	*fp;
	t_line	*line;

	if (!ed)
		return (-1);
	if (!filename)
		filename = ed->filename;
	if (!filename)
		return (-1);
	fp = fopen(filename, "w");
	if (!fp)
		return (-1);
	line = ed->first;
	while (line)
	{
		fprintf(fp, "%s\n", line->content);
		line = line->next;
	}
	fclose(fp);
	if (ed->filename != filename)
	{
		if (ed->filename)
			free(ed->filename);
		ed->filename = ft_strdup_ed(filename);
	}
	ed->modified = 0;
	return (0);
}

/* ==================== COMMANDES ==================== */

void	cmd_print(t_editor *ed, int start, int end)
{
	t_line	*line;
	int		num;

	if (!ed || !ed->first)
	{
		ft_putstr_ed("(fichier vide)\n");
		return ;
	}
	if (start < 1)
		start = 1;
	if (end > ed->line_count || end < 1)
		end = ed->line_count;
	line = ed->first;
	num = 1;
	while (line && num <= end)
	{
		if (num >= start)
		{
			printf("%4d%c %s\n", num, (line == ed->current) ? '>' : ':', line->content);
		}
		line = line->next;
		num++;
	}
}

void	cmd_print_all(t_editor *ed)
{
	cmd_print(ed, 1, ed->line_count);
}

void	cmd_goto(t_editor *ed, int line_num)
{
	t_line	*line;
	int		num;

	if (!ed || line_num < 1 || line_num > ed->line_count)
	{
		ft_putstr_ed("Numéro de ligne invalide\n");
		return ;
	}
	line = ed->first;
	num = 1;
	while (line && num < line_num)
	{
		line = line->next;
		num++;
	}
	if (line)
	{
		ed->current = line;
		ed->current_num = num;
		printf("Ligne %d: %s\n", num, line->content);
	}
}

void	cmd_insert(t_editor *ed, const char *text)
{
	t_line	*new_line;
	t_line	*prev;

	if (!ed)
		return ;
	new_line = line_new(text);
	if (!new_line)
		return ;
	if (ed->current && ed->current->prev)
		prev = ed->current->prev;
	else
		prev = NULL;
	line_insert_after(ed, prev, new_line);
	ed->current = new_line;
	ft_putstr_ed("Ligne insérée\n");
}

void	cmd_append(t_editor *ed, const char *text)
{
	t_line	*new_line;

	if (!ed)
		return ;
	new_line = line_new(text);
	if (!new_line)
		return ;
	line_insert_after(ed, ed->current, new_line);
	ed->current = new_line;
	ft_putstr_ed("Ligne ajoutée\n");
}

void	cmd_delete(t_editor *ed, int line_num)
{
	t_line	*line;
	int		num;

	if (!ed || line_num < 1 || line_num > ed->line_count)
	{
		ft_putstr_ed("Numéro de ligne invalide\n");
		return ;
	}
	line = ed->first;
	num = 1;
	while (line && num < line_num)
	{
		line = line->next;
		num++;
	}
	if (line)
	{
		line_delete(ed, line);
		printf("Ligne %d supprimée\n", line_num);
	}
}

void	cmd_replace(t_editor *ed, int line_num, const char *text)
{
	t_line	*line;
	int		num;

	if (!ed || line_num < 1 || line_num > ed->line_count)
	{
		ft_putstr_ed("Numéro de ligne invalide\n");
		return ;
	}
	line = ed->first;
	num = 1;
	while (line && num < line_num)
	{
		line = line->next;
		num++;
	}
	if (line)
	{
		free(line->content);
		line->content = ft_strdup_ed(text);
		line->len = ft_strlen_ed(line->content);
		ed->modified = 1;
		printf("Ligne %d modifiée\n", line_num);
	}
}

void	cmd_search(t_editor *ed, const char *pattern)
{
	t_line	*line;
	int		num;
	int		found;

	if (!ed || !pattern || !*pattern)
		return ;
	line = ed->first;
	num = 1;
	found = 0;
	printf("Recherche de \"%s\":\n", pattern);
	while (line)
	{
		if (strstr(line->content, pattern))
		{
			printf("  %4d: %s\n", num, line->content);
			found++;
		}
		line = line->next;
		num++;
	}
	printf("%d occurrence(s) trouvée(s)\n", found);
}

void	cmd_help(void)
{
	ft_putstr_ed("\n╔══════════════════════════════════════════╗\n");
	ft_putstr_ed("║           MINI EDITOR - AIDE             ║\n");
	ft_putstr_ed("╚══════════════════════════════════════════╝\n\n");
	ft_putstr_ed("Commandes disponibles:\n\n");
	ft_putstr_ed("  p [n] [m]  - Afficher lignes n à m (ou toutes)\n");
	ft_putstr_ed("  g <n>      - Aller à la ligne n\n");
	ft_putstr_ed("  i <texte>  - Insérer avant la ligne courante\n");
	ft_putstr_ed("  a <texte>  - Ajouter après la ligne courante\n");
	ft_putstr_ed("  d <n>      - Supprimer la ligne n\n");
	ft_putstr_ed("  r <n> <t>  - Remplacer la ligne n par texte t\n");
	ft_putstr_ed("  s <motif>  - Rechercher un motif\n");
	ft_putstr_ed("  w [nom]    - Sauvegarder (optionnel: nouveau nom)\n");
	ft_putstr_ed("  q          - Quitter\n");
	ft_putstr_ed("  h          - Afficher cette aide\n\n");
}
