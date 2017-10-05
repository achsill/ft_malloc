/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:08:55 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/09 17:21:59 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

int	is_free_small(void *ptr)
{
	t_small	*small;
	void	*tmp;

	small = g_env.small;
	while (small)
	{
		tmp = (void *)small + BLOCK_SIZE;
		if (ptr == tmp)
			return (1);
		small = small->next;
	}
	return (0);
}

int	is_free_tiny(void *ptr)
{
	t_tiny	*tiny;
	void	*tmp;

	tiny = g_env.tiny;
	while (tiny)
	{
		tmp = (void *)tiny + BLOCK_SIZE;
		if (ptr == tmp)
			return (1);
		tiny = tiny->next;
	}
	return (0);
}

int	is_free_large(void *ptr)
{
	t_large	*large;
	void	*tmp;

	large = g_env.large;
	while (large)
	{
		tmp = (void *)large + BLOCK_SIZE;
		if (ptr == tmp)
			return (1);
		large = large->next;
	}
	return (0);
}

int	check_tiny_size(void *ptr)
{
	t_tiny	*tiny;
	void	*tmp;

	tiny = g_env.tiny;
	while (tiny)
	{
		if (tiny->is_free == 0)
		{
			tmp = (void *)tiny + BLOCK_SIZE;
			if (ptr != NULL && tmp == ptr)
				return (tiny->size - BLOCK_SIZE);
		}
		tiny = tiny->next;
	}
	return (0);
}

int	check_small_size(void *ptr)
{
	t_small	*small;
	void	*tmp;

	small = g_env.small;
	while (small)
	{
		if (small->is_free == 0)
		{
			tmp = (void *)small + BLOCK_SIZE;
			if (ptr != NULL && tmp == ptr)
				return (small->size);
		}
		small = small->next;
	}
	return (0);
}
