/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piscine                                     +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:00:00 by piscine           #+#    #+#             */
/*   Updated: 2024/10/01 00:00:00 by piscine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_bzero - Met à zéro une zone mémoire
** @s: pointeur vers la zone mémoire
** @n: nombre d'octets à mettre à zéro
**
** Note: Équivalent à memset(s, 0, n)
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
