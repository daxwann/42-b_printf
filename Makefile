# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 21:40:35 by xwang             #+#    #+#              #
#    Updated: 2018/09/24 21:56:29 by xwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = b_printf.c ft_put.c
OBJ = b_printf.o ft_put.o

all: $(NAME)
$(NAME):
	gcc -Wall -Werror -Wextra -c -I. $(SRCS)
	ar rcs $(NAME) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
