#ifndef PUSH_SWAP
# define PUSH_SWAP

# include "libft/libft.h"
# include "my_printf/ft_printf.h"
# include <stdbool.h>

//Structure élément de stack
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
	int				pos;
}			t_node;

//parsing.c
t_node	*ft_parse_arguments(int argc, char **argv);
//utils.c
int		print_error(void);

#endif