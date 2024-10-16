/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:52 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/15 16:31:11 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_init_stack(int value)
{
	t_node	*stack;

	stack = (t_node *)malloc(sizeof(t_node));
	if (!stack)
		return (NULL);
	stack->prev = NULL;
	stack->pos = 0;
	stack->value = value;
	stack->next = NULL;
	return (stack);
}

bool	ft_add_node(t_node *stack, int value)
{
	t_node	*node;

	while (stack->next != NULL)
		stack = stack->next;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (false);
	stack->next = node;
	node->prev = stack;
	node->pos = stack->pos + 1;
	node->value = value;
	node->next = NULL;
	node->target = NULL;
	node->cost = -1;
	node->min = false;
	node->max = false;
	node->direction = false;
	return (true);
}

//Remplit une stack avec les arguments fournis
t_node	*populate_stack(char **argv, bool skip_first)
{
	t_node	*stack;
	int		i;

	i = 0;
	if (skip_first)
		i++;
	stack = ft_init_stack(ft_atoi(argv[i]));
	if (!stack)
		return (NULL);
	while (argv[++i])
	{
		if (!ft_add_node(stack, ft_atoi(argv[i])))
		{
			ft_free_stack(stack);
			print_error();
			return (NULL);
		}
	}
	return (stack);
}
