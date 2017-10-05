/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:59:26 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:45:06 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

void	init_small_global(void)
{
	void	*tmp;
	int		size;

	size = make_it_a_multiple(SMALL_LIMIT * NBR_PREMALLOC);
	tmp = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_env.small = (t_small*)tmp;
	g_env.small->size = size;
	g_env.small->is_free = 1;
	g_env.small->next = NULL;
}

void	malloc_new_small_chunck(void)
{
	t_small	*small;
	t_small	*new_chunck;
	size_t	size;
	void	*new_small;

	size = make_it_a_multiple(SMALL_LIMIT * NBR_PREMALLOC);
	small = g_env.small;
	while (small->next)
		small = small->next;
	new_small = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	new_chunck = (t_small *)new_small;
	new_chunck->size = size;
	new_chunck->is_free = 1;
	new_chunck->next = NULL;
	small->next = new_chunck;
}

void	add_small_chunck(size_t size)
{
	t_small	*small;
	size_t	old_size;
	void	*new_small;
	size_t	new_size;

	small = g_env.small;
	while (small->next)
		small = small->next;
	old_size = small->size;
	small->size = size;
	new_size = old_size - small->size;
	small->is_free = 0;
	if (new_size > BLOCK_SIZE)
	{
		new_small = (void *)small + small->size;
		small->next = create_small_chunck(new_small, new_size);
	}
	else
	{
		small->next = NULL;
		malloc_new_small_chunck();
	}
}

void	*small_malloc(size_t size)
{
	t_small	*small;
	void	*to_return;
	size_t	small_size;

	small = g_env.small;
	if (small == NULL)
	{
		init_small_global();
		small = g_env.small;
	}
	while (small)
	{
		small_size = small->size;
		if (small->is_free == 1 && (small->size >= size))
		{
			if (small->next == NULL)
				add_small_chunck(size);
			small->is_free = 0;
			to_return = (void *)small + BLOCK_SIZE;
			return (to_return);
		}
		small = small->next;
	}
	return (small_malloc2(small_size, size));
}
