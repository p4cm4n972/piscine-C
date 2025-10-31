/*
** CHALLENGE : ft_strrev
**
** Inverse une chaîne de caractères EN PLACE (sans créer de nouvelle chaîne).
**
** Prototype :
** char *ft_strrev(char *str);
**
** Exemple :
** "Hello" devient "olleH"
** "42" devient "24"
** "a" reste "a"
** "" reste ""
**
** Contraintes :
** - Modification directe de la chaîne (pas de malloc)
** - Utilise la technique des deux pointeurs (début et fin)
** - Retourne un pointeur vers la chaîne modifiée
*/

#include <stdio.h>

char	*ft_strrev(char *str)
{
	// TODO: À toi de coder !
	// Astuce :
	// 1. Trouve la longueur de la chaîne
	// 2. Utilise deux indices : un au début, un à la fin
	// 3. Échange les caractères et avance/recule les indices
	// 4. Arrête-toi quand ils se croisent

	return (str);
}

int	main(void)
{
	char test1[] = "Hello";
	char test2[] = "42";
	char test3[] = "a";
	char test4[] = "";

	printf("Test 1: '%s' -> ", test1);
	ft_strrev(test1);
	printf("'%s'\n", test1);

	printf("Test 2: '%s' -> ", test2);
	ft_strrev(test2);
	printf("'%s'\n", test2);

	printf("Test 3: '%s' -> ", test3);
	ft_strrev(test3);
	printf("'%s'\n", test3);

	printf("Test 4: '%s' -> ", test4);
	ft_strrev(test4);
	printf("'%s'\n", test4);

	return (0);
}

/*
** RÉSULTATS ATTENDUS :
** Test 1: 'Hello' -> 'olleH'
** Test 2: '42' -> '24'
** Test 3: 'a' -> 'a'
** Test 4: '' -> ''
**
** BONUS :
** - Chronomètre : < 20 min
** - Complexité : O(n) en temps, O(1) en espace
*/
