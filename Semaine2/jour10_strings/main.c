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

#include <stdio.h>
#include <string.h>

/* Prototypes */
char	*ft_strrev(char *str);
int		ft_is_anagram(char *s1, char *s2);

void	test_strrev(void)
{
	char	s1[] = "hello";
	char	s2[] = "Piscine C";
	char	s3[] = "a";
	char	s4[] = "";
	char	s5[] = "12345";

	printf("╔══════════════════════════════════════════╗\n");
	printf("║          FT_STRREV - INVERSION           ║\n");
	printf("╚══════════════════════════════════════════╝\n\n");
	printf("Test 1: \"%s\" -> ", s1);
	ft_strrev(s1);
	printf("\"%s\" (attendu: \"olleh\") %s\n\n", s1,
		strcmp(s1, "olleh") == 0 ? "OK" : "FAIL");
	printf("Test 2: \"%s\" -> ", s2);
	ft_strrev(s2);
	printf("\"%s\" (attendu: \"C enicsiP\") %s\n\n", s2,
		strcmp(s2, "C enicsiP") == 0 ? "OK" : "FAIL");
	printf("Test 3: \"%s\" -> ", s3);
	ft_strrev(s3);
	printf("\"%s\" (attendu: \"a\") %s\n\n", s3,
		strcmp(s3, "a") == 0 ? "OK" : "FAIL");
	printf("Test 4: \"\" -> ");
	ft_strrev(s4);
	printf("\"%s\" (attendu: \"\") %s\n\n", s4,
		strcmp(s4, "") == 0 ? "OK" : "FAIL");
	printf("Test 5: \"%s\" -> ", s5);
	ft_strrev(s5);
	printf("\"%s\" (attendu: \"54321\") %s\n\n", s5,
		strcmp(s5, "54321") == 0 ? "OK" : "FAIL");
}

void	test_anagram(void)
{
	int	result;

	printf("╔══════════════════════════════════════════╗\n");
	printf("║       FT_IS_ANAGRAM - ANAGRAMMES         ║\n");
	printf("╚══════════════════════════════════════════╝\n\n");
	printf("Test 1: \"listen\" et \"silent\"\n");
	result = ft_is_anagram("listen", "silent");
	printf("  Résultat: %d (attendu: 1) %s\n\n", result,
		result == 1 ? "OK" : "FAIL");
	printf("Test 2: \"triangle\" et \"integral\"\n");
	result = ft_is_anagram("triangle", "integral");
	printf("  Résultat: %d (attendu: 1) %s\n\n", result,
		result == 1 ? "OK" : "FAIL");
	printf("Test 3: \"hello\" et \"world\"\n");
	result = ft_is_anagram("hello", "world");
	printf("  Résultat: %d (attendu: 0) %s\n\n", result,
		result == 0 ? "OK" : "FAIL");
	printf("Test 4: \"aab\" et \"bba\"\n");
	result = ft_is_anagram("aab", "bba");
	printf("  Résultat: %d (attendu: 0) %s\n\n", result,
		result == 0 ? "OK" : "FAIL");
	printf("Test 5: \"\" et \"\" (chaînes vides)\n");
	result = ft_is_anagram("", "");
	printf("  Résultat: %d (attendu: 1) %s\n\n", result,
		result == 1 ? "OK" : "FAIL");
	printf("Test 6: \"ab\" et \"abc\" (longueurs différentes)\n");
	result = ft_is_anagram("ab", "abc");
	printf("  Résultat: %d (attendu: 0) %s\n\n", result,
		result == 0 ? "OK" : "FAIL");
	printf("Test 7: \"Aa\" et \"aA\" (casse différente)\n");
	result = ft_is_anagram("Aa", "aA");
	printf("  Résultat: %d (attendu: 1) %s\n\n", result,
		result == 1 ? "OK" : "FAIL");
}

int	main(void)
{
	printf("\n");
	test_strrev();
	test_anagram();
	return (0);
}
