/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:23:37 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/09 17:29:39 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

int		make_it_a_multiple(int size)
{
	int	i;

	i = 0;
	while ((i + size) % getpagesize() != 0)
		i++;
	return (i + size);
}

void	*malloc(size_t size)
{
	int		new_size;
	void	*to_return;

	new_size = size + BLOCK_SIZE;
	if (new_size <= TINY_LIMIT)
		to_return = tiny_malloc(new_size);
	else if (new_size <= SMALL_LIMIT)
		to_return = small_malloc(new_size);
	else
		to_return = large_malloc(new_size);
	return (to_return);
}

void	*realloc(void *ptr, size_t size)
{
	int		i;
	int		ptr_size;
	void	*new;

	i = 0;
	if (ptr == NULL)
		return (malloc(size));
	ptr_size = handle_check_size(ptr);
	if ((size == 0 && ptr != NULL) || ptr_size == 0)
		return (NULL);
	new = malloc(size);
	if (ptr_size > (int)size)
	{
		new = ft_memcpy(new, ptr, size);
		free(ptr);
		return (new);
	}
	else
	{
		new = ft_memcpy(new, ptr, ptr_size);
		free(ptr);
		return (new);
	}
	return (ptr);
}

void	*realloc_f(void *ptr, size_t size)
{
	void	*to_return;

	to_return = realloc(ptr, size);
	if (to_return == NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
		return (to_return);
}

void	free(void *ptr)
{
	if (ptr == NULL)
		return ;
	if (is_free_tiny(ptr) == 1)
		tiny_free(ptr);
	else if (is_free_small(ptr) == 1)
		small_free(ptr);
	else
		large_free(ptr);
}
