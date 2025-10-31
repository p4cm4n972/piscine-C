/*
** EXERCICE : ft_concat
**
** Concatène deux chaînes de caractères dans une nouvelle chaîne allouée.
**
** Prototype :
** char *ft_concat(char *s1, char *s2);
**
** Comportement :
** - Alloue une nouvelle chaîne de taille len(s1) + len(s2) + 1
** - Copie s1 puis s2 dans la nouvelle chaîne
** - Retourne NULL si s1 ou s2 est NULL
** - Retourne NULL si malloc échoue
**
** Exemples :
** ft_concat("Hello", " World") -> "Hello World"
** ft_concat("", "Test") -> "Test"
** ft_concat("Test", "") -> "Test"
**
** Complexité : O(n + m) où n = len(s1), m = len(s2)
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_concat(char *s1, char *s2)
{
	// TODO: Implémente ft_concat
	// 1. Vérifier que s1 et s2 ne sont pas NULL
	// 2. Calculer les longueurs : len1 = ft_strlen(s1), len2 = ft_strlen(s2)
	// 3. Allouer : char *result = malloc(sizeof(char) * (len1 + len2 + 1))
	// 4. Vérifier malloc : if (!result) return NULL
	// 5. Copier s1 :
	//    i = 0;
	//    while (s1[i]) { result[i] = s1[i]; i++; }
	// 6. Copier s2 :
	//    j = 0;
	//    while (s2[j]) { result[i + j] = s2[j]; j++; }
	// 7. Terminer : result[i + j] = '\0'
	// 8. Retourner result

	return (NULL);
}

int	main(void)
{
	char	*result;

	printf("=== Test 1 : concat('Hello', ' World') ===\n");
	result = ft_concat("Hello", " World");
	if (result)
	{
		printf("Résultat : '%s'\n", result);
		printf("Attendu  : 'Hello World'\n");
		free(result);
	}
	else
		printf("Erreur : malloc a échoué\n");

	printf("\n=== Test 2 : concat('42', 'Paris') ===\n");
	result = ft_concat("42", "Paris");
	if (result)
	{
		printf("Résultat : '%s'\n", result);
		printf("Attendu  : '42Paris'\n");
		free(result);
	}

	printf("\n=== Test 3 : concat('', 'Test') ===\n");
	result = ft_concat("", "Test");
	if (result)
	{
		printf("Résultat : '%s'\n", result);
		printf("Attendu  : 'Test'\n");
		free(result);
	}

	printf("\n=== Test 4 : concat('Test', '') ===\n");
	result = ft_concat("Test", "");
	if (result)
	{
		printf("Résultat : '%s'\n", result);
		printf("Attendu  : 'Test'\n");
		free(result);
	}

	printf("\n=== Test 5 : concat('', '') ===\n");
	result = ft_concat("", "");
	if (result)
	{
		printf("Résultat : '%s'\n", result);
		printf("Attendu  : ''\n");
		free(result);
	}

	printf("\n=== Test 6 : concat(NULL, 'test') ===\n");
	result = ft_concat(NULL, "test");
	if (result)
	{
		printf("Erreur : devrait retourner NULL\n");
		free(result);
	}
	else
		printf("NULL (correct)\n");

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 : concat('Hello', ' World') ===
** Résultat : 'Hello World'
** Attendu  : 'Hello World'
**
** === Test 2 : concat('42', 'Paris') ===
** Résultat : '42Paris'
** Attendu  : '42Paris'
**
** === Test 3 : concat('', 'Test') ===
** Résultat : 'Test'
** Attendu  : 'Test'
**
** === Test 4 : concat('Test', '') ===
** Résultat : 'Test'
** Attendu  : 'Test'
**
** === Test 5 : concat('', '') ===
** Résultat : ''
** Attendu  : ''
**
** === Test 6 : concat(NULL, 'test') ===
** NULL (correct)
**
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror -g ft_concat.c -o ft_concat
** valgrind --leak-check=full ./ft_concat
**
** 📚 THÉORIE :
** ft_concat est l'équivalent de strcat mais avec allocation automatique.
** C'est similaire à l'opérateur + en Python pour les strings.
**
** Différence avec strcat :
** - strcat : modifie dest (doit être assez grand)
** - ft_concat : crée une nouvelle chaîne (comme strjoin)
**
** Allocation nécessaire :
** Pour "Hello" (5 chars) + " World" (6 chars)
** = 5 + 6 + 1 (pour '\0') = 12 octets
**
** ⚠️ PIÈGES COURANTS :
** 1. Oublier le +1 pour '\0'
** 2. Ne pas vérifier si s1 ou s2 est NULL
** 3. Oublier de free après utilisation
** 4. Index mal calculé pour copier s2
**
** BONUS :
** - Chronomètre : < 20 min
** - ft_concat_multi(n, s1, s2, ..., sn) : concat multiple
** - ft_concat_sep(s1, sep, s2) : avec séparateur
** - ft_concat_with_free(s1, s2) : libère s1 et s2 automatiquement
*/
