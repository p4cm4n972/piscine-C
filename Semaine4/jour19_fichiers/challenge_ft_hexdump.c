/* challenge_ft_hexdump.c - Affichage hexadécimal */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void print_hex_line(unsigned char *buffer, int size, int offset)
{
	int i;

	printf("%08x  ", offset);

	for (i = 0; i < 16; i++)
	{
		if (i < size)
			printf("%02x ", buffer[i]);
		else
			printf("   ");
		if (i == 7)
			printf(" ");
	}

	printf(" |");
	for (i = 0; i < size; i++)
		printf("%c", (buffer[i] >= 32 && buffer[i] <= 126) ? buffer[i] : '.');
	printf("|\n");
}

void ft_hexdump(const char *filename)
{
	int fd;
	unsigned char buffer[16];
	ssize_t bytes_read;
	int offset = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return;
	}

	while ((bytes_read = read(fd, buffer, 16)) > 0)
	{
		print_hex_line(buffer, bytes_read, offset);
		offset += bytes_read;
	}

	close(fd);
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", av[0]);
		return (1);
	}

	ft_hexdump(av[1]);
	return (0);
}

/* gcc -Wall -Wextra -Werror challenge_ft_hexdump.c -o hexdump */
