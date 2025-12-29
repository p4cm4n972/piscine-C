/* challenge_dictionary.c - Dictionnaire complet avec hash table */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_entry
{
	char			*key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

typedef struct s_dict
{
	t_entry	**buckets;
	size_t	size;
	int		count;
}	t_dict;

unsigned long hash(const char *str, size_t size)
{
	unsigned long h = 5381;
	int c;
	while ((c = *str++))
		h = ((h << 5) + h) + c;
	return (h % size);
}

t_dict *dict_create(size_t size)
{
	t_dict *dict = malloc(sizeof(t_dict));
	dict->buckets = calloc(size, sizeof(t_entry *));
	dict->size = size;
	dict->count = 0;
	return (dict);
}

void dict_set(t_dict *dict, const char *key, const char *value)
{
	unsigned long idx = hash(key, dict->size);
	t_entry *entry = dict->buckets[idx];

	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			free(entry->value);
			entry->value = strdup(value);
			return;
		}
		entry = entry->next;
	}

	entry = malloc(sizeof(t_entry));
	entry->key = strdup(key);
	entry->value = strdup(value);
	entry->next = dict->buckets[idx];
	dict->buckets[idx] = entry;
	dict->count++;
}

char *dict_get(t_dict *dict, const char *key)
{
	unsigned long idx = hash(key, dict->size);
	t_entry *entry = dict->buckets[idx];

	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}

int main(void)
{
	t_dict *dict;

	printf("╔════════════════════════════════════════╗\n");
	printf("║     Dictionary - Hash Table Demo      ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	dict = dict_create(100);

	dict_set(dict, "name", "John");
	dict_set(dict, "age", "30");
	dict_set(dict, "city", "Paris");

	printf("name = %s\n", dict_get(dict, "name"));
	printf("age = %s\n", dict_get(dict, "age"));
	printf("city = %s\n", dict_get(dict, "city"));

	printf("\nTotal entries: %d\n", dict->count);

	return (0);
}

/* gcc -Wall -Wextra -Werror challenge_dictionary.c -o dictionary */
