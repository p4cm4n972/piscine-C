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
	// TODO: À toi de coder !
	// Astuce :
	// 1. Si nb < 2, retourne 2
	// 2. Sinon, parcours les nombres à partir de nb
	// 3. Retourne le premier nombre pour lequel ft_is_prime retourne 1

	return (0);
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
** BONUS :
** - Chronomètre : < 15 min
** - Teste avec de grands nombres (10000, 100000)
** - Optimisation : commence la recherche à nb (pas à 2)
*/
