#include "push_swap.h"

void	rotate(t_node *stack)
{
	int	new_last_value;

	new_last_value = stack->value;
	while (stack->next)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = new_last_value;
}

void	ra(t_node *a)
{
	ft_printf("ra\n");
	if (!a)
		return ;
	rotate(a);
}

void	rb(t_node *b)
{
	ft_printf("rb\n");
	if (!b)
		return ;
	rotate(b);
}

void	rr(t_node *a, t_node *b)
{
	ft_printf("rr\n");
	if (!a)
		(void)a;
	else
		rotate(a);
	if (!b)
		(void)b;
	else
		rotate(b);
}