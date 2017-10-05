/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:55:27 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/03 17:04:46 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp_dst;
	char		*tmp_src;
	char		*tmp;

	i = 0;
	tmp_dst = (char*)dst;
	tmp_src = (char*)src;
	tmp = (char *)malloc(sizeof(tmp) * (int)len);
	while (i < len)
	{
		tmp[i] = tmp_src[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		tmp_dst[i] = tmp[i];
		i++;
	}
	return ((void*)dst);
}
