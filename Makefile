NAME_PS = push_swap

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft_src/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)


HEADERS_LIST = push_swap.h
HEADERS_DIRECTORY = ./inc/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./src/
SOURCES_LIST = 	main.c					parse_many_in_one.c			parse_one_at_time.c 	\
				parse_utils.c			sort_arr.c					work_with_stack.c 		\
				ft_atoi_mod.c			instruction_push.c			instruction_rotate.c 	\
				instruction_reverse.c	sort_five.c					sort_big.c 				\
				sort_optima.c			sort_some.c					instruction_swap.c


SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))
OBJECTS_DIRECTORY = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

.PHONY: all clean fclean re

all: $(NAME_PS)

$(NAME_PS): $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME_PS)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_PS)

re:
	$(MAKE) fclean
	$(MAKE) all