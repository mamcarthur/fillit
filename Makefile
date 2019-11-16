# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/18 12:46:46 by mmcarthu          #+#    #+#              #
#    Updated: 2019/03/25 18:54:21 by mmcarthu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/parser1.c \
	  srcs/parser2.c \
	  srcs/parser_w_main.c \
	  srcs/fillit.c \
	  srcs/fillit2.c \
	  srcs/fillit3.c \

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@make -C libft re
	gcc -Wall -Wextra -Werror $(SRCS) -I includes/fillit.h $(LIB) -o $(NAME)

clean:
	@make clean -C libft

fclean:
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all
