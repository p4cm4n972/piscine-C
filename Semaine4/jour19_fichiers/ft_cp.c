/* ft_cp.c - Copier un fichier */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 4096

int ft_cp(const char *src, const char *dest)
{
	int fd_src, fd_dest;
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;

	fd_src = open(src, O_RDONLY);
	if (fd_src == -1)
	{
		perror("open source");
		return (-1);
	}

	fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_dest == -1)
	{
		perror("open dest");
		close(fd_src);
		return (-1);
	}

	while ((bytes_read = read(fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_dest, buffer, bytes_read) != bytes_read)
		{
			perror("write");
			close(fd_src);
			close(fd_dest);
			return (-1);
		}
	}

	close(fd_src);
	close(fd_dest);
	return (0);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		fprintf(stderr, "Usage: %s <source> <destination>\n", av[0]);
		return (1);
	}

	if (ft_cp(av[1], av[2]) == -1)
		return (1);

	printf("File copied successfully\n");
	return (0);
}

/* gcc -Wall -Wextra -Werror ft_cp.c -o ft_cp */
