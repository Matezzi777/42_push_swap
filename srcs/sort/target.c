/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:57:26 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 18:20:49 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_targets_a(t_stack **a, t_stack **b)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	if (!a || !(*a) || !b || !(*b))
		return ;
	cursor_a = *a;
	while (cursor_a)
	{
		cursor_a->target = NULL;
		cursor_b = *b;
		while (cursor_b)
		{
			if (cursor_b->value < cursor_a->value && !(cursor_a->target))
				cursor_a->target = cursor_b;
			else if (cursor_b->value < cursor_a->value
				&& cursor_b->value > cursor_a->target->value)
				cursor_a->target = cursor_b;
			cursor_b = cursor_b->next;
		}
		if (!(cursor_a->target))
			cursor_a->target = stack_max(b);
		cursor_a = cursor_a->next;
	}
}

void	update_targets_b(t_stack **a, t_stack **b)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	if (!a || !(*a) || !b || !(*b))
		return ;
	cursor_b = *b;
	while (cursor_b)
	{
		cursor_b->target = NULL;
		cursor_a = *a;
		while (cursor_a)
		{
			if (cursor_a->value > cursor_b->value && !(cursor_b->target))
				cursor_b->target = cursor_a;
			else if (cursor_a->value > cursor_b->value
				&& cursor_a->value < cursor_b->target->value)
				cursor_b->target = cursor_a;
			cursor_a = cursor_a->next;
		}
		if (!(cursor_b->target))
			cursor_b->target = stack_min(a);
		cursor_b = cursor_b->next;
	}
}
