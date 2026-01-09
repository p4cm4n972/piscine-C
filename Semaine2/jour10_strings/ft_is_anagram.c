/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_anagram.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen_local - Calcule la longueur d'une chaîne (locale)
*/
static int	ft_strlen_local(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

/*
** ft_is_anagram - Vérifie si deux chaînes sont des anagrammes
** @s1: première chaîne
** @s2: deuxième chaîne
** Return: 1 si anagrammes, 0 sinon
**
** Définition: Deux mots sont anagrammes s'ils contiennent exactement
** les mêmes caractères avec les mêmes fréquences.
**
** Algorithme: Comptage de caractères
** - Complexité: O(n) temps, O(1) espace (256 = constant)
**
** Principe:
** 1. Si longueurs différentes -> pas anagrammes
** 2. Créer un tableau de comptage pour 256 caractères ASCII
** 3. Pour chaque caractère de s1: incrémenter le compteur
** 4. Pour chaque caractère de s2: décrémenter le compteur
** 5. Si tous les compteurs sont à 0 -> anagrammes
**
** Exemple: "listen" et "silent"
** - l:1, i:1, s:1, t:1, e:1, n:1 (après s1)
** - l:0, i:0, s:0, t:0, e:0, n:0 (après s2)
** - Tous à 0 -> anagrammes !
**
** Note: Cette implémentation est sensible à la casse
** "Listen" et "silent" ne sont PAS anagrammes ici
*/
int	ft_is_anagram(char *s1, char *s2)
{
	int	count[256];
	int	i;

	if (!s1 || !s2)
		return (0);
	if (ft_strlen_local(s1) != ft_strlen_local(s2))
		return (0);
	i = 0;
	while (i < 256)
	{
		count[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i])
	{
		count[(unsigned char)s1[i]]++;
		count[(unsigned char)s2[i]]--;
		i++;
	}
	i = 0;
	while (i < 256)
	{
		if (count[i] != 0)
			return (0);
		i++;
	}
	return (1);
}
