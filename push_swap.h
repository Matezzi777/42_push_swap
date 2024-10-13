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
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);
//push.c
void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);
//rotate.c
void	ra(t_node *a);
void	rb(t_node *b);
void	rr(t_node *a, t_node *b);
//reverse_rotate.c
void	rra(t_node *a);
void	rrb(t_node *b);
void	rrr(t_node *a, t_node *b);

#endif