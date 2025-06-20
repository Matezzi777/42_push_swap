/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:27:46 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/20 09:46:22 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*get_stack_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (NULL);
	min = NULL;
	cursor = *stack;
	while (cursor)
	{
		if (!min)
			min = cursor;
		else
		{
			if (cursor->value < min->value)
				min = cursor;
		}
		cursor = cursor->next;
	}
	return (min);
}

static void	define_node_finale_target(t_stack *node, t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*target;

	target = NULL;
	cursor = *stack;
	while (cursor)
	{
		if (cursor->value > node->value)
		{
			if (!target)
				target = cursor;
			else
				if (cursor->value < target->value)
					target = cursor;
		}
		cursor = cursor->next;
	}
	if (!target)
		target = get_stack_min(stack);
	node->target = target;
}


static void	define_final_targets(t_stack **a, t_stack **b)
{
	t_stack	*cursor;

	if (!a || !(*a) || !b || !(*b))
		return ;
	cursor = *a;
	while (cursor)
	{
		define_node_finale_target(cursor, b);
		cursor = cursor->next;
	}
	cursor = *b;
	while (cursor)
	{
		define_node_finale_target(cursor, a);
		cursor = cursor->next;
	}
}

void	push_to_place(t_stack **a, t_stack **b)
{
	define_final_targets(a, b);
	while (*a != (*b)->target)
	{
		if ((*b)->target->direction == UP)
			ra(a, b);
		else
			rra(a, b);
	}
	pa(a, b);
}
