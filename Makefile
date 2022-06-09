# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sismaili <sismaili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/22 16:44:56 by sismaili          #+#    #+#              #
#    Updated: 2022/05/08 14:28:45 by sismaili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_split.c \
	ft_strjoin.c \
	is_sorted.c \
	just_sort.c \
	main.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	sort_3_to_10.c \
	sort.c \
	swap.c \
	utils.c \
	check_errors.c \

SRC_BONUS = ft_atoi.c \
		ft_split.c \
		ft_strjoin.c \
		is_sorted.c \
		checker_bonus/push1.c \
		checker_bonus/rev_rotate1.c \
		checker_bonus/rotate1.c \
		checker_bonus/swap1.c \
		check_errors.c \
		checker_bonus/checker.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

NAME = push_swap

NAME_BONUS = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

FT_PRINTF = libftprintf.a

SRC_FT_PRINTF = ft_printf/ft_flags2.c \
			ft_printf/ft_putstr.c \
			ft_printf/ft_hexa.c \
			ft_printf/ft_putchar.c \
			ft_printf/ft_sharp.c \
			ft_printf/ft_memory.c \
			ft_printf/ft_putnbr.c \
			ft_printf/ft_space_plus.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_putnbr_unsigned.c

OBJ_PRINTF = ${SRC_FT_PRINTF:.c=.o}

all : ${NAME}

${FT_PRINTF} : ${OBJ_PRINTF}
	ar rc ${FT_PRINTF} ${OBJ_PRINTF}

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJ} ${FT_PRINTF}
	${CC} ${CFLAGS} ${SRC} ${FT_PRINTF} -o ${NAME}

bonus : ${NAME_BONUS}

${NAME_BONUS} : ${OBJ_BONUS} ${FT_PRINTF}
		${CC} ${CFLAGS} ${SRC_BONUS} ${FT_PRINTF} -o ${NAME_BONUS}

clean :
	${RM} ${OBJ} ${OBJ_PRINTF} ${OBJ_BONUS}

fclean : clean
	${RM} ${NAME} ${NAME_BONUS} ${FT_PRINTF}

re : fclean all

.PHONY : all bonus clean fclean re