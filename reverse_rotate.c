#include "push_swap.h"

int		get_last_value(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->value);
}

void	reverse_rotate(t_node *stack)
{
	int	new_first_value;

	new_first_value = get_last_value(stack);
	while (stack->next)
		stack = stack->next;
	while (stack->prev)
	{
		stack->value = stack->prev->value;
		stack = stack->prev;
	}
	stack->value = new_first_value;
}

void	rra(t_node *a)
{
	ft_printf("rra\n");
	reverse_rotate(a);
}

void	rrb(t_node *b)
{
	ft_printf("rrb\n");
	reverse_rotate(b);
	
}

void	rrr(t_node *a, t_node *b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}