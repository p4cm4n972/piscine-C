/* challenge_ft_file_search.c - Recherche de pattern dans fichier */

#include <stdio.h>
#include <string.h>

void ft_file_search(const char *filename, const char *pattern)
{
	FILE *file;
	char line[1024];
	int line_num = 1;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("fopen");
		return;
	}

	while (fgets(line, sizeof(line), file))
	{
		if (strstr(line, pattern))
			printf("%d: %s", line_num, line);
		line_num++;
	}

	fclose(file);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		fprintf(stderr, "Usage: %s <file> <pattern>\n", av[0]);
		return (1);
	}

	ft_file_search(av[1], av[2]);
	return (0);
}

/* gcc -Wall -Wextra -Werror challenge_ft_file_search.c -o file_search */
