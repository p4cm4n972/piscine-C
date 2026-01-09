/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_editor.h"

/*
** PROJET FINAL - JOUR 24 : Mini Éditeur de Texte
**
** Ce programme est un éditeur de texte en ligne de commande inspiré de ed(1).
** Il combine tous les concepts de la Piscine C :
**
** 1. Gestion de fichiers : open/read/write/close
** 2. Allocation dynamique : malloc/realloc/free
** 3. Listes chaînées doublement liées
** 4. Manipulation de chaînes
** 5. Parsing de commandes
** 6. Gestion d'erreurs
**
** Usage: ./mini_editor [fichier]
*/

static void	print_banner(void)
{
	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║         MINI EDITOR v1.0                 ║\n");
	printf("║         Projet Final - Piscine C         ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	printf("  Tapez 'h' pour l'aide\n\n");
}

static void	print_prompt(t_editor *ed)
{
	if (ed->filename)
		printf("[%s", ed->filename);
	else
		printf("[(nouveau)");
	if (ed->modified)
		printf("*");
	printf("] %d/%d > ", ed->current_num, ed->line_count);
}

static char	*get_arg(char *cmd)
{
	while (*cmd && *cmd != ' ')
		cmd++;
	while (*cmd == ' ')
		cmd++;
	return (cmd);
}

static int	parse_range(char *arg, int *start, int *end)
{
	*start = ft_atoi_ed(arg);
	while (*arg && *arg != ' ' && *arg != ',')
		arg++;
	if (*arg == ',' || *arg == ' ')
	{
		arg++;
		while (*arg == ' ')
			arg++;
		*end = ft_atoi_ed(arg);
	}
	else
		*end = *start;
	return (0);
}

static int	process_command(t_editor *ed, char *cmd)
{
	char	*arg;
	int		n1;
	int		n2;

	while (*cmd == ' ')
		cmd++;
	if (!*cmd)
		return (1);
	arg = get_arg(cmd);
	if (cmd[0] == 'q')
	{
		if (ed->modified)
		{
			printf("Fichier modifié. Utilisez 'w' pour sauvegarder ou 'q!' pour forcer.\n");
			if (cmd[1] == '!')
				return (0);
			return (1);
		}
		return (0);
	}
	else if (cmd[0] == 'h')
		cmd_help();
	else if (cmd[0] == 'p')
	{
		if (*arg)
		{
			parse_range(arg, &n1, &n2);
			cmd_print(ed, n1, n2);
		}
		else
			cmd_print_all(ed);
	}
	else if (cmd[0] == 'g')
		cmd_goto(ed, ft_atoi_ed(arg));
	else if (cmd[0] == 'i')
		cmd_insert(ed, arg);
	else if (cmd[0] == 'a')
		cmd_append(ed, arg);
	else if (cmd[0] == 'd')
		cmd_delete(ed, ft_atoi_ed(arg));
	else if (cmd[0] == 'r')
	{
		n1 = ft_atoi_ed(arg);
		while (*arg && *arg != ' ')
			arg++;
		while (*arg == ' ')
			arg++;
		cmd_replace(ed, n1, arg);
	}
	else if (cmd[0] == 's')
		cmd_search(ed, arg);
	else if (cmd[0] == 'w')
	{
		if (*arg)
		{
			if (editor_save(ed, arg) == 0)
				printf("Sauvegardé: %s (%d lignes)\n", arg, ed->line_count);
			else
				printf("Erreur de sauvegarde\n");
		}
		else if (ed->filename)
		{
			if (editor_save(ed, NULL) == 0)
				printf("Sauvegardé: %s (%d lignes)\n", ed->filename, ed->line_count);
			else
				printf("Erreur de sauvegarde\n");
		}
		else
			printf("Spécifiez un nom de fichier: w <nom>\n");
	}
	else if (cmd[0] == '+')
	{
		if (ed->current && ed->current->next)
		{
			ed->current = ed->current->next;
			ed->current_num++;
			printf("%4d: %s\n", ed->current_num, ed->current->content);
		}
	}
	else if (cmd[0] == '-')
	{
		if (ed->current && ed->current->prev)
		{
			ed->current = ed->current->prev;
			ed->current_num--;
			printf("%4d: %s\n", ed->current_num, ed->current->content);
		}
	}
	else if (cmd[0] == '.')
	{
		if (ed->current)
			printf("%4d: %s\n", ed->current_num, ed->current->content);
	}
	else
		printf("Commande inconnue: '%c'. Tapez 'h' pour l'aide.\n", cmd[0]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_editor	*ed;
	char		cmd[MAX_LINE_LEN];
	int			running;

	ed = editor_new();
	if (!ed)
	{
		fprintf(stderr, "Erreur: allocation mémoire\n");
		return (1);
	}
	print_banner();
	if (argc > 1)
	{
		if (editor_load(ed, argv[1]) == 0)
			printf("Fichier chargé: %s (%d lignes)\n", argv[1], ed->line_count);
		else
			printf("Nouveau fichier: %s\n", argv[1]);
	}
	running = 1;
	while (running)
	{
		print_prompt(ed);
		if (!fgets(cmd, MAX_LINE_LEN, stdin))
			break ;
		cmd[strcspn(cmd, "\n")] = '\0';
		running = process_command(ed, cmd);
	}
	printf("\nAu revoir!\n");
	editor_free(ed);
	return (0);
}
