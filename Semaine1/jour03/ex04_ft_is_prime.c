/* ex04_ft_is_prime.c - Vérifier si nombre premier */

/*
** ÉNONCÉ : Retourner 1 si premier, 0 sinon
** is_prime(7) = 1
** is_prime(8) = 0
** is_prime(1) = 0 (pas premier par convention)
*/

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
** 🔗 JS :
** function isPrime(n) {
**     if (n < 2) return false;
**     if (n === 2) return true;
**     if (n % 2 === 0) return false;
**     for (let i = 3; i * i <= n; i += 2) {
**         if (n % i === 0) return false;
**     }
**     return true;
** }
**
** Optimisation : √n au lieu de n
** Question interview : "Count Primes" (LeetCode #204)
** → Sieve of Eratosthenes O(n log log n)
*/
