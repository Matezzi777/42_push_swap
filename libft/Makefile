#################### VARIABLES ####################
#COMPILING
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = libft.a
#SOURCES
DIR_SRCS = srcs/
SRCS = 	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_itoa.c \
		ft_memcmp.c \
		ft_memchr.c \
		ft_split.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strnstr.c \
		ft_strrchr.c
#OBJECTS
OBJS = $(SRCS:.c=.o)
#COLORS
RED = \033[1;31m
LIGHT_GREEN = \033[0;32m
GREEN = \033[1;32m
BLUE = \033[0;34m
CUT = \033[0m

###################### RULES ######################
all: $(NAME)
$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$@				[OK]$(CUT)"
%.o : $(DIR_SRCS)/%.c
	@$(CC) $(CCFLAGS) -c $< -I./ -o $@
	@echo "$(BLUE)$@			$(CUT)$(GREEN)[OK]$(CUT)"
fclean : clean
	@$(RM) $(NAME)
	@echo "$(BLUE)$(NAME)				$(CUT)$(RED)[DELETE]$(CUT)"
clean :
	@$(RM) *.o
	@echo "$(BLUE)OBJECTS				$(CUT)$(RED)[DELETE]$(CUT)"
re : fclean all