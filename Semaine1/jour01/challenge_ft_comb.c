/*
** CHALLENGE : ft_comb
**
** Affiche toutes les combinaisons possibles de trois chiffres différents
** dans l'ordre croissant, séparées par ", ".
**
** Exemple de sortie :
** 012, 013, 014, ..., 789
**
** Contraintes :
** - Les trois chiffres doivent être différents
** - Ordre strictement croissant (a < b < c)
** - Pas de ", " après la dernière combinaison
*/

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_comb(void)
{
	// TODO: À toi de coder !
	// Astuce : utilise 3 boucles imbriquées
	// N'oublie pas la condition a < b < c
}

int	main(void)
{
	ft_comb();
	ft_putchar('\n');
	return (0);
}

/*
** TESTS À FAIRE :
** - Compile : gcc -Wall -Wextra -Werror challenge_ft_comb.c
** - Vérifie que la sortie commence par "012, 013, ..."
** - Vérifie que la sortie se termine par "789" (sans ", " après)
** - Compte le nombre de combinaisons : doit être C(10,3) = 120
**
** BONUS :
** - Chronomètre-toi : < 30 min
** - Essaie sans regarder la correction
*/
