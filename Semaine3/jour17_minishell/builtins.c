/* builtins.c - Commandes intégrées */

#include "minishell.h"

int is_builtin(char *cmd)
{
	return (ft_strcmp(cmd, "cd") == 0 ||
			ft_strcmp(cmd, "pwd") == 0 ||
			ft_strcmp(cmd, "echo") == 0 ||
			ft_strcmp(cmd, "env") == 0 ||
			ft_strcmp(cmd, "exit") == 0);
}

int execute_builtin(t_cmd *cmd, char **env)
{
	if (ft_strcmp(cmd->name, "cd") == 0)
		return (builtin_cd(cmd->args));
	else if (ft_strcmp(cmd->name, "pwd") == 0)
		return (builtin_pwd());
	else if (ft_strcmp(cmd->name, "echo") == 0)
		return (builtin_echo(cmd->args));
	else if (ft_strcmp(cmd->name, "env") == 0)
		return (builtin_env(env));
	else if (ft_strcmp(cmd->name, "exit") == 0)
		return (builtin_exit(cmd->args));
	return (0);
}

int builtin_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "cd: missing argument\n");
		return (1);
	}
	if (chdir(args[1]) != 0)
	{
		perror("cd");
		return (1);
	}
	return (0);
}

int builtin_pwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("%s\n", cwd);
	else
	{
		perror("pwd");
		return (1);
	}
	return (0);
}

int builtin_echo(char **args)
{
	int i = 1;

	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}

int builtin_env(char **env)
{
	int i = 0;

	while (env[i])
		printf("%s\n", env[i++]);
	return (0);
}

int builtin_exit(char **args)
{
	int exit_code = 0;

	if (args[1])
		exit_code = atoi(args[1]);

	printf("exit\n");
	return (-1); // Signal pour quitter la boucle principale
}
