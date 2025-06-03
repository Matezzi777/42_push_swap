/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:27:46 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/03 18:38:45 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	define_final_target(t_stack **a, t_stack **b)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;
	t_stack	*target;

	cursor_b = *b;
	while(cursor_b)
	{
		target = NULL;
		cursor_a = *a;
		while(cursor_a)
		{
			if (!target)
				target = cursor_a;
			else
			{
				if (cursor_a->value < cursor_b->value
					&& cursor_a->value > target->value)
					target = cursor_a;
			}
			cursor_a = cursor_a->next;
		}
		cursor_b->target = target;
		cursor_b = cursor_b->next;
	}
}

void	push_to_place(t_stack **a, t_stack **b)
{
	define_final_target(a, b);
	while (*a != (*b)->target)
		ra(a, b);
	pa(a, b);
}
