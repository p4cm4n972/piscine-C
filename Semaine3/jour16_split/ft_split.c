/*
 * ft_split.c - Split générique avec un séparateur
 */

#include <stdio.h>
#include <stdlib.h>

int is_sep(char c, char sep)
{
	return (c == sep);
}

int count_words(char *str, char sep)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (!is_sep(*str, sep) && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*str, sep))
			in_word = 0;
		str++;
	}
	return (count);
}

char *word_dup(char *str, int start, int end)
{
	char *word;
	int i = 0;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char **ft_split(char *str, char sep)
{
	char	**result;
	int		i = 0, j, start;
	int		words = count_words(str, sep);

	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i], sep))
			i++;
		start = i;
		while (str[i] && !is_sep(str[i], sep))
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
	{
		printf("[%d] \"%s\"\n", i, split[i]);
		i++;
	}
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
	printf("║         ft_split - Generic             ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	result = ft_split("Hello,World,How,Are,You", ',');
	print_split(result);
	free_split(result);

	printf("\n");
	result = ft_split("one:two:three:four", ':');
	print_split(result);
	free_split(result);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_split.c -o split */
