/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 16:24:25 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/04 17:48:45 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *aig)
{
	int	i;
	int	j;
	int	e;

	e = 0;
	i = 0;
	j = 0;
	if (aig[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = i;
		e = 0;
		while (src[j] == aig[e])
		{
			j++;
			e++;
			if (aig[e] == '\0')
				return (char *)(&src[i]);
		}
		i++;
	}
	return (NULL);
}
