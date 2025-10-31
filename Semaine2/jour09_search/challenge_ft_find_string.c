/*
** CHALLENGE : ft_find_string
**
** Trouve la première occurrence d'une sous-chaîne (needle) dans une chaîne (haystack).
** Implémente l'algorithme naïf en O(n*m) puis optimise si possible.
**
** Prototype :
** char *ft_find_string(char *haystack, char *needle);
**
** Retour :
** - Pointeur vers la première occurrence de needle dans haystack
** - NULL si needle n'est pas trouvé
** - haystack si needle est vide
**
** Exemples :
** ft_find_string("Hello World", "World") -> pointeur vers "World"
** ft_find_string("Hello World", "xyz") -> NULL
** ft_find_string("abcabcabc", "cab") -> pointeur vers "cabcabc"
**
** Complexité :
** - Algorithme naïf : O(n * m) où n = taille haystack, m = taille needle
** - KMP : O(n + m) - algorithme avancé
*/

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_find_string(char *haystack, char *needle)
{
	// TODO: Implémente la recherche de sous-chaîne (algorithme naïf)
	// 1. Cas spécial : si needle est vide, retourner haystack
	// 2. Parcourir haystack caractère par caractère
	// 3. À chaque position, vérifier si needle commence ici :
	//    - Comparer caractère par caractère
	//    - Si tous les caractères correspondent, retourner le pointeur
	// 4. Si aucune correspondance, retourner NULL
	//
	// Astuce : utilise deux indices, i pour haystack et j pour needle

	return (0); // À remplacer
}

int	main(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "The quick brown fox jumps over the lazy dog";
	char	*str3 = "abcabcabc";
	char	*result;

	printf("=== Test 1 ===\n");
	result = ft_find_string(str1, "World");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	printf("\n=== Test 2 ===\n");
	result = ft_find_string(str1, "xyz");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	printf("\n=== Test 3 ===\n");
	result = ft_find_string(str2, "fox");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	printf("\n=== Test 4 ===\n");
	result = ft_find_string(str3, "cab");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	printf("\n=== Test 5 (needle vide) ===\n");
	result = ft_find_string(str1, "");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	printf("\n=== Test 6 (début de chaîne) ===\n");
	result = ft_find_string(str1, "Hello");
	if (result)
		printf("Trouvé : '%s'\n", result);
	else
		printf("Non trouvé\n");

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Trouvé : 'World'
**
** === Test 2 ===
** Non trouvé
**
** === Test 3 ===
** Trouvé : 'fox jumps over the lazy dog'
**
** === Test 4 ===
** Trouvé : 'cabcabc'
**
** === Test 5 (needle vide) ===
** Trouvé : 'Hello World'
**
** === Test 6 (début de chaîne) ===
** Trouvé : 'Hello World'
**
** BONUS :
** - Chronomètre : < 25 min
** - Implémente l'algorithme KMP (Knuth-Morris-Pratt) en O(n+m)
** - Compare les performances sur de longues chaînes
** - Compte le nombre de comparaisons effectuées
**
** 📚 THÉORIE :
** Recherche de sous-chaîne est un problème fondamental.
**
** Algorithmes courants :
** 1. Naïf : O(n*m) - simple mais lent
** 2. KMP : O(n+m) - prétraite le pattern pour éviter les comparaisons inutiles
** 3. Boyer-Moore : O(n/m) en moyenne - très rapide en pratique
** 4. Rabin-Karp : O(n+m) - utilise le hashing
**
** La fonction strstr() de la libc utilise généralement une version
** optimisée de l'algorithme naïf ou Boyer-Moore.
**
** Pour la piscine, l'algorithme naïf est suffisant, mais connaître
** les algorithmes avancés est un plus pour les entretiens.
*/
