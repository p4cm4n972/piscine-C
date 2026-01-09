/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_memmove - Copie n octets (gère le chevauchement)
** @dst: zone destination
** @src: zone source
** @len: nombre d'octets à copier
** Return: pointeur vers dst
**
** Gestion du chevauchement:
** - Si dst < src: copie du début vers la fin (normal)
** - Si dst > src: copie de la fin vers le début (évite écrasement)
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
