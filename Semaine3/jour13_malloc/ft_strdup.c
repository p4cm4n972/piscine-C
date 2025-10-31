/*
** EXERCICE : ft_strdup
**
** Duplique une chaîne de caractères avec allocation dynamique.
** C'est une fonction fondamentale de la libc.
**
** Prototype :
** char *ft_strdup(const char *src);
**
** Comportement :
** - Alloue la mémoire nécessaire avec malloc
** - Copie la chaîne src dans la nouvelle zone
** - Retourne le pointeur vers la nouvelle chaîne
** - Retourne NULL si malloc échoue ou si src est NULL
**
** Exemples :
** char *dup = ft_strdup("Hello");
** // dup pointe vers une nouvelle chaîne "Hello"
** // Il faut faire free(dup) après utilisation !
**
** Complexité : O(n) où n = longueur de src
*/

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	// TODO: Implémente ft_strdup
	// 1. Vérifier que src n'est pas NULL
	// 2. Calculer la longueur de src avec ft_strlen
	// 3. Allouer len + 1 octets (le +1 pour '\0')
	//    char *dup = malloc(sizeof(char) * (len + 1));
	// 4. Vérifier que malloc a réussi (if (!dup) return NULL)
	// 5. Copier caractère par caractère :
	//    while (src[i]) { dup[i] = src[i]; i++; }
	// 6. Ajouter le '\0' : dup[i] = '\0';
	// 7. Retourner dup

	return (NULL);
}

int	main(void)
{
	char	*str1 = "Hello World";
	char	*str2 = "";
	char	*str3 = "42";
	char	*dup1, *dup2, *dup3;

	printf("=== Test 1 ===\n");
	dup1 = ft_strdup(str1);
	if (dup1)
	{
		printf("Original : '%s' (%p)\n", str1, (void *)str1);
		printf("Copie    : '%s' (%p)\n", dup1, (void *)dup1);
		printf("Adresses différentes : %s\n", (str1 != dup1) ? "OUI" : "NON");
		free(dup1);
	}
	else
		printf("Erreur : malloc a échoué\n");

	printf("\n=== Test 2 (chaîne vide) ===\n");
	dup2 = ft_strdup(str2);
	if (dup2)
	{
		printf("Original : '%s'\n", str2);
		printf("Copie    : '%s'\n", dup2);
		free(dup2);
	}

	printf("\n=== Test 3 ===\n");
	dup3 = ft_strdup(str3);
	if (dup3)
	{
		printf("Original : '%s'\n", str3);
		printf("Copie    : '%s'\n", dup3);
		free(dup3);
	}

	printf("\n=== Test 4 (NULL) ===\n");
	char *dup4 = ft_strdup(NULL);
	if (dup4)
		free(dup4);
	else
		printf("Retourne NULL pour src = NULL : OK\n");

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** === Test 1 ===
** Original : 'Hello World' (0x...)
** Copie    : 'Hello World' (0x...)
** Adresses différentes : OUI
**
** === Test 2 (chaîne vide) ===
** Original : ''
** Copie    : ''
**
** === Test 3 ===
** Original : '42'
** Copie    : '42'
**
** === Test 4 (NULL) ===
** Retourne NULL pour src = NULL : OK
**
** VÉRIFICATION VALGRIND :
** Compiler :
** gcc -Wall -Wextra -Werror -g ft_strdup.c -o ft_strdup
**
** Tester avec valgrind :
** valgrind --leak-check=full ./ft_strdup
**
** Résultat attendu :
** All heap blocks were freed -- no leaks are possible
**
** 📚 THÉORIE :
** ft_strdup est une fonction POSIX (pas dans C standard).
** Elle est extrêmement utile car elle simplifie la duplication de chaînes.
**
** Différence avec strcpy :
** - strcpy : nécessite que la destination soit déjà allouée
** - strdup : alloue automatiquement la mémoire
**
** ⚠️ IMPORTANT :
** Toute chaîne retournée par ft_strdup DOIT être libérée avec free()
** après utilisation, sinon fuite mémoire !
**
** Variantes possibles :
** - ft_strndup(src, n) : duplique au plus n caractères
** - ft_strdup_range(src, start, end) : duplique une sous-chaîne
*/
