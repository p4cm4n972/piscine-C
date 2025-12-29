/*
 * minishell.h - Header principal du minishell
 */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <signal.h>

# define MAX_ARGS 100
# define BUFFER_SIZE 1024

// Structure pour stocker les commandes
typedef struct s_cmd
{
	char	*name;
	char	**args;
	int		argc;
}	t_cmd;

// Parsing
t_cmd	*parse_command(char *line);
void	free_command(t_cmd *cmd);

// Exécution
int		execute_command(t_cmd *cmd, char **env);
int		execute_external(t_cmd *cmd, char **env);

// Builtins
int		is_builtin(char *cmd);
int		execute_builtin(t_cmd *cmd, char **env);
int		builtin_cd(char **args);
int		builtin_pwd(void);
int		builtin_echo(char **args);
int		builtin_env(char **env);
int		builtin_exit(char **args);

// Utils
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	print_prompt(void);

// Signals
void	setup_signals(void);
void	handle_sigint(int sig);

#endif
