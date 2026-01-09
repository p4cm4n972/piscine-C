/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_binary_search - Recherche binaire dans un tableau trié
** @tab: tableau d'entiers TRIÉ (précondition obligatoire)
** @size: taille du tableau
** @target: valeur à rechercher
** Return: index de l'élément si trouvé, -1 sinon
**
** Algorithme: Recherche binaire (dichotomie)
** - Complexité: O(log n) - très efficace
** - PRÉCONDITION: le tableau DOIT être trié
**
** Principe:
** 1. Comparer target avec l'élément du milieu
** 2. Si égal: trouvé, retourner l'index
** 3. Si target < milieu: chercher dans la moitié gauche
** 4. Si target > milieu: chercher dans la moitié droite
** 5. Répéter jusqu'à trouver ou left > right (non trouvé)
**
** Exemple: chercher 7 dans [1, 3, 5, 7, 9, 11, 13]
** - Étape 1: milieu = 7, trouvé ! Return 3
**
** Note: mid = left + (right - left) / 2 évite l'overflow
** contrairement à (left + right) / 2
*/
int	ft_binary_search(int *tab, int size, int target)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (tab[mid] == target)
			return (mid);
		if (tab[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
