/* ft_hashtable_create.c - Créer une table de hachage */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_entry
{
	char			*key;
	void			*value;
	struct s_entry	*next;
}	t_entry;

typedef struct s_hashtable
{
	t_entry	**buckets;
	size_t	size;
}	t_hashtable;

t_hashtable *ht_create(size_t size)
{
	t_hashtable *ht;

	ht = malloc(sizeof(t_hashtable));
	if (!ht)
		return (NULL);

	ht->buckets = calloc(size, sizeof(t_entry *));
	if (!ht->buckets)
	{
		free(ht);
		return (NULL);
	}

	ht->size = size;
	return (ht);
}

void ht_destroy(t_hashtable *ht)
{
	size_t i;
	t_entry *entry, *next;

	for (i = 0; i < ht->size; i++)
	{
		entry = ht->buckets[i];
		while (entry)
		{
			next = entry->next;
			free(entry->key);
			free(entry);
			entry = next;
		}
	}
	free(ht->buckets);
	free(ht);
}

int main(void)
{
	t_hashtable *ht;

	ht = ht_create(100);
	if (ht)
	{
		printf("✓ Hash table created with size 100\n");
		ht_destroy(ht);
		printf("✓ Hash table destroyed\n");
	}

	return (0);
}

/* gcc -Wall -Wextra -Werror ft_hashtable_create.c -o ht_create */
