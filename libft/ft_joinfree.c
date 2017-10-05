/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:22:47 by hlouar            #+#    #+#             */
/*   Updated: 2016/02/15 17:24:32 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinfree(char *str, char *dst, int fre)
{
	char	*host;
	int		o;

	o = ft_strlen(str) + ft_strlen(dst);
	host = (char *)malloc(sizeof(host) * o + 1);
	ft_strcpy(host, str);
	ft_strcat(host, dst);
	if (fre == 1)
		free(str);
	if (fre == 2)
		free(dst);
	if (fre == 3)
	{
		free(str);
		free(dst);
	}
	return (host);
}
