/* ex02_ft_sort_int_tab.c - Tri à bulles */

/*
** ÉNONCÉ : Trier un tableau d'entiers par ordre croissant
** Utilise l'algorithme de tri à bulles (Bubble Sort)
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		size--;
	}
}

/*
** 🔗 JS :
** // Built-in
** arr.sort((a, b) => a - b);
**
** // Bubble Sort manuel
** function bubbleSort(arr) {
**     for (let i = arr.length - 1; i > 0; i--) {
**         for (let j = 0; j < i; j++) {
**             if (arr[j] > arr[j + 1]) {
**                 [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
**             }
**         }
**     }
**     return arr;
** }
**
** Complexité : O(n²)
** Interview : Quick Sort O(n log n), Merge Sort
** LeetCode #912 - Sort an Array
** Attention : arr.sort() sans comparateur trie en string!
*/
