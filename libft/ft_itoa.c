/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:01:27 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 17:05:23 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		enflure(long int s)
{
	long int		i;

	i = 0;
	while (s)
	{
		i++;
		s = (s / 10);
	}
	return (i);
}

char			*ft_itoa(long int n)
{
	long int		i;
	char			*str;

	i = enflure(n);
	if (n == 0)
		return ("0\0");
	str = (char*)malloc(sizeof(str) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		i++;
		str[0] = 45;
		n = -n;
	}
	while (n)
	{
		i--;
		str[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (str);
}
