# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falarm <falarm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/27 16:20:27 by falarm            #+#    #+#              #
#    Updated: 2022/06/27 18:25:47 by falarm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker

SRCS	=	src/main.c					src/parse_many_in_one.c			src/parse_one_at_time.c 	\
			src/parse_utils.c			src/sort_arr.c					src/work_with_stack.c 		\
			src/ft_atoi_mod.c			src/instruction_push.c			src/instruction_rotate.c 	\
			src/instruction_reverse.c	src/sort_five.c					src/sort_move.c 			\
			src/sort_five_second.c		src/sort_some.c					src/instruction_swap.c

SRCS_B	=	src/instruction_swap.c		src/parse_many_in_one.c			src/parse_one_at_time.c 	\
			src/parse_utils.c			src/sort_arr.c					src/work_with_stack.c 		\
			src/ft_atoi_mod.c			src/instruction_push.c			src/instruction_rotate.c 	\
			src/instruction_reverse.c	src/checker.c					src/checker_utils.c

OBJ		=	$(SRCS:%.c=%.o)

OBJ_B	=	$(SRCS_B:%.c=%.o)

LIB		=	libft_src/libft.a

INCLUDE	=	inc/

HEADER	=	push_swap.h

CC		=	gcc

FLAGS	=	-Wall -Wextra -Werror

RM		= rm -rf


.PHONY:		all	clean	fclean	re	bonus	libft

all:		libft $(NAME)

libft:
			@$(MAKE) -C libft_src/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

%.o:		%.c $(INCLUDE)$(HEADER)
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)

bonus:		libft $(OBJ_B)
			$(CC) $(FLAGS) $(OBJ_B) $(LIB) -o $(NAME_B)

clean:
			@$(RM) $(OBJ) $(OBJ_B)
			@$(MAKE) -C libft_src/ clean

fclean:		clean
			@$(MAKE) -C libft_src/ fclean
			@$(RM) $(NAME) $(NAME_B)

re:			fclean all
