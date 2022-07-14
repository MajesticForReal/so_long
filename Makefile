# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 14:54:09 by anrechai          #+#    #+#              #
#    Updated: 2022/06/27 15:00:44 by anrechai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c gnl.c check_line.c img.c map.c move.c parsing.c utils.c utils2.c

OBJS		=	${SRCS:.c=.o}

NAME		=	so_long

CFLAGS		=	-Wall -Wextra -Werror -g3

CC			=	cc

MLX			=	-ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

HEADER		=	so_long.h

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I./

$(NAME):	${OBJS}
			$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME) -L.

all:		$(NAME)

clean:
			rm -f ${OBJS}
			@echo "\033[92mstatus $@ is [OK]\033[0m"

fclean:		clean
			rm -f ${NAME}
			@echo "\033[92mstatus $@ [OK]\033[0m"

re:			fclean all

.PHONY:		fclean clean re all
