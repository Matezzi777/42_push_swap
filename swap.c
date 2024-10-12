#include "push_swap.h"

void	swap(t_node *stack)
{
	int	temp_value;

	temp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_value;
}

void	ss(t_node *a, t_node *b)
{
	swap(a);
	swap(b);
}