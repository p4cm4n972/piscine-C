/* ft_tail.c - Afficher les n dernières lignes */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1024

void ft_tail(const char *filename, int n)
{
	FILE *file;
	char *lines[MAX_LINES];
	char buffer[MAX_LINE_LEN];
	int count = 0, i, start;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("fopen");
		return;
	}

	while (fgets(buffer, MAX_LINE_LEN, file))
	{
		if (lines[count % MAX_LINES])
			free(lines[count % MAX_LINES]);
		lines[count % MAX_LINES] = strdup(buffer);
		count++;
	}

	fclose(file);

	start = (count > n) ? count - n : 0;
	for (i = start; i < count; i++)
		printf("%s", lines[i % MAX_LINES]);

	for (i = 0; i < MAX_LINES && i < count; i++)
		if (lines[i])
			free(lines[i]);
}

int main(int ac, char **av)
{
	int n = 10;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s [-n lines] <file>\n", av[0]);
		return (1);
	}

	if (ac == 4 && strcmp(av[1], "-n") == 0)
	{
		n = atoi(av[2]);
		ft_tail(av[3], n);
	}
	else
		ft_tail(av[1], n);

	return (0);
}

/* gcc -Wall -Wextra -Werror ft_tail.c -o ft_tail */
