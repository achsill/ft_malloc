/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 17:03:29 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 17:02:05 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_malloc.h"

void	print_format(unsigned long long tmp, unsigned long long tmp2, int size)
{
	put_hexa(tmp);
	ft_putstr(" - ");
	put_hexa(tmp2);
	ft_putstr(" : ");
	ft_putnbr(size);
	ft_putstr(" octets");
	ft_putchar('\n');
}

void	show_alloc_large(t_large *large)
{
	while (large)
	{
		if (large->is_free == 0)
		{
			print_format((unsigned long long)large + BLOCK_SIZE,
					(unsigned long long)large + BLOCK_SIZE + large->size,
					large->size);
		}
		large = large->next;
	}
}

void	show_alloc_small(t_small *small)
{
	while (small)
	{
		if (small->is_free == 0)
		{
			print_format((unsigned long long)small + BLOCK_SIZE,
					(unsigned long long)small + BLOCK_SIZE + small->size,
					small->size);
		}
		small = small->next;
	}
}

void	show_alloc_tiny(t_tiny *tiny)
{
	while (tiny)
	{
		if (tiny->is_free == 0)
		{
			print_format((unsigned long long)tiny + BLOCK_SIZE,
					(unsigned long long)tiny + BLOCK_SIZE + tiny->size,
					tiny->size);
		}
		tiny = tiny->next;
	}
}

void	show_alloc_mem(void)
{
	ft_putstr("TINY: ");
	put_hexa((unsigned long long)g_env.tiny);
	ft_putchar('\n');
	show_alloc_tiny(g_env.tiny);
	ft_putstr("SMALL: ");
	put_hexa((unsigned long long)g_env.small);
	ft_putchar('\n');
	show_alloc_small(g_env.small);
	ft_putstr("LARGE: ");
	put_hexa((unsigned long long)g_env.large);
	ft_putchar('\n');
	show_alloc_large(g_env.large);
}
