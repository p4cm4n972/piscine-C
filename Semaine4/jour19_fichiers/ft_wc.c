/* ft_wc.c - Compter lignes, mots, caractères */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

typedef struct s_count
{
	int lines;
	int words;
	int chars;
}	t_count;

void ft_wc(const char *filename)
{
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	t_count count = {0, 0, 0};
	int in_word = 0;
	int i;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("ft_wc");
		return;
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		for (i = 0; i < bytes_read; i++)
		{
			count.chars++;
			if (buffer[i] == '\n')
				count.lines++;
			if (buffer[i] == ' ' || buffer[i] == '\n' || buffer[i] == '\t')
				in_word = 0;
			else if (!in_word)
			{
				in_word = 1;
				count.words++;
			}
		}
	}

	close(fd);
	printf(" %d  %d  %d %s\n", count.lines, count.words, count.chars, filename);
}

int main(int ac, char **av)
{
	int i;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s <file1> [file2] ...\n", av[0]);
		return (1);
	}

	for (i = 1; i < ac; i++)
		ft_wc(av[i]);

	return (0);
}

/* gcc -Wall -Wextra -Werror ft_wc.c -o ft_wc */
