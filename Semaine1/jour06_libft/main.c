/* main.c - Test program for libft */
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	char	str[] = "PiscineC";
	char	dest[50];
	int		a;
	int		b;
	int		tab[] = {5, 2, 8, 1, 9};
	int		i;

	// Test ft_putstr
	ft_putstr("=== Test libft ===\n");

	// Test ft_strlen
	printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));

	// Test ft_strcpy
	ft_strcpy(dest, str);
	printf("ft_strcpy: copied = %s\n", dest);

	// Test ft_strcmp
	printf("ft_strcmp(\"abc\", \"abc\") = %d\n", ft_strcmp("abc", "abc"));
	printf("ft_strcmp(\"abc\", \"def\") = %d\n", ft_strcmp("abc", "def"));

	// Test ft_swap
	a = 42;
	b = 21;
	printf("\nBefore swap: a=%d, b=%d\n", a, b);
	ft_swap(&a, &b);
	printf("After swap: a=%d, b=%d\n", a, b);

	// Test ft_sort_int_tab
	printf("\nBefore sort: ");
	for (i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	printf("\n");

	ft_sort_int_tab(tab, 5);
	printf("After sort: ");
	for (i = 0; i < 5; i++)
		printf("%d ", tab[i]);
	printf("\n");

	return (0);
}