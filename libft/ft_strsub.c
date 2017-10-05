/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:23:45 by hlouar            #+#    #+#             */
/*   Updated: 2016/05/23 10:13:26 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		str = ft_strncpy(str, &s[start], len);
		str[len] = '\0';
	}
	return (str);
}
