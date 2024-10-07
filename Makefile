#################### VARIABLES ####################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Ilibft -Imy_printf
RM = rm -rf

NAME = push_swap
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

LIBFT = -Llibft -l:libft.a
PRINTF = -Lmy_printf -l:libftprintf.a

RED = \033[1;31m
LIGHT_GREEN = \033[0;32m
GREEN = \033[1;32m
BLUE = \033[0;34m
CUT = \033[0m

####################   RULES   ####################
#COMPILING RULES
all: $(NAME)

$(NAME): make_libft make_printf $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $@
	@echo "$(GREEN)$(NAME)				[OK]$(CUT)"

make_libft:
	@cd libft && make > /dev/null
	@echo "$(BLUE)LIBFT					$(CUT)$(GREEN)[OK]$(CUT)"

make_printf:
	@cd my_printf && make > /dev/null
	@echo "$(BLUE)FT_PRINTF				$(CUT)$(GREEN)[OK]$(CUT)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

#CLEANING RULES
fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)SO_LONG					$(CUT)$(RED)[DELETE]$(CUT)"

clean: clean_libft clean_printf
	@$(RM) *.o
	@echo "$(BLUE)OBJECTS					$(CUT)$(RED)[DELETE]$(CUT)"

clean_libft:
	@cd libft && make fclean > /dev/null
	@echo "$(BLUE)LIBFT					$(CUT)$(RED)[DELETE]$(CUT)"

clean_printf:
	@cd my_printf && make fclean > /dev/null
	@echo "$(BLUE)FT_PRINTF				$(CUT)$(RED)[DELETE]$(CUT)"

re: fclean all