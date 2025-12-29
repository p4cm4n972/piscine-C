/* ft_hash_function.c - Fonction de hachage djb2 */

#include <stdio.h>

unsigned long ft_hash(const char *str, size_t size)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *str++))
		hash = ((hash << 5) + hash) + c; // hash * 33 + c

	return (hash % size);
}

int main(void)
{
	printf("hash('hello') mod 100 = %lu\n", ft_hash("hello", 100));
	printf("hash('world') mod 100 = %lu\n", ft_hash("world", 100));
	printf("hash('test') mod 100  = %lu\n", ft_hash("test", 100));
	return (0);
}

/* gcc -Wall -Wextra -Werror ft_hash_function.c -o hash */
