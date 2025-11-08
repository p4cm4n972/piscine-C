/* ************************************************************************** */
/*                                                                            */
/*   ex01_ft_strlen.c                                                         */
/*                                                                            */
/*   Exercice : ft_strlen                                                     */
/*   Reproduire le comportement de la fonction strlen (man strlen)           */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui compte le nombre de caractères dans une chaîne
** et retourne ce nombre.
**
** Prototype : int ft_strlen(char *str);
**
** Elle devra être prototypée de la façon suivante :
** int ft_strlen(char *str);
**
** EXEMPLES :
** ft_strlen("Hello")     → retourne 5
** ft_strlen("")          → retourne 0
** ft_strlen("42")        → retourne 2
**
** CONTRAINTES :
** - Parcourir la chaîne caractère par caractère
** - S'arrêter au '\0' (caractère null de fin de chaîne)
** - Retourner le nombre de caractères (sans compter le '\0')
**
** RAPPEL :
** En C, les chaînes de caractères sont des tableaux terminés par '\0'
** Exemple: "Hi" = ['H', 'i', '\0']
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** En C, vous devez parcourir manuellement chaque caractère.
** En JS, c'est automatique :
**
** C  : ft_strlen(str)  → Boucle manuelle O(n)
** JS : str.length      → Propriété O(1) (stockée dans l'objet)
**
** 💡 POURQUOI C'EST IMPORTANT POUR UN SENIOR JS :
**
** 1. Comprendre la complexité cachée
**    "Hello".length  // Paraît gratuit mais quelqu'un a compté!
**
** 2. Optimisation en JS
**    // ❌ Mauvais (recalcule length à chaque itération)
**    for (let i = 0; i < str.length; i++)
**
**    // ✅ Bon (cache la length)
**    const len = str.length;
**    for (let i = 0; i < len; i++)
**
** 3. Question d'entretien type :
**    "Comment implémenter .length sans utiliser .length ?"
**    → Exactement ce que vous faites ici en C!
**
** 🎯 ÉQUIVALENT JS (ce qui se passe sous le capot) :
**
** String.prototype.length = function() {
**     let count = 0;
**     for (let char of this) count++;
**     return count;
** }
*/

/*
** TESTS (à compiler avec un main) :
**
** #include <stdio.h>
**
** int main(void)
** {
**     printf("ft_strlen(\"Hello\") = %d\n", ft_strlen("Hello"));     // 5
**     printf("ft_strlen(\"\") = %d\n", ft_strlen(""));               // 0
**     printf("ft_strlen(\"42\") = %d\n", ft_strlen("42"));           // 2
**     printf("ft_strlen(\"Piscine C\") = %d\n", ft_strlen("Piscine C")); // 9
**     return (0);
** }
**
** COMPILATION :
** gcc -Wall -Wextra -Werror ex01_ft_strlen.c -o test_strlen
** ./test_strlen
*/
