/*
** CHALLENGE : ft_capitalize
**
** Capitalise la première lettre de chaque mot dans une chaîne.
** Un mot est une séquence de caractères alphanumériques.
**
** Prototype :
** char *ft_capitalize(char *str);
**
** Règles :
** - Première lettre de chaque mot en MAJUSCULE
** - Autres lettres en minuscule
** - Les séparateurs sont : espace, tabulation, ponctuation, etc.
**
** Exemples :
** "hello world" -> "Hello World"
** "salut, comment 42mots" -> "Salut, Comment 42mots"
** "  test  TEST  " -> "  Test  Test  "
*/

#include <stdio.h>

int	is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9'));
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	to_uppercase(char c)
{
	if (is_lowercase(c))
		return (c - 32);
	return (c);
}

char	to_lowercase(char c)
{
	if (is_uppercase(c))
		return (c + 32);
	return (c);
}

char	*ft_capitalize(char *str)
{
	// TODO: Implémente la capitalisation
	// 1. Parcourir la chaîne avec un booléen "new_word"
	// 2. Initialiser new_word = 1 (on commence un mot)
	// 3. Pour chaque caractère :
	//    - Si c'est un alphanumérique :
	//      * Si new_word == 1 : mettre en majuscule, new_word = 0
	//      * Sinon : mettre en minuscule
	//    - Sinon (séparateur) :
	//      * new_word = 1
	// 4. Retourner str

	return (str);
}

int	main(void)
{
	char	str1[] = "hello world";
	char	str2[] = "salut, comment vas-tu?";
	char	str3[] = "42paris est GENIAL";
	char	str4[] = "  test  TEST  TeSt  ";
	char	str5[] = "one-two_three four";

	printf("=== Test 1 ===\n");
	printf("Avant : '%s'\n", str1);
	ft_capitalize(str1);
	printf("Après : '%s'\n\n", str1);

	printf("=== Test 2 ===\n");
	printf("Avant : '%s'\n", str2);
	ft_capitalize(str2);
	printf("Après : '%s'\n\n", str2);

	printf("=== Test 3 ===\n");
	printf("Avant : '%s'\n", str3);
	ft_capitalize(str3);
	printf("Après : '%s'\n\n", str3);

	printf("=== Test 4 ===\n");
	printf("Avant : '%s'\n", str4);
	ft_capitalize(str4);
	printf("Après : '%s'\n\n", str4);

	printf("=== Test 5 ===\n");
	printf("Avant : '%s'\n", str5);
	ft_capitalize(str5);
	printf("Après : '%s'\n\n", str5);

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Avant : 'hello world'
** Après : 'Hello World'
**
** === Test 2 ===
** Avant : 'salut, comment vas-tu?'
** Après : 'Salut, Comment Vas-Tu?'
**
** === Test 3 ===
** Avant : '42paris est GENIAL'
** Après : '42paris Est Genial'
**
** === Test 4 ===
** Avant : '  test  TEST  TeSt  '
** Après : '  Test  Test  Test  '
**
** === Test 5 ===
** Avant : 'one-two_three four'
** Après : 'One-Two_Three Four'
**
** BONUS :
** - Chronomètre : < 20 min
** - Version ft_str_capitalize_first : capitalise seulement le premier mot
** - Gère les accents (UTF-8) - beaucoup plus complexe !
** - Lit une ligne depuis stdin et capitalise
**
** 📚 THÉORIE :
** La capitalisation dépend de la définition de "mot".
**
** Définitions possibles :
** 1. Séquence séparée par des espaces
** 2. Séquence alphanumérique (notre choix)
** 3. Séquence selon les règles Unicode
**
** En C, on travaille avec ASCII/Latin-1 par défaut.
** Pour UTF-8, il faut gérer les caractères multi-octets.
**
** Astuce : utiliser un booléen (0 ou 1) pour tracker si on est
** au début d'un nouveau mot est plus lisible qu'une condition complexe.
*/
