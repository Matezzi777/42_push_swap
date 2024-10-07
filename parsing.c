#include "push_swap.h"

void	add_node_bottom(t_node *stack, char *value, int pos)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->pos = pos;
	new_node->value = ft_atoi();
}

void	string_to_stack(t_node *stack, char *string)
{
	int		i;
	char	**arguments;

	arguments = ft_split(string, ' ');
	i = -1;
	while (arguments[++i])
		add_node_bottom(&stack, arguments[i], i);
}