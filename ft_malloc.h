/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlouar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/10 16:16:45 by hlouar            #+#    #+#             */
/*   Updated: 2017/09/10 17:02:52 by hlouar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H
# include <stdio.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include <string.h>
# include <pthread.h>
# include "libft/libft.h"
# define BLOCK_SIZE 32
# define TINY_LIMIT 532
# define SMALL_LIMIT 4096
# define NBR_PREMALLOC 100

typedef struct	s_tiny
{
	int				is_free;
	int				is_origin;
	size_t			size;
	struct s_tiny	*next;
}				t_tiny;

typedef struct	s_small
{
	int					is_free;
	int					is_origin;
	size_t				size;
	struct s_small		*next;
}				t_small;

typedef struct	s_large
{
	int				is_free;
	int				is_origin;
	size_t			size;
	struct s_large	*next;
}				t_large;

typedef struct	s_manageage
{
	struct s_tiny	*tiny;
	struct s_small	*small;
	struct s_large	*large;
}				t_managepage;

t_managepage	g_env;

void			init_zone();
void			*tiny_malloc(size_t size);
void			*small_malloc(size_t size);
void			tiny_free(void *ptr);
void			small_free(void *ptr);
void			put_hexa(unsigned long long n);
void			*large_malloc(size_t size);
void			free_tiny(void *ptr);
void			free_small(void *ptr);
void			free_large(void *ptr);
int				make_it_a_multiple(int size);
void			print_tiny();
void			print_small();
void			print_large();
void			large_free(void *ptr);
void			tiny_free(void *ptr);
int				handle_check_size(void *ptr);
int				is_free_tiny(void *ptr);
int				is_free_large(void *ptr);
int				is_free_small(void *ptr);
void			show_alloc_mem();
void			show_alloc_large(t_large *large);
void			need_to_tiny_munmap(t_tiny *tiny, int k);
void			need_to_small_munmap(t_small *small, int k);
t_small			*create_small_chunck(void *new_small, size_t new_size);
t_tiny			*create_tiny_chunck(void *new_small, size_t new_size);
void			*small_malloc2(size_t small_size, size_t size);
void			malloc_new_small_chunck(void);
void			malloc_new_tiny_chunck(void);
void			*tiny_malloc2(size_t tiny_size, size_t size);
int				check_tiny_size(void *ptr);
int				check_small_size(void *ptr);
int				check_large_size(void *ptr);
void			large_free_2(t_large *large, t_large *tmp);
t_large			*get_prev(t_large *tmp);

#endif
