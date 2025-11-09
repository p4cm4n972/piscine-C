/* ************************************************************************** */
/*                                                                            */
/*   ex03_ft_print_numbers.c                                                  */
/*                                                                            */
/*   Exercice : ft_print_numbers                                              */
/*   Afficher les chiffres de 0 à 9                                           */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui affiche les chiffres de 0 à 9, dans l'ordre,
** sur une seule ligne.
**
** Prototype : void ft_print_numbers(void);
**
** SORTIE ATTENDUE :
** 0123456789
*/

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}

/*
** EXPLICATION :
**
** '0' = ASCII 48, '1' = 49, ..., '9' = 57
** c++ incrémente de 48 à 57
*/

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, '0' à '9' sont des caractères (ASCII 48-57).
** En JS, conversion char ↔ number est plus explicite :
**
** C  : char c = '5'; int n = c - '0'; // n = 5
** JS : let c = '5'; let n = parseInt(c); // ou +c, Number(c)
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Type Coercion en JS
**    '5' - 0     // 5 (coercion implicite)
**    '5' + 0     // '50' (concaténation!)
**    +'5'        // 5 (unary plus)
**    Number('5') // 5 (explicite)
**    parseInt('5') // 5
**
** 2. Générer range de chiffres
**    // ✅ Comme en C
**    Array.from({length: 10}, (_, i) => i).join('') // '0123456789'
**
**    // ✅ Alternative
**    [...Array(10).keys()].join('') // '0123456789'
**
** 3. Convertir char digit ↔ number
**    // C : c - '0'
**    // JS :
**    const charToNum = c => c.charCodeAt(0) - 48;
**    const numToChar = n => String.fromCharCode(n + 48);
**
** 4. Question d'entretien :
**    "Convertir '123' en 123 sans parseInt"
**    → Itérer et utiliser charCode - 48
**
**    function stringToNumber(str) {
**        let result = 0;
**        for (const char of str) {
**            const digit = char.charCodeAt(0) - 48;
**            result = result * 10 + digit;
**        }
**        return result;
**    }
**
** 🎯 ÉQUIVALENT JS :
**
** function printNumbers() {
**     console.log(Array.from({length: 10}, (_, i) => i).join(''));
** }
**
** 💼 UTILISATION EN PRODUCTION :
**
** // Validation de chiffres
** function isDigit(char) {
**     const code = char.charCodeAt(0);
**     return code >= 48 && code <= 57;
** }
**
** // Nettoyer input (garder que digits)
** const cleanDigits = str => str.replace(/[^0-9]/g, '');
*/

/*
** TESTS :
**
** int main(void)
** {
**     ft_print_numbers();
**     write(1, "\n", 1);
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex03_ft_print_numbers.c -o test_numbers
** ./test_numbers
**
** SORTIE :
** 0123456789
*/
