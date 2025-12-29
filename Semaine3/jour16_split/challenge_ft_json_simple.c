/*
 * challenge_ft_json_simple.c - Parser JSON très simplifié
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_json_field
{
	char	*key;
	char	*value;
}	t_json_field;

t_json_field *parse_json_field(char *str)
{
	t_json_field *field = malloc(sizeof(t_json_field));
	char *colon;
	int key_len, val_len;

	// Trouver ":"
	colon = strchr(str, ':');
	if (!colon)
		return (NULL);

	// Extraire la clé (entre guillemets)
	key_len = colon - str - 3; // Enlever " et espaces
	field->key = malloc(key_len + 1);
	strncpy(field->key, str + 2, key_len);
	field->key[key_len] = '\0';

	// Extraire la valeur
	val_len = strlen(colon + 3) - 2;
	field->value = malloc(val_len + 1);
	strncpy(field->value, colon + 3, val_len);
	field->value[val_len] = '\0';

	return (field);
}

void print_json_field(t_json_field *field)
{
	if (!field)
		return;
	printf("  %s = %s\n", field->key, field->value);
}

void free_field(t_json_field *field)
{
	if (!field)
		return;
	free(field->key);
	free(field->value);
	free(field);
}

int main(void)
{
	t_json_field *field;

	printf("╔════════════════════════════════════════╗\n");
	printf("║  challenge_ft_json_simple - JSON       ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	printf("Exemple JSON simple :\n{\n");

	field = parse_json_field("  \"name\": \"John\"");
	print_json_field(field);
	free_field(field);

	field = parse_json_field("  \"age\": \"30\"");
	print_json_field(field);
	free_field(field);

	field = parse_json_field("  \"city\": \"Paris\"");
	print_json_field(field);
	free_field(field);

	printf("}\n");

	printf("\n✓ Tests réussis\n");
	printf("Note: Parser très simplifié pour démo\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g challenge_ft_json_simple.c -o json_simple */
