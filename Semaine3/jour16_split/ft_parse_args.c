/*
 * ft_parse_args.c - Parser d'arguments de ligne de commande
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_args
{
	char	*program;
	char	**options;
	char	**files;
	int		opt_count;
	int		file_count;
}	t_args;

t_args *parse_args(int ac, char **av)
{
	t_args *args = malloc(sizeof(t_args));
	int i;

	args->program = av[0];
	args->options = malloc(sizeof(char *) * ac);
	args->files = malloc(sizeof(char *) * ac);
	args->opt_count = 0;
	args->file_count = 0;

	for (i = 1; i < ac; i++)
	{
		if (av[i][0] == '-')
			args->options[args->opt_count++] = av[i];
		else
			args->files[args->file_count++] = av[i];
	}
	args->options[args->opt_count] = NULL;
	args->files[args->file_count] = NULL;
	return (args);
}

void print_args(t_args *args)
{
	int i;

	printf("Programme : %s\n\n", args->program);
	printf("Options (%d) :\n", args->opt_count);
	for (i = 0; i < args->opt_count; i++)
		printf("  %s\n", args->options[i]);
	printf("\nFichiers (%d) :\n", args->file_count);
	for (i = 0; i < args->file_count; i++)
		printf("  %s\n", args->files[i]);
}

void free_args(t_args *args)
{
	free(args->options);
	free(args->files);
	free(args);
}

int main(int ac, char **av)
{
	t_args *args;

	printf("╔════════════════════════════════════════╗\n");
	printf("║      ft_parse_args - Arg parser        ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	if (ac < 2)
	{
		printf("Usage: %s [-option1] [-option2] file1 file2 ...\n", av[0]);
		return (1);
	}

	args = parse_args(ac, av);
	print_args(args);
	free_args(args);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_parse_args.c -o parse_args */
/* ./parse_args -v -d --debug file1.txt file2.txt */
