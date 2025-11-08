/* ************************************************************************** */
/*                                                                            */
/*   ex02_ft_strcmp.c                                                         */
/*                                                                            */
/*   Exercice : ft_strcmp                                                     */
/*   Reproduire le comportement de la fonction strcmp (man strcmp)            */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui compare deux chaînes de caractères et retourne
** un entier selon le résultat de la comparaison.
**
** Prototype : int ft_strcmp(char *s1, char *s2);
**
** VALEURS DE RETOUR :
** - Retourne 0 si les chaînes sont identiques
** - Retourne un nombre négatif si s1 < s2 (premier caractère différent)
** - Retourne un nombre positif si s1 > s2 (premier caractère différent)
**
** EXEMPLES :
** ft_strcmp("Hello", "Hello")   → retourne 0
** ft_strcmp("Hello", "World")   → retourne négatif ('H' < 'W')
** ft_strcmp("abc", "ab")        → retourne positif ('c' > '\0')
** ft_strcmp("abc", "abcd")      → retourne négatif ('\0' < 'd')
**
** ALGORITHME :
** 1. Parcourir les deux chaînes caractère par caractère
** 2. S'arrêter dès qu'un caractère diffère OU qu'on atteint la fin
** 3. Retourner la différence entre les caractères (s1[i] - s2[i])
**
** RAPPEL :
** La comparaison se fait sur les valeurs ASCII des caractères
** 'A' = 65, 'B' = 66, 'a' = 97, 'b' = 98, '\0' = 0
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/*
** EXPLICATION DU CODE :
**
** while (s1[i] && s1[i] == s2[i])
**   ↓
**   Tant que s1[i] n'est pas '\0' ET que les caractères sont identiques
**
** return (s1[i] - s2[i]);
**   ↓
**   Retourne la différence entre les deux caractères qui diffèrent
**   (ou entre s1[i] et '\0' si une chaîne est plus courte)
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, strcmp() fait une comparaison lexicographique manuelle.
** En JS, plusieurs méthodes selon le besoin :
**
** C  : ft_strcmp(s1, s2)           → Retourne int (négatif/0/positif)
** JS : s1 === s2                   → Retourne boolean (true/false)
** JS : s1.localeCompare(s2)        → Retourne int (comme strcmp)
** JS : s1 < s2, s1 > s2            → Comparaison lexicographique
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Tri personnalisé (interview classique)
**    // ❌ Erreur commune
**    numbers.sort()  // ["1", "10", "2"] → tri alphabétique!
**
**    // ✅ Avec comparaison personnalisée
**    numbers.sort((a, b) => a - b)  // [1, 2, 10]
**    strings.sort((a, b) => a.localeCompare(b))
**
** 2. Comprendre localeCompare()
**    'a'.localeCompare('b')  // -1 (comme strcmp en C)
**    'b'.localeCompare('a')  // 1
**    'a'.localeCompare('a')  // 0
**
** 3. Question d'entretien type :
**    "Pourquoi [10, 5, 40].sort() donne [10, 40, 5] ?"
**    → Parce que sort() convertit en string et fait strcmp !
**
** 4. Comparaison avec accents (senior+)
**    'é'.localeCompare('e', 'fr', { sensitivity: 'base' })  // 0
**    → Utile pour recherche insensible aux accents
**
** 🎯 ÉQUIVALENT JS (ce qui se passe sous le capot) :
**
** String.prototype.compare = function(other) {
**     for (let i = 0; i < Math.max(this.length, other.length); i++) {
**         const charCode1 = this.charCodeAt(i) || 0;
**         const charCode2 = other.charCodeAt(i) || 0;
**         if (charCode1 !== charCode2) {
**             return charCode1 - charCode2;
**         }
**     }
**     return 0;
** }
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Recherche binaire (nécessite comparaison)
** function binarySearch(arr, target) {
**     let left = 0, right = arr.length - 1;
**     while (left <= right) {
**         const mid = Math.floor((left + right) / 2);
**         const cmp = arr[mid].localeCompare(target);
**         if (cmp === 0) return mid;
**         if (cmp < 0) left = mid + 1;
**         else right = mid - 1;
**     }
**     return -1;
** }
*/

/*
** TESTS (à compiler avec un main) :
**
** #include <stdio.h>
** #include <string.h>
**
** int main(void)
** {
**     // Test 1 : Chaînes identiques
**     printf("ft_strcmp(\"Hello\", \"Hello\") = %d\n",
**            ft_strcmp("Hello", "Hello"));
**     printf("strcmp(\"Hello\", \"Hello\") = %d\n\n",
**            strcmp("Hello", "Hello"));
**
**     // Test 2 : s1 < s2
**     printf("ft_strcmp(\"Hello\", \"World\") = %d\n",
**            ft_strcmp("Hello", "World"));
**     printf("strcmp(\"Hello\", \"World\") = %d\n\n",
**            strcmp("Hello", "World"));
**
**     // Test 3 : s1 > s2
**     printf("ft_strcmp(\"abc\", \"ab\") = %d\n",
**            ft_strcmp("abc", "ab"));
**     printf("strcmp(\"abc\", \"ab\") = %d\n\n",
**            strcmp("abc", "ab"));
**
**     // Test 4 : Longueurs différentes
**     printf("ft_strcmp(\"abc\", \"abcd\") = %d\n",
**            ft_strcmp("abc", "abcd"));
**     printf("strcmp(\"abc\", \"abcd\") = %d\n",
**            strcmp("abc", "abcd"));
**
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex02_ft_strcmp.c -o test_strcmp
** ./test_strcmp
*/
