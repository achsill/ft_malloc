/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:07:44 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:42:26 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

void	init_large_global(size_t size)
{
	void	*tmp;

	size = make_it_a_multiple(size);
	tmp = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_env.large = (t_large*)tmp;
	g_env.large->size = size;
	g_env.large->is_free = 1;
	g_env.large->next = NULL;
}

void	malloc_new_large_chunck(size_t size)
{
	t_large	*large;
	t_large	*new_chunck;
	void	*new_large;

	size = make_it_a_multiple(size);
	large = g_env.large;
	while (large->next)
		large = large->next;
	new_large = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	new_chunck = (t_large *)new_large;
	new_chunck->size = size;
	new_chunck->is_free = 1;
	new_chunck->next = NULL;
	large->next = new_chunck;
}

void	*large_malloc(size_t size)
{
	t_large	*large;
	void	*to_return;

	large = g_env.large;
	if (large == NULL)
	{
		init_large_global(size);
		large = g_env.large;
	}
	while (large)
	{
		if (large->is_free == 1 && large->size >= size)
		{
			large->is_free = 0;
			to_return = (void *)large + BLOCK_SIZE;
			return (to_return);
		}
		large = large->next;
	}
	if (large == NULL)
	{
		malloc_new_large_chunck(size);
		return (large_malloc(size));
	}
	return (NULL);
}

t_large	*get_prev(t_large *tmp)
{
	t_large	*large;

	large = g_env.large;
	while (large)
	{
		if (large->next && large->next == tmp)
			return (large);
		large = large->next;
	}
	return (NULL);
}

void	large_free_2(t_large *large, t_large *tmp)
{
	if (large->next)
		tmp->next = large->next;
	else
		tmp->next = NULL;
	munmap(large, large->size);
}
