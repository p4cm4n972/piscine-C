/* parser.c - Parsing des commandes */

#include "minishell.h"

t_cmd *parse_command(char *line)
{
	t_cmd	*cmd;
	char	*token;
	int		i;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);

	cmd->args = malloc(sizeof(char *) * MAX_ARGS);
	cmd->argc = 0;

	token = strtok(line, " \t");
	if (!token)
	{
		free(cmd->args);
		free(cmd);
		return (NULL);
	}

	cmd->name = ft_strdup(token);
	cmd->args[cmd->argc++] = ft_strdup(token);

	while ((token = strtok(NULL, " \t")) != NULL && cmd->argc < MAX_ARGS - 1)
		cmd->args[cmd->argc++] = ft_strdup(token);

	cmd->args[cmd->argc] = NULL;
	return (cmd);
}

void free_command(t_cmd *cmd)
{
	int i;

	if (!cmd)
		return;

	free(cmd->name);
	for (i = 0; i < cmd->argc; i++)
		free(cmd->args[i]);
	free(cmd->args);
	free(cmd);
}
