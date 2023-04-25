# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 14:43:46 by snemoto           #+#    #+#              #
#    Updated: 2023/04/24 21:09:04 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHSWAP_SRCS	= \
			main.c \
			ps_atoi.c \
			ps_lst_actions.c \
			ps_lst_check.c \
			ps_lst_make.c \
			ps_lst_rank.c \
			ps_operations.c \
			ps_sort_a.c \
			ps_sort_b.c \
			ps_sort_large.c \
			ps_sort_small.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I include
RM		= rm -f
NAME	= push_swap
SRCS	= ${PUSHSWAP_SRCS}
OBJS	= ${PUSHSWAP_SRCS:.c=.o}
LIBFT_PATH = libft
LIBFT_INCLUDE = libft.a

$(NAME): ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make bonus
		${CC} ${CFLAGS} \
			$(PWD)/${LIBFT_PATH}/${LIBFT_INCLUDE} \
			${SRCS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}
		cd "$(PWD)/${LIBFT_PATH}" && make fclean

fclean:	clean
		${RM} ${NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus
