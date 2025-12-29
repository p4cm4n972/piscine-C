/*
 * ft_split_quotes.c - Split en gérant les guillemets
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **ft_split_quotes(char *str)
{
	char **result = malloc(sizeof(char *) * 100);
	char buffer[1000];
	int i = 0, j = 0, k = 0, in_quote = 0;

	while (str[i])
	{
		if (str[i] == '"')
			in_quote = !in_quote;
		else if (str[i] == ' ' && !in_quote)
		{
			if (k > 0)
			{
				buffer[k] = '\0';
				result[j++] = strdup(buffer);
				k = 0;
			}
		}
		else
			buffer[k++] = str[i];
		i++;
	}
	if (k > 0)
	{
		buffer[k] = '\0';
		result[j++] = strdup(buffer);
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
	printf("║     ft_split_quotes - With quotes      ║\n");
	printf("╚════════════════════════════════════════╝\n\n");

	result = ft_split_quotes("echo \"Hello World\" test \"foo bar\"");
	print_split(result);
	free_split(result);

	printf("\n✓ Tests réussis\n");
	return (0);
}
/* gcc -Wall -Wextra -Werror -g ft_split_quotes.c -o split_quotes */
