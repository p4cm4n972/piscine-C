/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcat - Concatène avec garantie de null-termination
** @dst: buffer destination (doit contenir une chaîne valide)
** @src: chaîne à concaténer
** @dstsize: taille totale du buffer
** Return: longueur de la chaîne qui aurait été créée si dstsize était infini
**
** Note: Si dstsize <= strlen(dst), retourne dstsize + strlen(src)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
