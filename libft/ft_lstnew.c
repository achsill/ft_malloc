/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:55:03 by hlouar            #+#    #+#             */
/*   Updated: 2015/12/09 21:46:10 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = (t_list *)malloc(sizeof(*tmp));
	if (tmp != NULL)
	{
		if (content == NULL)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			tmp->content = (void *)malloc(content_size * (sizeof(*content)));
			ft_memcpy((tmp->content), content, content_size);
			tmp->content_size = content_size;
		}
		tmp->next = NULL;
		return (tmp);
	}
	return (NULL);
}
