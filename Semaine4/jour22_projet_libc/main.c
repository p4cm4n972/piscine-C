/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

static int	g_tests_passed = 0;
static int	g_tests_failed = 0;

void	test(const char *name, int condition)
{
	if (condition)
	{
		printf("  ✓ %s\n", name);
		g_tests_passed++;
	}
	else
	{
		printf("  ✗ %s FAILED\n", name);
		g_tests_failed++;
	}
}

void	test_is_functions(void)
{
	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_is* / ft_to*           ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	test("ft_isalpha('A')", ft_isalpha('A') != 0);
	test("ft_isalpha('5')", ft_isalpha('5') == 0);
	test("ft_isdigit('5')", ft_isdigit('5') != 0);
	test("ft_isdigit('a')", ft_isdigit('a') == 0);
	test("ft_isalnum('a')", ft_isalnum('a') != 0);
	test("ft_isalnum('5')", ft_isalnum('5') != 0);
	test("ft_isascii(127)", ft_isascii(127) != 0);
	test("ft_isascii(128)", ft_isascii(128) == 0);
	test("ft_isprint(' ')", ft_isprint(' ') != 0);
	test("ft_isprint(31)", ft_isprint(31) == 0);
	test("ft_toupper('a')", ft_toupper('a') == 'A');
	test("ft_tolower('A')", ft_tolower('A') == 'a');
}

void	test_str_functions(void)
{
	char	buf[50];

	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_str*                   ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	test("ft_strlen(\"hello\")", ft_strlen("hello") == 5);
	test("ft_strlen(\"\")", ft_strlen("") == 0);
	test("ft_strchr(\"hello\", 'l')", ft_strchr("hello", 'l') != NULL);
	test("ft_strchr(\"hello\", 'z')", ft_strchr("hello", 'z') == NULL);
	test("ft_strrchr(\"hello\", 'l')", ft_strrchr("hello", 'l') == &"hello"[3]);
	test("ft_strncmp(\"abc\", \"abc\", 3)", ft_strncmp("abc", "abc", 3) == 0);
	test("ft_strncmp(\"abc\", \"abd\", 3)", ft_strncmp("abc", "abd", 3) < 0);
	ft_strlcpy(buf, "hello", 50);
	test("ft_strlcpy", strcmp(buf, "hello") == 0);
	ft_strlcat(buf, " world", 50);
	test("ft_strlcat", strcmp(buf, "hello world") == 0);
	test("ft_strnstr(\"hello\", \"ll\", 5)", ft_strnstr("hello", "ll", 5) != NULL);
}

void	test_mem_functions(void)
{
	char	buf1[20];
	char	buf2[20];

	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_mem*                   ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	ft_memset(buf1, 'A', 5);
	buf1[5] = '\0';
	test("ft_memset", strcmp(buf1, "AAAAA") == 0);
	ft_bzero(buf1, 5);
	test("ft_bzero", buf1[0] == 0 && buf1[4] == 0);
	ft_memcpy(buf1, "hello", 6);
	test("ft_memcpy", strcmp(buf1, "hello") == 0);
	ft_memmove(buf2, buf1, 6);
	test("ft_memmove", strcmp(buf2, "hello") == 0);
	test("ft_memchr", ft_memchr("hello", 'l', 5) != NULL);
	test("ft_memcmp(\"abc\", \"abc\")", ft_memcmp("abc", "abc", 3) == 0);
}

void	test_alloc_functions(void)
{
	char	*dup;
	void	*ptr;
	char	*sub;

	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_alloc*                 ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	test("ft_atoi(\"42\")", ft_atoi("42") == 42);
	test("ft_atoi(\"-42\")", ft_atoi("-42") == -42);
	test("ft_atoi(\"   +42\")", ft_atoi("   +42") == 42);
	ptr = ft_calloc(5, sizeof(int));
	test("ft_calloc", ptr != NULL && ((int *)ptr)[0] == 0);
	free(ptr);
	dup = ft_strdup("hello");
	test("ft_strdup", dup != NULL && strcmp(dup, "hello") == 0);
	free(dup);
	sub = ft_substr("hello world", 6, 5);
	test("ft_substr", sub != NULL && strcmp(sub, "world") == 0);
	free(sub);
}

void	test_extra_functions(void)
{
	char	*str;
	char	**split;

	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_extra                  ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	str = ft_strjoin("hello", " world");
	test("ft_strjoin", str != NULL && strcmp(str, "hello world") == 0);
	free(str);
	str = ft_strtrim("  hello  ", " ");
	test("ft_strtrim", str != NULL && strcmp(str, "hello") == 0);
	free(str);
	str = ft_itoa(-42);
	test("ft_itoa(-42)", str != NULL && strcmp(str, "-42") == 0);
	free(str);
	str = ft_itoa(0);
	test("ft_itoa(0)", str != NULL && strcmp(str, "0") == 0);
	free(str);
	split = ft_split("hello world test", ' ');
	test("ft_split", split != NULL && strcmp(split[0], "hello") == 0
		&& strcmp(split[1], "world") == 0 && strcmp(split[2], "test") == 0);
	if (split)
	{
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
	}
}

void	test_list_functions(void)
{
	t_list	*list;
	t_list	*node;
	char	*s1;
	char	*s2;

	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║          TESTS ft_lst*                   ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	s1 = ft_strdup("first");
	s2 = ft_strdup("second");
	list = ft_lstnew(s1);
	test("ft_lstnew", list != NULL && list->content == s1);
	node = ft_lstnew(s2);
	ft_lstadd_front(&list, node);
	test("ft_lstadd_front", list == node && list->next->content == s1);
	test("ft_lstsize", ft_lstsize(list) == 2);
	test("ft_lstlast", ft_lstlast(list)->content == s1);
	ft_lstclear(&list, free);
	test("ft_lstclear", list == NULL);
}

int	main(void)
{
	printf("\n╔══════════════════════════════════════════════════════════╗\n");
	printf("║              LIBFT - Tests de validation                 ║\n");
	printf("║              42 fonctions implémentées                   ║\n");
	printf("╚══════════════════════════════════════════════════════════╝\n");
	test_is_functions();
	test_str_functions();
	test_mem_functions();
	test_alloc_functions();
	test_extra_functions();
	test_list_functions();
	printf("\n╔══════════════════════════════════════════╗\n");
	printf("║              RÉSULTATS                   ║\n");
	printf("╚══════════════════════════════════════════╝\n");
	printf("  Tests passés : %d\n", g_tests_passed);
	printf("  Tests échoués: %d\n", g_tests_failed);
	if (g_tests_failed == 0)
		printf("\n  ✓ TOUS LES TESTS PASSENT !\n\n");
	else
		printf("\n  ✗ CERTAINS TESTS ONT ÉCHOUÉ\n\n");
	return (g_tests_failed);
}
