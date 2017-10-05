/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:53:29 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 16:55:00 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

int		check_large_size(void *ptr)
{
	t_large	*large;
	void	*tmp;

	large = g_env.large;
	while (large)
	{
		if (large->is_free == 0)
		{
			tmp = (void *)large + BLOCK_SIZE;
			if (ptr != NULL && tmp == ptr)
				return (large->size - BLOCK_SIZE);
		}
		large = large->next;
	}
	return (0);
}

void	put_hexa_before_format(unsigned long long n)
{
	if (n > 15)
	{
		put_hexa_before_format(n / 16);
		put_hexa_before_format(n % 16);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[n], 1);
	}
}

void	put_hexa(unsigned long long n)
{
	ft_putstr("0x");
	put_hexa_before_format(n);
}
