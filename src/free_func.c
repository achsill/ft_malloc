/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:49:37 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:49:55 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

void	large_free(void *ptr)
{
	t_large	*large;
	void	*to_compare_with;
	int		i;
	t_large	*tmp;

	i = 0;
	large = g_env.large;
	tmp = NULL;
	while (large)
	{
		to_compare_with = (void *)large + BLOCK_SIZE;
		if (ptr == to_compare_with)
		{
			if (i > 0)
			{
				tmp = get_prev(large);
				large_free_2(large, tmp);
				return ;
			}
			large->is_free = 1;
			return ;
		}
		i++;
		large = large->next;
	}
}

void	tiny_free(void *ptr)
{
	t_tiny	*tiny;
	void	*to_compare_with;

	tiny = g_env.tiny;
	while (tiny)
	{
		to_compare_with = (void *)tiny + BLOCK_SIZE;
		if (ptr == to_compare_with)
		{
			tiny->is_free = 1;
			need_to_tiny_munmap(g_env.tiny, 1);
			return ;
		}
		tiny = tiny->next;
	}
}

void	small_free(void *ptr)
{
	t_small	*small;
	void	*to_compare_with;

	small = g_env.small;
	while (small)
	{
		to_compare_with = (void *)small + BLOCK_SIZE;
		if (ptr == to_compare_with)
		{
			small->is_free = 1;
			need_to_small_munmap(g_env.small, 1);
			return ;
		}
		small = small->next;
	}
}
