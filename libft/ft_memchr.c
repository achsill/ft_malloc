/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:55:13 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 21:56:13 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*e;
	unsigned char	k;

	e = (unsigned char *)str;
	k = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (e[i] == (k))
			return (e + i);
		i++;
	}
	return (NULL);
}
