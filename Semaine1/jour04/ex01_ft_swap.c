/* ex01_ft_swap.c - Échanger deux entiers */

/*
** ÉNONCÉ : Échanger les valeurs de deux variables
** swap(&a, &b) : a et b sont échangés
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
** 🔗 JS :
** function swap(a, b) {
**     return [b, a]; // Retourne nouveau tuple
** }
** // ou destructuring:
** [a, b] = [b, a];
**
** C : Passage par référence (pointeurs)
** JS : Passage par valeur → retourner nouveau objet
**
** Interview : "Swap without temp variable"
** XOR trick : a^=b; b^=a; a^=b;
** LeetCode contexts: Two pointers, partitioning
*/
