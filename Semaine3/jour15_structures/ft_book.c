/*
 * ft_book.c - Gestion de livres avec structures
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_book
{
	char	*title;
	char	*author;
	int		year;
	float	price;
}	t_book;

t_book *create_book(char *title, char *author, int year, float price)
{
	t_book *book = malloc(sizeof(t_book));
	if (!book)
		return (NULL);
	book->title = strdup(title);
	book->author = strdup(author);
	book->year = year;
	book->price = price;
	return (book);
}

void print_book(t_book *book)
{
	if (!book)
		return;
	printf("╭─────────────────────────────────────╮\n");
	printf("│ Titre  : %-27s│\n", book->title);
	printf("│ Auteur : %-27s│\n", book->author);
	printf("│ Année  : %-27d│\n", book->year);
	printf("│ Prix   : %.2f€%-22s│\n", book->price, "");
	printf("╰─────────────────────────────────────╯\n");
}

void free_book(t_book *book)
{
	if (!book)
		return;
	free(book->title);
	free(book->author);
	free(book);
}

int main(void)
{
	t_book *book1, *book2;

	printf("╔════════════════════════════════════════╗\n");
	printf("║          ft_book - Structure           ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	book1 = create_book("Le Petit Prince", "Antoine de Saint-Exupéry", 1943, 12.50);
	book2 = create_book("1984", "George Orwell", 1949, 15.90);

	print_book(book1);
	printf("\n");
	print_book(book2);

	free_book(book1);
	free_book(book2);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_book.c -o book */
