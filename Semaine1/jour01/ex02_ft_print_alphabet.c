/* ************************************************************************** */
/*                                                                            */
/*   ex02_ft_print_alphabet.c                                                 */
/*                                                                            */
/*   Exercice : ft_print_alphabet                                             */
/*   Afficher l'alphabet en minuscules                                        */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui affiche l'alphabet en minuscules, dans l'ordre,
** sur une seule ligne.
**
** Prototype : void ft_print_alphabet(void);
**
** COMPORTEMENT :
** - Afficher les lettres de 'a' à 'z'
** - Utiliser uniquement write()
** - Pas de retour à la ligne
**
** SORTIE ATTENDUE :
** abcdefghijklmnopqrstuvwxyz
**
** CONTRAINTE :
** - Utiliser une boucle (while ou for)
** - Incrémenter un char de 'a' à 'z'
*/

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}

/*
** EXPLICATION DU CODE :
**
** char c = 'a'
**   ↓
**   Initialise c avec le caractère 'a' (valeur ASCII 97)
**
** while (c <= 'z')
**   ↓
**   Tant que c est <= 'z' (valeur ASCII 122)
**
** c++
**   ↓
**   Incrémente la valeur ASCII : 'a'→'b'→'c'→...→'z'
**
** ASTUCE :
** Les caractères sont des nombres (ASCII)
** 'a' = 97, 'b' = 98, ..., 'z' = 122
** Donc c++ passe de 97 à 98 (de 'a' à 'b')
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, les caractères sont des entiers (ASCII).
** En JS, les strings sont des objets complexes :
**
** C  : char c = 'a'; c++; // 'b'
** JS : let c = 'a'; c++;  // NaN! (ne fonctionne pas)
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Générer l'alphabet en JS
**    // ❌ Approche naïve (hardcodé)
**    const alphabet = 'abcdefghijklmnopqrstuvwxyz';
**
**    // ✅ Approche algorithmique (comme en C)
**    const alphabet = Array.from({length: 26}, (_, i) =>
**        String.fromCharCode(97 + i)
**    ).join('');
**
**    // ✅ Alternative avec for
**    let alphabet = '';
**    for (let i = 0; i < 26; i++) {
**        alphabet += String.fromCharCode(97 + i);
**    }
**
** 2. Codes ASCII vs Unicode
**    C  : char (1 byte, ASCII)
**    JS : String (UTF-16, peut être plusieurs bytes)
**
**    'a'.charCodeAt(0)           // 97 (ASCII)
**    String.fromCharCode(97)     // 'a'
**
**    '🔥'.charCodeAt(0)          // 55357 (surrogate pair)
**    '🔥'.codePointAt(0)         // 128293 (vrai code Unicode)
**
** 3. Question d'entretien senior :
**    "Générer l'alphabet sans le hardcoder"
**    → Utiliser charCode comme en C!
**
** 4. Performance : String Concatenation
**    // ❌ Lent (crée 26 strings intermédiaires)
**    let result = '';
**    for (let i = 97; i <= 122; i++) {
**        result += String.fromCharCode(i);
**    }
**
**    // ✅ Rapide (1 allocation finale)
**    const chars = [];
**    for (let i = 97; i <= 122; i++) {
**        chars.push(String.fromCharCode(i));
**    }
**    const result = chars.join('');
**
**    // ✅ Le plus rapide (Array.from avec map)
**    const result = Array.from({length: 26}, (_, i) =>
**        String.fromCharCode(97 + i)
**    ).join('');
**
** 🎯 ÉQUIVALENT JS (plusieurs approches) :
**
** // Approche 1 : Comme en C (impérative)
** function printAlphabet() {
**     let result = '';
**     for (let code = 97; code <= 122; code++) {
**         result += String.fromCharCode(code);
**     }
**     console.log(result);
** }
**
** // Approche 2 : Fonctionnelle (moderne)
** function printAlphabet() {
**     const alphabet = Array.from({length: 26}, (_, i) =>
**         String.fromCharCode(97 + i)
**     ).join('');
**     console.log(alphabet);
** }
**
** // Approche 3 : Generator (avancée)
** function* alphabetGenerator() {
**     for (let i = 97; i <= 122; i++) {
**         yield String.fromCharCode(i);
**     }
** }
** const alphabet = [...alphabetGenerator()].join('');
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Générer ranges de caractères (ex: validation)
** const lowercaseLetters = Array.from({length: 26}, (_, i) =>
**     String.fromCharCode(97 + i)
** );
**
** function isLowercase(char) {
**     const code = char.charCodeAt(0);
**     return code >= 97 && code <= 122;
** }
**
** // Shift cipher (Caesar cipher)
** function caesarShift(text, shift) {
**     return text.split('').map(char => {
**         const code = char.charCodeAt(0);
**         if (code >= 97 && code <= 122) {
**             return String.fromCharCode(((code - 97 + shift) % 26) + 97);
**         }
**         return char;
**     }).join('');
** }
**
** caesarShift('abc', 1)  // 'bcd'
** caesarShift('xyz', 3)  // 'abc' (wraparound)
*/

/*
** TESTS (à compiler avec un main) :
**
** int main(void)
** {
**     ft_print_alphabet();
**     write(1, "\n", 1);  // Retour à la ligne pour clarté
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex02_ft_print_alphabet.c -o test_alphabet
** ./test_alphabet
**
** SORTIE ATTENDUE :
** abcdefghijklmnopqrstuvwxyz
*/

/*
** VARIANTES POSSIBLES :
**
** 1. Afficher en majuscules
**    c = 'A'; // ASCII 65
**    while (c <= 'Z') // ASCII 90
**
** 2. Afficher à l'envers
**    c = 'z';
**    while (c >= 'a')
**    {
**        write(1, &c, 1);
**        c--;
**    }
**
** 3. Afficher une lettre sur deux
**    c = 'a';
**    while (c <= 'z')
**    {
**        write(1, &c, 1);
**        c += 2; // a, c, e, g, ...
**    }
*/

/*
** CONCEPTS CLÉS :
**
** 1. ASCII Table
**    'a' = 97, 'b' = 98, ..., 'z' = 122
**    'A' = 65, 'B' = 66, ..., 'Z' = 90
**    '0' = 48, '1' = 49, ..., '9' = 57
**
** 2. Incrémentation de char
**    char c = 'a';
**    c++;  // c devient 'b'
**    → Fonctionne car char est un entier (1 byte)
**
** 3. Comparaison de char
**    c <= 'z' compare les valeurs ASCII
**    → 97 <= 122 (true)
*/
