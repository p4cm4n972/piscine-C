/* executor.c - Exécution des commandes */

#include "minishell.h"

int execute_command(t_cmd *cmd, char **env)
{
	if (!cmd || !cmd->name)
		return (0);

	if (is_builtin(cmd->name))
		return (execute_builtin(cmd, env));

	return (execute_external(cmd, env));
}

int execute_external(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		// Processus fils
		if (execve(cmd->name, cmd->args, env) == -1)
		{
			// Essayer avec /bin/
			char path[256];
			snprintf(path, sizeof(path), "/bin/%s", cmd->name);
			if (execve(path, cmd->args, env) == -1)
			{
				// Essayer avec /usr/bin/
				snprintf(path, sizeof(path), "/usr/bin/%s", cmd->name);
				if (execve(path, cmd->args, env) == -1)
				{
					printf("minishell: %s: command not found\n", cmd->name);
					exit(127);
				}
			}
		}
	}
	else
	{
		// Processus parent
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}

	return (0);
}
