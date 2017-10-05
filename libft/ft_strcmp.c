/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 14:26:49 by hlouar            #+#    #+#             */
/*   Updated: 2016/05/16 17:03:06 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (s1 && s2 && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (s1 && s2)
		return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
	else
		return (-1);
}
