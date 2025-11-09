/*
** CHALLENGE : ft_find_next_prime
**
** Retourne le plus petit nombre premier supérieur ou égal à nb.
**
** Prototype :
** int ft_find_next_prime(int nb);
**
** Exemples :
** ft_find_next_prime(5) = 5 (5 est premier)
** ft_find_next_prime(6) = 7 (6 n'est pas premier, le suivant est 7)
** ft_find_next_prime(100) = 101
** ft_find_next_prime(-10) = 2 (le premier nombre premier)
**
** Contraintes :
** - Réutilise ft_is_prime que tu as déjà codé
** - Gère les nombres négatifs (retourne 2)
*/

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	i = 3;
	while (i * i <= nb)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

int	main(void)
{
	printf("ft_find_next_prime(5) = %d (attendu: 5)\n", ft_find_next_prime(5));
	printf("ft_find_next_prime(6) = %d (attendu: 7)\n", ft_find_next_prime(6));
	printf("ft_find_next_prime(100) = %d (attendu: 101)\n", ft_find_next_prime(100));
	printf("ft_find_next_prime(-10) = %d (attendu: 2)\n", ft_find_next_prime(-10));
	printf("ft_find_next_prime(0) = %d (attendu: 2)\n", ft_find_next_prime(0));
	printf("ft_find_next_prime(1) = %d (attendu: 2)\n", ft_find_next_prime(1));
	printf("ft_find_next_prime(2) = %d (attendu: 2)\n", ft_find_next_prime(2));
	printf("ft_find_next_prime(13) = %d (attendu: 13)\n", ft_find_next_prime(13));

	return (0);
}

/*
** 🔗 JS :
** function findNextPrime(n) {
**     if (n < 2) return 2;
**     while (!isPrime(n)) n++;
**     return n;
** }
**
** Interview : Prime number generation, caching
** LeetCode #204 - Count Primes (Sieve of Eratosthenes)
** Optimization : Skip even numbers after 2
*/
