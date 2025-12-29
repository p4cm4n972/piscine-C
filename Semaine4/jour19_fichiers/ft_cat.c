/* ft_cat.c - Afficher le contenu d'un fichier */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

int ft_cat(const char *filename)
{
	int fd;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("ft_cat");
		return (-1);
	}

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(1, buffer, bytes_read) == -1)
		{
			perror("write");
			close(fd);
			return (-1);
		}
	}

	if (bytes_read == -1)
	{
		perror("read");
		close(fd);
		return (-1);
	}

	close(fd);
	return (0);
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
	{
		if (ft_cat(av[i]) == -1)
			return (1);
	}

	return (0);
}

/* gcc -Wall -Wextra -Werror ft_cat.c -o ft_cat */
/* ./ft_cat file.txt */
