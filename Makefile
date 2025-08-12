#################### COMPILING ####################
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -I./includes
LIBFT = ./libft/libft.a
LIBRARIES = -L./libft -lft
RM = rm -rf
NAME = push_swap

###################### FILES ######################
RAW_SRCS = main.c \
			operations/push.c \
			operations/reverse_rotate.c \
			operations/rotate.c \
			operations/swap.c \
			parsing/parsing.c \
			parsing/parsing_utils.c \
			sort/sort.c \
			sort/index.c \
			sort/cost.c \
			sort/target.c \
			sort/update.c \
			sort/rotate_both.c \
			sort/move.c \
			sort/cheapest.c \
			stacks/stack_memory.c \
			stacks/stack_utils.c \
			stacks/more_stack_utils.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

###################### RULES ######################
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBRARIES)

$(LIBFT):
	$(MAKE) -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(MAKE) -C libft fclean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all fclean clean re