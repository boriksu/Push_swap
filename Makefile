# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/02 17:03:41 by tguillem          #+#    #+#              #
#    Updated: 2020/01/11 14:46:33 by dholiday         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH = ./libft
LIBFT = $(LIBFTPATH)/libft.a

CFLAGS = -Wall -Wextra -Werror -I. -I$(LIBFTPATH) -Iinc -g3
CC = gcc
PUSHSWAP = push_swap
PUSHSWAPSRC =  main_push_swap.c
PUSHSWAPOBJ = $(PUSHSWAPSRC:%.c=%.o)

CHECKER = checker
CHECKERSRC = main_checker.c
CHECKEROBJ = $(CHECKERSRC:%.c=%.o)

SRC_PATH = ./src/

SRC_NAME = initial.c check_sort.c other.c read.c rules_p.c rules_r.c rules_rr.c rules_s.c try_to_sort_q.c \
		help_to_q.c help_second.c help_to_separate_a.c
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ = $(SRC:%.c=%.o)

NAME = $(LIBFT) $(CHECKER) $(PUSHSWAP)

all: $(NAME)

$(OBJ) : ./push_swap.h

$(LIBFT) :
	make -C $(LIBFTPATH)

$(CHECKER): $(LIBFT) $(OBJ) $(CHECKEROBJ)
	gcc $(CFLAGS) $(OBJ) $(CHECKEROBJ) $(LIBFT) -o $(CHECKER)

$(PUSHSWAP): $(LIBFT) $(OBJ) $(PUSHSWAPOBJ)
	gcc $(CFLAGS) $(OBJ) $(PUSHSWAPOBJ) $(LIBFT) -o $(PUSHSWAP)

clean:
	make clean -C $(LIBFTPATH)
	rm -f $(OBJ) $(PUSHSWAPOBJ) $(CHECKEROBJ)

fclean: clean
	make fclean -C $(LIBFTPATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
