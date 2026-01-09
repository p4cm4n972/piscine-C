/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strrev - Inverse une chaîne de caractères en place
** @str: la chaîne à inverser
** Return: pointeur vers la chaîne inversée (pour chaînage)
**
** Algorithme: Two-pointer technique
** - Complexité: O(n/2) = O(n)
** - En place: oui (pas d'allocation)
**
** Principe:
** 1. Placer un pointeur au début (i = 0)
** 2. Placer un pointeur à la fin (j = len - 1)
** 3. Échanger str[i] et str[j]
** 4. Avancer i, reculer j
** 5. Répéter tant que i < j
**
** Exemple: "hello" -> "olleh"
** - Étape 1: swap(h, o) -> "oellh"
** - Étape 2: swap(e, l) -> "olleh"
** - i >= j, terminé
*/
char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	if (!str)
		return (str);
	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
