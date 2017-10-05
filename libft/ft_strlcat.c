/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:24:16 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 16:51:30 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t o;
	size_t i;
	size_t e;
	size_t k;

	i = 0;
	e = ft_strlen(src);
	o = ft_strlen(dst);
	k = e + o;
	if (size < o)
		return (e + size);
	if ((size_t)ft_strlen(dst) < size)
	{
		while (o < (size - 1))
		{
			dst[o++] = src[i++];
		}
	}
	if (size > o)
		dst[o] = 0;
	return (k);
}
