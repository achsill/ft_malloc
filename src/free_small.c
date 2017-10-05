/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 15:59:57 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/09 16:06:04 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

t_small	*get_next_small_munmap(int k)
{
	t_small	*tmp;
	int		i;

	i = 0;
	tmp = g_env.small;
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

t_small	*get_small_prev_munmap(int k)
{
	t_small	*tmp;
	int		i;

	i = 0;
	tmp = g_env.small;
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

void	small_swap_and_mun(t_small *tmp, t_small *tmp2)
{
	int	size;

	size = make_it_a_multiple(SMALL_LIMIT * NBR_PREMALLOC);
	if (tmp == g_env.small)
		return ;
	munmap(tmp->next, size);
	tmp->next = tmp2;
}

void	do_the_small_munmap(int k)
{
	t_small	*tmp;
	int		i;
	t_small	*prev;

	i = 0;
	tmp = g_env.small;
	while (tmp)
	{
		if (tmp->is_origin == 1)
			i++;
		if (k == i)
		{
			small_swap_and_mun(get_small_prev_munmap(k),
					get_next_small_munmap(k));
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

void	need_to_small_munmap(t_small *small, int k)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (small)
	{
		if (small->is_free == 1)
			i++;
		count++;
		if (small->next && small->next->is_origin == 1)
		{
			if (count == i)
			{
				do_the_small_munmap(k);
				return ;
			}
			need_to_small_munmap(small->next, k + 1);
			return ;
		}
		small = small->next;
	}
}
