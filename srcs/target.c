/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 02:12:13 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/03 17:27:57 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// La cible est la valeur inférieur la plus proche ou la valeur
// la plus grande si la node devient la nouvelle plus petite.
static void	define_node_target(t_stack *node, t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*target;

	target = NULL;
	cursor = *stack;
	while (cursor)
	{
		if (cursor->value < node->value)
		{
			if (!target)
				target = cursor;
			else
				if (cursor->value > target->value)
					target = cursor;
		}
		cursor = cursor->next;
	}
	if (!target)
		target = get_stack_max(stack);
	node->target = target;
}

void	define_targets(t_stack **a, t_stack **b)
{
	t_stack	*cursor;

	if (!a || !(*a) || !b || !(*b))
		return ;
	cursor = *a;
	while (cursor)
	{
		define_node_target(cursor, b);
		cursor = cursor->next;
	}
	cursor = *b;
	while (cursor)
	{
		define_node_target(cursor, a);
		cursor = cursor->next;
	}
}
