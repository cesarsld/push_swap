# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjaimes <cjaimes@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/18 18:36:00 by cjaimes           #+#    #+#              #
#    Updated: 2021/03/15 18:07:03 by cjaimes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SWAP_DIR	=	push_swap_files/

CHECK_DIR	=	checker_files/
				

SRCS		=	${addprefix ${SRC_DIR}, ${SRC}}

OBJS		=	${patsubst ${SRC_DIR}%.c,${OBJ_DIR}%.o,${SRCS}}

NAME		=	push_swap

RM			=	rm -f

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g -O3

T		=	$(words ${OBJS})
N		=	0
C		=	$(words $N)${eval N := X $N}
_CYAN	=	\033[36m
_GREEN	=	\033[32m
ECHO	=	"[`expr $C  '*' 100 / $T`%]"

all:	${NAME}

${NAME}:
	${MAKE} -C ${SWAP_DIR}
	cp ${SWAP_DIR}push_swap push_swap
	${MAKE} -C ${CHECK_DIR}
	cp ${CHECK_DIR}checker checker

run : all
	./${NAME}

bonus: all

clean:
	${MAKE} -C ${SWAP_DIR} clean
	${MAKE} -C ${CHECK_DIR} clean

fclean:	clean
	${RM} push_swap
	${RM} checker
	${MAKE} -C ${SWAP_DIR} fclean
	${MAKE} -C ${CHECK_DIR} fclean

re: fclean all