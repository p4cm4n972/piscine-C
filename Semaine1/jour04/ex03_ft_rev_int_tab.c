/* ex03_ft_rev_int_tab.c - Inverser un tableau */

/*
** ÉNONCÉ : Inverser l'ordre des éléments d'un tableau
** [1, 2, 3, 4, 5] → [5, 4, 3, 2, 1]
** Modification en place (in-place)
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
}

/*
** 🔗 JS :
** // Built-in (modifie en place)
** arr.reverse();
**
** // Two Pointers manuel
** function reverse(arr) {
**     let left = 0, right = arr.length - 1;
**     while (left < right) {
**         [arr[left], arr[right]] = [arr[right], arr[left]];
**         left++;
**         right--;
**     }
**     return arr;
** }
**
** // Immutable (nouveau tableau)
** const reversed = [...arr].reverse();
**
** Pattern : Two Pointers (convergent)
** LeetCode #344 - Reverse String
** Complexité : O(n/2) = O(n), Space O(1)
*/
