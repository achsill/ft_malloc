/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 13:35:52 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/04 15:24:52 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*new_str;

	new_str = (char *)malloc(sizeof(*new_str) * (ft_strlen(src) + 1));
	if (new_str == NULL)
		return (NULL);
	return (ft_strcpy(new_str, src));
}
