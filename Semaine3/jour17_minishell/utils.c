/* utils.c - Fonctions utilitaires */

#include "minishell.h"

char *ft_strdup(const char *s)
{
	char	*dup;
	int		len = 0;
	int		i;

	while (s[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);

	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char *ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void print_prompt(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("\033[1;32mminishell\033[0m:\033[1;34m%s\033[0m$ ", cwd);
	else
		printf("minishell$ ");
	fflush(stdout);
}
