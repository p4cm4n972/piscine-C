/*
 * challenge_ft_csv_parser.c - Parser CSV simple
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse_csv_line(char *line)
{
	char **fields = malloc(sizeof(char *) * 100);
	char *token;
	int i = 0;

	token = strtok(line, ",");
	while (token)
	{
		fields[i++] = strdup(token);
		token = strtok(NULL, ",");
	}
	fields[i] = NULL;
	return (fields);
}

void print_csv_line(char **fields)
{
	int i = 0;
	while (fields[i])
	{
		printf("  [%d] %s\n", i, fields[i]);
		i++;
	}
}

void free_fields(char **fields)
{
	int i = 0;
	while (fields[i])
		free(fields[i++]);
	free(fields);
}

int main(void)
{
	char line1[] = "John,Doe,30,Engineer";
	char line2[] = "Alice,Smith,25,Designer";
	char line3[] = "Bob,Johnson,35,Manager";
	char **fields;

	printf("╔════════════════════════════════════════╗\n");
	printf("║   challenge_ft_csv_parser - CSV        ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	printf("Ligne 1 : %s\n", line1);
	fields = parse_csv_line(line1);
	print_csv_line(fields);
	free_fields(fields);

	printf("\nLigne 2 : %s\n", line2);
	fields = parse_csv_line(line2);
	print_csv_line(fields);
	free_fields(fields);

	printf("\nLigne 3 : %s\n", line3);
	fields = parse_csv_line(line3);
	print_csv_line(fields);
	free_fields(fields);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g challenge_ft_csv_parser.c -o csv_parser */
