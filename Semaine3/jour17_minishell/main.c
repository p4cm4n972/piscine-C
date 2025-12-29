/* main.c - Point d'entrée du minishell */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
	char	line[BUFFER_SIZE];
	t_cmd	*cmd;
	int		status;

	(void)ac;
	(void)av;

	setup_signals();

	while (1)
	{
		print_prompt();
		if (!fgets(line, BUFFER_SIZE, stdin))
			break;

		// Enlever le \n
		line[strcspn(line, "\n")] = 0;

		if (strlen(line) == 0)
			continue;

		cmd = parse_command(line);
		if (!cmd)
			continue;

		status = execute_command(cmd, env);
		free_command(cmd);

		if (status == -1)
			break;
	}

	printf("\nAu revoir!\n");
	return (0);
}
