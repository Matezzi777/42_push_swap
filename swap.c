#include "push_swap.h"

static void	swap(t_node *stack)
{
	int	temp_value;

	temp_value = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp_value;
}
void	sa(t_node *a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_node *b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_node *a, t_node *b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}