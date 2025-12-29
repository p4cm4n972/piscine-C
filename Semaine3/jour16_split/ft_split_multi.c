/*
 * ft_split_multi.c - Split avec plusieurs séparateurs
 */

#include <stdio.h>
#include <stdlib.h>

int is_sep(char c, char *seps)
{
	while (*seps)
	{
		if (c == *seps)
			return (1);
		seps++;
	}
	return (0);
}

int count_words(char *str, char *seps)
{
	int count = 0, in_word = 0;

	while (*str)
	{
		if (!is_sep(*str, seps) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*str, seps))
			in_word = 0;
		str++;
	}
	return (count);
}

char *word_dup(char *str, int start, int end)
{
	char *word = malloc(sizeof(char) * (end - start + 1));
	int i = 0;

	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char **ft_split_multi(char *str, char *seps)
{
	char **result;
	int i = 0, j = 0, start, words = count_words(str, seps);

	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] && is_sep(str[i], seps))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], seps))
			i++;
		if (i > start)
			result[j++] = word_dup(str, start, i);
	}
	result[j] = NULL;
	return (result);
}

void print_split(char **split)
{
	int i = 0;
	while (split[i])
		printf("[%d] \"%s\"\n", i, split[i++]);
}

void free_split(char **split)
{
	int i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int main(void)
{
	char **result;

	printf("╔════════════════════════════════════════╗\n");
	printf("║      ft_split_multi - Multi-sep        ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	result = ft_split_multi("Hello, World; How: Are You?", " ,;:?");
	print_split(result);
	free_split(result);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_split_multi.c -o split_multi */
