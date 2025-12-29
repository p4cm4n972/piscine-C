/* signals.c - Gestion des signaux */

#include "minishell.h"

void handle_sigint(int sig)
{
	(void)sig;
	printf("\n");
	print_prompt();
}

void setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
