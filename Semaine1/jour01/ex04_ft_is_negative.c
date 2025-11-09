/* ************************************************************************** */
/*                                                                            */
/*   ex04_ft_is_negative.c                                                    */
/*                                                                            */
/*   Exercice : ft_is_negative                                                */
/*   Afficher 'N' si négatif, 'P' si positif ou zéro                          */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui affiche 'N' si l'entier passé en paramètre
** est négatif, et 'P' s'il est positif ou nul.
**
** Prototype : void ft_is_negative(int n);
**
** EXEMPLES :
** ft_is_negative(-5)   → affiche "N"
** ft_is_negative(0)    → affiche "P"
** ft_is_negative(42)   → affiche "P"
**
** IMPORTANT :
** 0 est considéré comme positif
*/

#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

/*
** EXPLICATION :
**
** if (n < 0) → test strictement inférieur à 0
** 0 est >= 0 donc va dans le else (positif)
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C comme en JS, la comparaison < 0 est directe.
** Mais JS a des subtilités avec -0 et NaN :
**
** C  : if (n < 0) → simple
** JS : if (n < 0) → attention aux edge cases!
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Le cas spécial de -0 en JS
**    -0 === 0           // true (!)
**    -0 < 0             // false
**    Object.is(-0, 0)   // false
**    1 / -0             // -Infinity
**    1 / 0              // Infinity
**
**    → -0 existe en JS mais pas en C!
**
** 2. NaN (Not a Number)
**    NaN < 0            // false
**    NaN >= 0           // false
**    NaN === NaN        // false (!)
**    isNaN(NaN)         // true
**    Number.isNaN(NaN)  // true (plus fiable)
**
** 3. Infinity
**    Infinity > 0       // true
**    -Infinity < 0      // true
**    isFinite(Infinity) // false
**
** 4. Type coercion (pièges classiques)
**    '' < 0             // false ('' converti en 0)
**    null < 0           // false (null converti en 0)
**    undefined < 0      // false (undefined → NaN)
**    '5' < 10           // true (coercion en nombre)
**
** 5. Question d'entretien senior :
**    "Différence entre == et === pour -0 et 0 ?"
**    -0 == 0   // true
**    -0 === 0  // true (!)
**    Object.is(-0, 0) // false (le seul qui distingue)
**
** 🎯 ÉQUIVALENT JS (version robuste) :
**
** function isNegative(n) {
**     // Version simple (comme en C)
**     return n < 0 ? 'N' : 'P';
** }
**
** // Version robuste (gère NaN, Infinity, etc.)
** function isNegativeRobust(n) {
**     if (typeof n !== 'number' || isNaN(n)) {
**         throw new Error('Not a valid number');
**     }
**     if (n === -Infinity) return 'N';
**     if (n === Infinity) return 'P';
**     if (Object.is(n, -0)) return 'P'; // -0 considéré positif
**     return n < 0 ? 'N' : 'P';
** }
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Validation de nombres
** function sign(n) {
**     if (n > 0) return 1;
**     if (n < 0) return -1;
**     if (Object.is(n, -0)) return -0;
**     return 0;
** }
**
** // Math.sign() fait exactement ça (ES6+)
** Math.sign(5)    // 1
** Math.sign(-5)   // -1
** Math.sign(0)    // 0
** Math.sign(-0)   // -0
** Math.sign(NaN)  // NaN
**
** // Clamp (limiter un nombre)
** function clamp(value, min, max) {
**     if (value < min) return min;
**     if (value > max) return max;
**     return value;
** }
**
** // Absolute value (valeur absolue)
** function abs(n) {
**     return n < 0 ? -n : n;
** }
** // Math.abs() en JS natif
*/

/*
** TESTS :
**
** int main(void)
** {
**     ft_is_negative(-42);
**     write(1, "\n", 1);
**
**     ft_is_negative(0);
**     write(1, "\n", 1);
**
**     ft_is_negative(42);
**     write(1, "\n", 1);
**
**     ft_is_negative(-2147483648); // INT_MIN
**     write(1, "\n", 1);
**
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex04_ft_is_negative.c -o test_negative
** ./test_negative
**
** SORTIE ATTENDUE :
** N
** P
** P
** N
*/

/*
** CONCEPTS CLÉS :
**
** 1. Opérateurs de comparaison
**    < , > , <= , >= , == , !=
**
** 2. Structure if-else
**    if (condition)
**        instruction;
**    else
**        autre_instruction;
**
** 3. Zéro est positif
**    Convention mathématique : 0 ∈ ℝ⁺
*/
