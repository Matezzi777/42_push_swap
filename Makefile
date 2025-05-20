############################### COMMANDS ##############################
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I:includes
LIBFT = -L./libft -lft
RM = rm -f
NAME = push_swap

##############################   FILES   ##############################
RAW_SRCS = push_swap.c
SRCS = $(addprefix srcs/, $(RAW_SRCS))
OBJS = $(SRCS:.c=.o)

##############################   RULES   ##############################
all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

libft:
	cd libft && make

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	cd libft && make fclean
	$(RM) $(OBJS)

re: fclean all

.PHONY: all libft fclean clean re