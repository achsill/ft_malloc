/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 12:38:49 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/03 16:56:38 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)malloc(size);
	if (str)
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return ((void *)str);
	}
	else
		return (0);
}
