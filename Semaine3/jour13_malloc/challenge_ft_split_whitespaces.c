/*
** CHALLENGE : ft_split_whitespaces
**
** Découpe une chaîne en mots séparés par des espaces/tabs/newlines.
** Retourne un tableau de chaînes allouées dynamiquement.
**
** Prototype :
** char **ft_split_whitespaces(char *str);
**
** Comportement :
** - Sépare sur ' ', '\t', '\n'
** - Ignore les espaces multiples
** - Le tableau se termine par NULL
** - Chaque mot est alloué avec malloc
** - Retourne NULL si str est NULL ou malloc échoue
**
** Exemple :
** str = "Hello   World\tTest"
** Retourne : ["Hello", "World", "Test", NULL]
**
** Complexité : O(n) où n = longueur de str
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	ft_count_words(char *str)
{
	// TODO: Compte le nombre de mots
	// Utilise ft_is_whitespace et un flag in_word
	return (0);
}

int	ft_word_len(char *str)
{
	// TODO: Retourne la longueur du premier mot
	// S'arrête au premier whitespace ou '\0'
	return (0);
}

char	*ft_strndup(char *src, int n)
{
	// TODO: Duplique les n premiers caractères de src
	// 1. Allouer n + 1 octets
	// 2. Copier n caractères
	// 3. Ajouter '\0'
	// 4. Retourner le pointeur
	return (NULL);
}

char	**ft_split_whitespaces(char *str)
{
	// TODO: Implémente le split
	// 1. Compter le nombre de mots avec ft_count_words
	// 2. Allouer le tableau : char **result = malloc(sizeof(char *) * (count + 1))
	// 3. Vérifier malloc
	// 4. Boucle pour chaque mot :
	//    - Ignorer les whitespaces : while (ft_is_whitespace(*str)) str++;
	//    - Calculer la longueur : len = ft_word_len(str)
	//    - Dupliquer le mot : result[i] = ft_strndup(str, len)
	//    - Avancer le pointeur : str += len
	// 5. Terminer par NULL : result[count] = NULL
	// 6. Retourner result

	return (NULL);
}

void	ft_free_split(char **split)
{
	// TODO: Libère un tableau de chaînes
	// 1. Si split est NULL, retourner
	// 2. Boucle : for (i = 0; split[i]; i++) free(split[i]);
	// 3. free(split);
}

void	ft_print_split(char **split)
{
	int	i;

	if (!split)
	{
		printf("(NULL)\n");
		return;
	}
	i = 0;
	while (split[i])
	{
		printf("[%d] = \"%s\"\n", i, split[i]);
		i++;
	}
	printf("[%d] = NULL\n", i);
}

int	main(void)
{
	char	*str1 = "Hello World Test";
	char	*str2 = "   Multiple   spaces   ";
	char	*str3 = "\tTabs\tand\nnewlines\n";
	char	*str4 = "OneWord";
	char	*str5 = "   ";
	char	**split;

	printf("=== Test 1 ===\n");
	printf("Input: \"%s\"\n", str1);
	split = ft_split_whitespaces(str1);
	ft_print_split(split);
	ft_free_split(split);

	printf("\n=== Test 2 (espaces multiples) ===\n");
	printf("Input: \"%s\"\n", str2);
	split = ft_split_whitespaces(str2);
	ft_print_split(split);
	ft_free_split(split);

	printf("\n=== Test 3 (tabs et newlines) ===\n");
	printf("Input: \"\\tTabs\\tand\\nnewlines\\n\"\n");
	split = ft_split_whitespaces(str3);
	ft_print_split(split);
	ft_free_split(split);

	printf("\n=== Test 4 (un seul mot) ===\n");
	printf("Input: \"%s\"\n", str4);
	split = ft_split_whitespaces(str4);
	ft_print_split(split);
	ft_free_split(split);

	printf("\n=== Test 5 (que des espaces) ===\n");
	printf("Input: \"%s\"\n", str5);
	split = ft_split_whitespaces(str5);
	ft_print_split(split);
	ft_free_split(split);

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Input: "Hello World Test"
** [0] = "Hello"
** [1] = "World"
** [2] = "Test"
** [3] = NULL
**
** === Test 2 (espaces multiples) ===
** Input: "   Multiple   spaces   "
** [0] = "Multiple"
** [1] = "spaces"
** [2] = NULL
**
** === Test 3 (tabs et newlines) ===
** Input: "\tTabs\tand\nnewlines\n"
** [0] = "Tabs"
** [1] = "and"
** [2] = "newlines"
** [3] = NULL
**
** === Test 4 (un seul mot) ===
** Input: "OneWord"
** [0] = "OneWord"
** [1] = NULL
**
** === Test 5 (que des espaces) ===
** Input: "   "
** [0] = NULL
**
** VÉRIFICATION VALGRIND :
** gcc -Wall -Wextra -Werror -g challenge_ft_split_whitespaces.c
** valgrind --leak-check=full ./a.out
**
** Résultat attendu : no leaks are possible
**
** 📚 THÉORIE :
** ft_split est une fonction fondamentale pour le parsing.
** Elle est utilisée dans quasiment tous les parseurs : shell, CSV, JSON, etc.
**
** Structure de la mémoire :
** +-------+
** | char**| -> [ptr1][ptr2][ptr3][NULL]
** +-------+     |     |     |
**               v     v     v
**           "Hello" "World" "Test"
**
** Il faut libérer :
** 1. Chaque chaîne (free(split[i]))
** 2. Le tableau lui-même (free(split))
**
** Ordre de libération :
** - D'abord les chaînes (de 0 à n-1)
** - Puis le tableau
**
** ⚠️ ATTENTION AUX FUITES :
** Si malloc échoue au milieu du split, il faut libérer
** tout ce qui a déjà été alloué avant de retourner NULL !
**
** BONUS :
** - Chronomètre : < 45 min
** - Gestion d'erreur complète si malloc échoue
** - ft_split générique avec séparateur paramétrable
** - Optimisation : calculer la taille totale et allouer d'un coup
*/
