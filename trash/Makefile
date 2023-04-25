# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 14:43:46 by snemoto           #+#    #+#              #
#    Updated: 2023/03/21 17:53:51 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP_SRCS	= \
			main.c \
			ps_atoi.c \
			ps_lst_actions.c \
			ps_lst_check.c \
			ps_lst_make.c \
			ps_operations.c \
			ps_sort_large.c \
			ps_sort_small.c \
			checker.c

CC		= cc
# CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -I include
CFLAGS	= -Wall -Wextra -Werror -I include
RM		= rm -f
NAME	= push_swap
SRCS	= ${PUSHSWAP_SRCS}
OBJS	= ${PUSHSWAP_SRCS:.c=.o}
LIBFT_PATH = libft
LIBFT_INCLUDE = libft.a
LIBFTPRINTF_PATH = printf
LIBFTPRINTF_INCLUDE = libftprintf.a

$(NAME): ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make bonus
		cd "$(PWD)/${LIBFTPRINTF_PATH}" && make bonus
		${CC} ${CFLAGS} \
			$(PWD)/${LIBFT_PATH}/${LIBFT_INCLUDE} \
			$(PWD)/${LIBFTPRINTF_PATH}/${LIBFTPRINTF_INCLUDE} \
			${SRCS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make fclean
		cd "$(PWD)/${LIBFTPRINTF_PATH}" && make fclean

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus
