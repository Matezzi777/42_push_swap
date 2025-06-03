/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:32:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/03 15:42:23 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	define_node_cost(t_stack *node, t_stack **stack)
{
	int	size;

	if (node->direction == NONE)
		node->cost = 0;
	else if (node->direction == UP)
		node->cost = node->position - 1;
	else
	{
		size = stack_size(stack);
		node->cost = size - node->position + 1;
	}
}

static void	define_stack_costs(t_stack **stack)
{
	t_stack	*cursor;

	cursor = *stack;
	while (cursor)
	{
		define_node_cost(cursor, stack);
		cursor = cursor->next;
	}
}

static void	define_directions(t_stack **stack)
{
	int		i;
	int		size;
	t_stack	*cursor;

	size = stack_size(stack);
	cursor = *stack;
	i = 0;
	while (cursor)
	{
		if (i == 0)
			cursor->direction = NONE;
		else if (i <= size / 2)
			cursor->direction = UP;
		else
			cursor->direction = DOWN;
		cursor = cursor->next;
		i++;
	}
}

void	define_positions(t_stack **stack)
{
	int		i;
	t_stack	*cursor;

	i = 1;
	cursor = *stack;
	while (cursor)
	{
		cursor->position = i;
		cursor = cursor->next;
		i++;
	}
}

void	define_costs(t_stack **a, t_stack **b)
{
	define_directions(a);
	define_directions(b);
	define_positions(a);
	define_positions(b);
	define_stack_costs(a);
	define_stack_costs(b);
}
