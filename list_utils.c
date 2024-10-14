#include "push_swap.h"

int	ft_find_min(t_node *stack)
{
	int	min;

	min = 2147483647;
	while (stack)
	{
		if (stack->value <= min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	ft_find_max(t_node *stack)
{
	int	max;

	max = -2147483648;
	while (stack)
	{
		if (stack->value >= max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	ft_get_index_from_value(t_node *stack, int target)
{
	while (stack)
	{
		if (stack->value == target)
			return (stack->pos);
		stack = stack->next;
	}
	return (-1);
}