/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:50:52 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:54:51 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

t_small	*create_small_chunck(void *new_small, size_t new_size)
{
	t_small	*new_chunck;

	new_chunck = (t_small*)new_small;
	new_chunck->size = new_size;
	new_chunck->is_free = 1;
	new_chunck->next = NULL;
	return (new_chunck);
}

void	*small_malloc2(size_t small_size, size_t size)
{
	if (small_size < size)
	{
		malloc_new_small_chunck();
		return (small_malloc(size));
	}
	return (NULL);
}

t_tiny	*create_tiny_chunck(void *new_tiny, size_t new_size)
{
	t_tiny	*new_chunck;

	new_chunck = (t_tiny*)new_tiny;
	new_chunck->size = new_size;
	new_chunck->is_free = 1;
	new_chunck->is_origin = 0;
	new_chunck->next = NULL;
	return (new_chunck);
}

void	*tiny_malloc2(size_t tiny_size, size_t size)
{
	if (tiny_size < size)
	{
		malloc_new_tiny_chunck();
		return (tiny_malloc(size));
	}
	return (NULL);
}

int		handle_check_size(void *ptr)
{
	if (is_free_tiny(ptr) == 1)
		return (check_tiny_size(ptr));
	else if (is_free_small(ptr) == 1)
		return (check_small_size(ptr));
	else if (is_free_large(ptr) == 1)
		return (check_large_size(ptr));
	return (0);
}
