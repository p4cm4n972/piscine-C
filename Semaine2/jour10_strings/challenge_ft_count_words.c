/*
** CHALLENGE : ft_count_words
**
** Compte le nombre de mots dans une chaîne de caractères.
** Un mot est une séquence de caractères non-blancs.
**
** Prototype :
** int ft_count_words(char *str);
**
** Règles :
** - Les espaces, tabulations, retours à la ligne sont des séparateurs
** - Plusieurs séparateurs consécutifs ne comptent qu'une fois
** - Les espaces en début/fin de chaîne sont ignorés
**
** Exemples :
** "Hello World" -> 2
** "  test  " -> 1
** "one two three" -> 3
** "" -> 0
** "   " -> 0
*/

#include <stdio.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int	ft_count_words(char *str)
{
	// TODO: Compte les mots
	// 1. Initialiser count = 0 et in_word = 0
	// 2. Parcourir la chaîne :
	//    - Si caractère non-blanc ET in_word == 0 :
	//      * Incrémenter count
	//      * in_word = 1
	//    - Si caractère blanc :
	//      * in_word = 0
	// 3. Retourner count

	return (0);
}

int	main(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "  test  ";
	char	*str3 = "one two three";
	char	*str4 = "";
	char	*str5 = "   ";
	char	*str6 = "The quick brown fox jumps over the lazy dog";
	char	*str7 = "a";
	char	*str8 = "   multiple    spaces   between   words   ";

	printf("=== Test 1 ===\n");
	printf("'%s' -> %d mots (attendu: 2)\n\n", str1, ft_count_words(str1));

	printf("=== Test 2 ===\n");
	printf("'%s' -> %d mots (attendu: 1)\n\n", str2, ft_count_words(str2));

	printf("=== Test 3 ===\n");
	printf("'%s' -> %d mots (attendu: 3)\n\n", str3, ft_count_words(str3));

	printf("=== Test 4 ===\n");
	printf("'%s' -> %d mots (attendu: 0)\n\n", str4, ft_count_words(str4));

	printf("=== Test 5 ===\n");
	printf("'%s' -> %d mots (attendu: 0)\n\n", str5, ft_count_words(str5));

	printf("=== Test 6 ===\n");
	printf("'%s' -> %d mots (attendu: 9)\n\n", str6, ft_count_words(str6));

	printf("=== Test 7 ===\n");
	printf("'%s' -> %d mots (attendu: 1)\n\n", str7, ft_count_words(str7));

	printf("=== Test 8 ===\n");
	printf("'%s' -> %d mots (attendu: 4)\n\n", str8, ft_count_words(str8));

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** 'Hello World' -> 2 mots (attendu: 2)
**
** === Test 2 ===
** '  test  ' -> 1 mots (attendu: 1)
**
** === Test 3 ===
** 'one two three' -> 3 mots (attendu: 3)
**
** === Test 4 ===
** '' -> 0 mots (attendu: 0)
**
** === Test 5 ===
** '   ' -> 0 mots (attendu: 0)
**
** === Test 6 ===
** 'The quick brown fox jumps over the lazy dog' -> 9 mots (attendu: 9)
**
** === Test 7 ===
** 'a' -> 1 mots (attendu: 1)
**
** === Test 8 ===
** '   multiple    spaces   between   words   ' -> 4 mots (attendu: 4)
**
** BONUS :
** - Chronomètre : < 15 min
** - ft_split(char *str) : découpe la chaîne en tableau de mots (malloc)
** - ft_word_len(char *str, int index) : longueur du n-ième mot
** - ft_get_word(char *str, int index) : retourne le n-ième mot (malloc)
**
** 📚 THÉORIE :
** Compter les mots est un problème classique de parsing.
**
** Technique du "flag" :
** Utiliser un booléen (in_word) pour tracker si on est actuellement
** dans un mot ou entre deux mots. Cette technique évite de compter
** plusieurs fois les séparateurs consécutifs.
**
** Variantes du problème :
** 1. Compter les mots (ce que tu fais maintenant)
** 2. Extraire chaque mot dans un tableau (ft_split)
** 3. Trouver le mot le plus long/court
** 4. Compter les occurrences d'un mot spécifique
**
** Ce genre de fonction est la base pour :
** - Parseurs de commandes (shell)
** - Analyseurs lexicaux (compilateurs)
** - Traitement de texte
** - Statistiques linguistiques
**
** Complexité : O(n) où n est la longueur de la chaîne
*/
