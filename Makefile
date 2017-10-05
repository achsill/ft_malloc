# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hlouar <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/27 15:40:57 by hlouar            #+#    #+#              #
#*   Updated: 2016/05/23 15:13:21 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
		HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif


FULLNAME = libft_malloc.so

NAME = libft_malloc_${HOSTTYPE}.so

SRC = src/main.c  src/malloc_tiny.c src/malloc_large.c src/check_size.c \
			src/malloc_small.c src/tools.c src/free_small.c src/free_tiny.c \
			src/tools2.c src/tools3.c src/free_func.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

LIBS = libft/libft.a

$(NAME):$(OBJ)
		@cd libft && make re && cd ..
		@gcc $(CFLAGS) -shared -o $(NAME) $(SRC) $(LIBS) -I.
		@ln -sf $(NAME) $(FULLNAME)
all: $(NAME)

clean:
		@cd libft && make clean && cd ..
		@/bin/rm -f $(OBJ)

fclean: clean
	@cd libft && make fclean && cd ..
	@/bin/rm -f $(NAME) $(FULLNAME)

re:	fclean all


.PHONY: clean fclean re all
