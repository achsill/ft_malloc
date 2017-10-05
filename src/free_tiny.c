/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:30:47 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/09 15:57:42 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

t_tiny	*get_next_munmap(int k)
{
	t_tiny	*tmp;
	int		i;

	i = 0;
	tmp = g_env.tiny;
	while (tmp)
	{
		if (tmp->is_origin == 1)
			i++;
		if (i == k + 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_tiny	*get_prev_munmap(int k)
{
	t_tiny	*tmp;
	int		i;

	i = 0;
	tmp = g_env.tiny;
	while (tmp)
	{
		if (tmp->next && tmp->next->is_origin == 1)
			i++;
		if (i == k - 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void	swap_and_mun(t_tiny *tmp, t_tiny *tmp2)
{
	int	size;

	size = make_it_a_multiple(TINY_LIMIT * NBR_PREMALLOC);
	if (tmp == g_env.tiny)
		return ;
	munmap(tmp->next, size);
	tmp->next = tmp2;
}

void	do_the_munmap(int k)
{
	t_tiny	*tmp;
	t_tiny	*prev;
	int		i;

	i = 0;
	tmp = g_env.tiny;
	while (tmp)
	{
		if (tmp->is_origin == 1)
			i++;
		if (k == i)
		{
			swap_and_mun(get_prev_munmap(k), get_next_munmap(k));
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	need_to_tiny_munmap(t_tiny *tiny, int k)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tiny)
	{
		if (tiny->is_free == 1)
			i++;
		count++;
		if (tiny->next && tiny->next->is_origin == 1)
		{
			if (count == i)
			{
				do_the_munmap(k);
				return ;
			}
			need_to_tiny_munmap(tiny->next, k + 1);
			return ;
		}
		tiny = tiny->next;
	}
}
