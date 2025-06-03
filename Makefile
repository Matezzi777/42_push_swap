############################### COMMANDS ##############################
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes
LIBFT = -L./libft -l:libft.a
RM = rm -f
NAME = push_swap

##############################   FILES   ##############################
RAW_SRCS = push_swap.c \
			push.c \
			swap.c \
			rotate.c \
			reverse_rotate.c \
			stack_utils.c \
			parsing.c \
			parsing_utils.c \
			sort.c \
			verif.c \
			target.c \
			cost.c \
			move.c \
			final_push.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

##############################   RULES   ##############################
all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LIBFT)

libft:
	cd libft && make bonus

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	cd libft && make fclean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all libft fclean clean re