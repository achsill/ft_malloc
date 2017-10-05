/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:40:10 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:46:02 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

void	init_tiny_global(void)
{
	void	*tmp;
	int		size;

	size = make_it_a_multiple(TINY_LIMIT * NBR_PREMALLOC);
	tmp = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_env.tiny = (t_tiny*)tmp;
	g_env.tiny->size = size;
	g_env.tiny->is_free = 1;
	g_env.tiny->is_origin = 1;
	g_env.tiny->next = NULL;
}

void	malloc_new_tiny_chunck(void)
{
	t_tiny	*tiny;
	t_tiny	*new_chunck;
	size_t	size;
	void	*new_tiny;

	size = make_it_a_multiple(TINY_LIMIT * NBR_PREMALLOC);
	tiny = g_env.tiny;
	while (tiny->next)
		tiny = tiny->next;
	new_tiny = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	new_chunck = (t_tiny *)new_tiny;
	new_chunck->size = size;
	new_chunck->is_free = 1;
	new_chunck->is_origin = 1;
	new_chunck->next = NULL;
	tiny->next = new_chunck;
}

void	add_tiny_chunck(size_t size)
{
	t_tiny	*tiny;
	size_t	old_size;
	void	*new_tiny;
	size_t	new_size;

	tiny = g_env.tiny;
	while (tiny->next)
		tiny = tiny->next;
	old_size = tiny->size;
	tiny->size = size;
	new_size = old_size - tiny->size;
	tiny->is_free = 0;
	if (new_size > BLOCK_SIZE)
	{
		new_tiny = (void *)tiny + tiny->size;
		tiny->next = create_tiny_chunck(new_tiny, new_size);
	}
	else
	{
		tiny->next = NULL;
		malloc_new_tiny_chunck();
	}
}

void	*tiny_malloc(size_t size)
{
	t_tiny	*tiny;
	void	*to_return;
	size_t	tiny_size;

	tiny = g_env.tiny;
	if (tiny == NULL)
	{
		init_tiny_global();
		tiny = g_env.tiny;
	}
	while (tiny)
	{
		tiny_size = tiny->size;
		if (tiny->is_free == 1 && (tiny->size >= size))
		{
			if (tiny->next == NULL)
				add_tiny_chunck(size);
			tiny->is_free = 0;
			to_return = (void *)tiny + BLOCK_SIZE;
			return (to_return);
		}
		tiny = tiny->next;
	}
	return (tiny_malloc2(tiny_size, size));
}
