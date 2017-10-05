/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:43:46 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/04 18:16:44 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	e;
	int	i;
	int	n;

	e = 0;
	i = 0;
	n = 0;
	while (str[e] == ' ' || str[e] == '\t' || str[e] == '\n' || str[e] == '\v'
			|| str[e] == '\r' || str[e] == '\f')
		e++;
	if (str[e] == '-')
		i = 1;
	if (str[e] == '-' || str[e] == '+')
		e++;
	while ((str[e] && (str[e] >= '0' && str[e] <= '9')))
	{
		n = n * 10;
		n = n + ((int)str[e] - '0');
		e++;
	}
	if (i == 1)
		return (-n);
	else
		return (n);
}
