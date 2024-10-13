#include "push_swap.h"

void	reset_pos(t_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

void	push(t_node **dest, t_node **src)
{
	t_node	*temp;

	if (!src)
		return ;
	temp = *dest;
	*dest = *src;
	*src = (*src)->next;
	(*dest)->next = temp;
	reset_pos(*src);
	reset_pos(*dest);
}

void	pa(t_node *a, t_node *b)
{
	ft_printf("pa\n");
	if (!b)
		return ;
	else
		push(&a, &b);
}

void	pb(t_node *a, t_node *b)
{
	ft_printf("pb\n");
	if (!a)
		return ;
	else
		push(&b, &a);
}