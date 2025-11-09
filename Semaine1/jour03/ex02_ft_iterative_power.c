/* ex02_ft_iterative_power.c - Calculer puissance itérative */

/*
** ÉNONCÉ : Calculer nb^power
** power(2, 3) = 8
** power(5, 0) = 1
** power(0, 0) = 1 (convention)
** power négatif = 0
*/

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
** 🔗 JS : Math.pow(nb, power) ou nb ** power (ES7)
**
** Interview : "Implémenter pow() sans Math.pow"
** → Exponentiation rapide O(log n) :
** function pow(x, n) {
**     if (n === 0) return 1;
**     if (n < 0) return 1 / pow(x, -n);
**     if (n % 2 === 0) {
**         const half = pow(x, n / 2);
**         return half * half;
**     }
**     return x * pow(x, n - 1);
** }
*/
