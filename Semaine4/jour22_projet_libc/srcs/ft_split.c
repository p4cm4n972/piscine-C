/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*get_word(char const *s, char c, size_t *start)
{
	size_t	len;
	char	*word;
	size_t	i;

	while (s[*start] && s[*start] == c)
		(*start)++;
	len = 0;
	while (s[*start + len] && s[*start + len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
	*start += len;
	return (word);
}

static void	free_array(char **arr, size_t n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

/*
** ft_split - Découpe une chaîne selon un délimiteur
** @s: chaîne à découper
** @c: caractère délimiteur
** Return: tableau de chaînes, NULL si échec
**
** Le tableau est terminé par NULL
** Exemple: ft_split("hello world", ' ') -> ["hello", "world", NULL]
*/
char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	i;
	size_t	start;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		result[i] = get_word(s, c, &start);
		if (!result[i])
		{
			free_array(result, i);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
