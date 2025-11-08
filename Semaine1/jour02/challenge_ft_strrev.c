/* ************************************************************************** */
/*                                                                            */
/*   challenge_ft_strrev.c                                                    */
/*                                                                            */
/*   CHALLENGE : ft_strrev                                                    */
/*   Inverser une chaîne de caractères EN PLACE                              */
/*                                                                            */
/* ************************************************************************** */

/*
** 🏆 CHALLENGE : ft_strrev
**
** Inverse une chaîne de caractères EN PLACE (sans créer de nouvelle chaîne).
**
** Prototype : char *ft_strrev(char *str);
**
** EXEMPLES :
** ft_strrev("Hello")  → "olleH"
** ft_strrev("42")     → "24"
** ft_strrev("a")      → "a"
** ft_strrev("")       → ""
**
** CONTRAINTES :
** - Modification directe de la chaîne (pas de malloc)
** - Utilise la technique des deux pointeurs (début et fin)
** - Retourne un pointeur vers la chaîne modifiée
**
** ALGORITHME (Two Pointers) :
**
** Avant :  H e l l o
**          ↑       ↑
**        start   end
**
** Étape 1: o e l l H  (échange H et o)
**            ↑   ↑
**          start end
**
** Étape 2: o l l e H  (échange e et l)
**              ↑
**         start=end (STOP)
**
** Après :  o l l e H
*/

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	start;
	int	end;
	char	temp;

	// Trouver la longueur et positionner end
	end = 0;
	while (str[end])
		end++;
	end--;  // end pointe maintenant sur le dernier caractère (pas '\0')

	// Échanger les caractères
	start = 0;
	while (start < end)
	{
		// Swap str[start] et str[end]
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		// Avancer start, reculer end
		start++;
		end--;
	}

	return (str);
}

/*
** EXPLICATION DÉTAILLÉE :
**
** Pour str = "Hello" :
**
** Initial : str = ['H', 'e', 'l', 'l', 'o', '\0']
**                   0    1    2    3    4    5
**
** 1. Trouver end :
**    end = 5 (longueur)
**    end-- → end = 4 (dernier caractère)
**
** 2. Boucle d'échange :
**    Itération 1 : start=0, end=4 → swap 'H' et 'o'
**                  ['o', 'e', 'l', 'l', 'H', '\0']
**                  start++, end-- → start=1, end=3
**
**    Itération 2 : start=1, end=3 → swap 'e' et 'l'
**                  ['o', 'l', 'l', 'e', 'H', '\0']
**                  start++, end-- → start=2, end=2
**
**    Itération 3 : start=2, end=2 → start < end est FAUX → STOP
**
** 3. Résultat : "olleH"
*/

/*
** VERSION ALTERNATIVE (avec pointeurs) :
**
** char	*ft_strrev(char *str)
** {
**     char	*start;
**     char	*end;
**     char	temp;
**
**     start = str;
**     end = str;
**
**     // Positionner end sur le dernier caractère
**     while (*end)
**         end++;
**     end--;
**
**     // Échanger
**     while (start < end)
**     {
**         temp = *start;
**         *start = *end;
**         *end = temp;
**         start++;
**         end--;
**     }
**
**     return (str);
** }
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, on inverse EN PLACE (modification directe, O(1) espace).
** En JS, les strings sont immuables → nouvelle string créée :
**
** C  : ft_strrev(str)              → Modification en place, O(1) espace
** JS : str.split('').reverse().join('')  → Nouvelle string, O(n) espace
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Technique Two Pointers (pattern algorithmique)
**    // LeetCode classique : "Reverse String" (Easy)
**    function reverseString(s) {
**        let left = 0, right = s.length - 1;
**        while (left < right) {
**            [s[left], s[right]] = [s[right], s[left]];  // Swap
**            left++;
**            right--;
**        }
**    }
**    // Complexité : O(n) temps, O(1) espace ✅
**
** 2. Questions d'entretien courantes
**    a) "Inverser une string sans utiliser .reverse()"
**       → Exactement cet exercice !
**
**    b) "Vérifier si un string est un palindrome"
**       → Two Pointers depuis les extrémités
**       function isPalindrome(s) {
**           let left = 0, right = s.length - 1;
**           while (left < right) {
**               if (s[left] !== s[right]) return false;
**               left++;
**               right--;
**           }
**           return true;
**       }
**
**    c) "Inverser les mots d'une phrase" (Medium LeetCode)
**       "Hello World" → "World Hello"
**       → Inverse totale + inverse chaque mot
**
** 3. Performance JS : 3 méthodes
**    // ❌ Méthode 1 : split/reverse/join (simple mais O(n) espace)
**    str.split('').reverse().join('')
**
**    // ❌ Méthode 2 : Boucle arrière (O(n) espace aussi)
**    let result = '';
**    for (let i = str.length - 1; i >= 0; i--) {
**        result += str[i];
**    }
**
**    // ✅ Méthode 3 : Array reduction (moderne)
**    [...str].reduce((acc, char) => char + acc, '')
**
** 4. Swap destructuring (ES6+)
**    // En C : besoin d'une variable temp
**    temp = a; a = b; b = temp;
**
**    // En JS : destructuring
**    [a, b] = [b, a];  // Swap élégant !
**
** 🎯 ÉQUIVALENT JS (approche fonctionnelle) :
**
** const reverseString = str => str.split('').reverse().join('');
**
** // Ou avec reduce
** const reverseString = str =>
**     [...str].reduce((reversed, char) => char + reversed, '');
**
** // Ou récursif (interview avancé)
** const reverseString = str =>
**     str === '' ? '' : reverseString(str.slice(1)) + str[0];
**
** 💼 PATTERN TWO POINTERS - Utilisations courantes :
**
** 1. Remove Duplicates (LeetCode Easy)
** 2. Container With Most Water (LeetCode Medium)
** 3. Trapping Rain Water (LeetCode Hard)
** 4. 3Sum (LeetCode Medium - très fréquent en interview)
** 5. Valid Palindrome (LeetCode Easy)
**
** 🏆 COMPLEXITÉ :
** C (en place)  : O(n) temps, O(1) espace → Optimal
** JS (immuable) : O(n) temps, O(n) espace → Acceptable
**
** 💡 ASTUCE SENIOR :
** En JS, si performance critique, convertir string → array mutable :
** const arr = [...str];
** // Modifier arr en place (Two Pointers)
** return arr.join('');
*/

int	main(void)
{
	char test1[] = "Hello";
	char test2[] = "42";
	char test3[] = "a";
	char test4[] = "";
	char test5[] = "Palindrome";

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

	printf("Test 5: '%s' -> ", test5);
	ft_strrev(test5);
	printf("'%s'\n", test5);

	return (0);
}

/*
** COMPILATION ET TEST :
** gcc -Wall -Wextra -Werror challenge_ft_strrev.c -o test_strrev
** ./test_strrev
**
** RÉSULTATS ATTENDUS :
** Test 1: 'Hello' -> 'olleH'
** Test 2: '42' -> '24'
** Test 3: 'a' -> 'a'
** Test 4: '' -> ''
** Test 5: 'Palindrome' -> 'emordnilaP'
*/

/*
** 🎯 COMPLEXITÉ :
** - Temps  : O(n) où n = longueur de la chaîne
** - Espace : O(1) (pas d'allocation, modification en place)
**
** 💡 TECHNIQUE : Two Pointers
** Pattern très utilisé en algorithmique :
** - Palindrome check
** - Reverse array/string
** - Two sum (sorted array)
** - Container with most water
**
** 🔥 CHALLENGE BONUS :
** Essayez de coder ft_strrev en moins de 20 minutes sans regarder la solution !
*/
