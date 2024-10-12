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
//populate_stack.c
t_node	*populate_stack(char **argv, bool skip_first);
//utils.c
void	ft_free_stack(t_node *stack);
int		print_error(void);
//swap.c
void	swap(t_node *stack);
void	ss(t_node *a, t_node *b);
//push.c
void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);
//rotate.c
void	rotate(t_node *stack);
void	rr(t_node *a, t_node *b);
//reverse_rotate.c
void	reverse_rotate(t_node *stack);
void	rrr(t_node *a, t_node *b);

#endif