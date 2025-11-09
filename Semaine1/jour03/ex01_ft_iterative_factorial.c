/* ************************************************************************** */
/*                                                                            */
/*   ex01_ft_iterative_factorial.c                                            */
/*                                                                            */
/*   Exercice : ft_iterative_factorial                                        */
/*   Calculer la factorielle de manière itérative                            */
/*                                                                            */
/* ************************************************************************** */

/*
** ÉNONCÉ :
**
** Écrire une fonction qui calcule la factorielle d'un nombre.
** n! = n × (n-1) × (n-2) × ... × 2 × 1
**
** Prototype : int ft_iterative_factorial(int n);
**
** EXEMPLES :
** factorial(0) = 1
** factorial(5) = 120 (5×4×3×2×1)
** factorial(-5) = 0 (invalide)
**
** CONTRAINTES :
** - Si n < 0, retourner 0
** - 0! = 1 par convention
*/

int	ft_iterative_factorial(int n)
{
	int	result;
	int	i;

	if (n < 0)
		return (0);
	result = 1;
	i = 1;
	while (i <= n)
	{
		result *= i;
		i++;
	}
	return (result);
}

/*
** 🔗 LIEN AVEC JAVASCRIPT :
**
** C  : Boucle while avec multiplication
** JS : Récursion, reduce, ou boucle
**
** 💡 POURQUOI C'EST IMPORTANT :
**
** 1. Itératif vs Récursif
**    // Itératif (comme C)
**    function factorial(n) {
**        if (n < 0) return 0;
**        let result = 1;
**        for (let i = 1; i <= n; i++) result *= i;
**        return result;
**    }
**
**    // Récursif (élégant mais risque stack overflow)
**    function factorial(n) {
**        if (n < 0) return 0;
**        if (n <= 1) return 1;
**        return n * factorial(n - 1);
**    }
**
**    // Reduce (fonctionnel)
**    const factorial = n => n < 0 ? 0 :
**        Array.from({length: n}, (_, i) => i + 1)
**             .reduce((acc, x) => acc * x, 1);
**
** 2. Overflow (très important!)
**    factorial(13) = 6,227,020,800 (OK en int 32-bit)
**    factorial(14) = 87,178,291,200 (OVERFLOW!)
**    → En JS, Number.MAX_SAFE_INTEGER = 2^53
**
** 3. Memoization (DP classique)
**    const memo = {};
**    function factorialMemo(n) {
**        if (n in memo) return memo[n];
**        if (n <= 1) return 1;
**        memo[n] = n * factorialMemo(n - 1);
**        return memo[n];
**    }
**
** 4. Question interview :
**    "Calculer factorielle sans récursion"
**    → Exactement cet exercice!
**
** 💼 UTILISATION :
** - Combinatoire C(n,k) = n! / (k!(n-k)!)
** - Permutations P(n,k) = n! / (n-k)!
** - Probabilités
*/

/*
** TESTS :
**
** #include <stdio.h>
** int main(void)
** {
**     printf("0! = %d\n", ft_iterative_factorial(0));   // 1
**     printf("5! = %d\n", ft_iterative_factorial(5));   // 120
**     printf("-5! = %d\n", ft_iterative_factorial(-5)); // 0
**     return (0);
** }
*/
