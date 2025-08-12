/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:54:59 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:56:02 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_costs(t_stack **a, t_stack **b)
{
	int		size_a;
	int		size_b;
	t_stack	*cursor;

	if (!a || !(*a) || !b || !(*b))
		return ;
	size_a = stack_size(a);
	size_b = stack_size(b);
	cursor = *a;
	while (cursor)
	{
		if (cursor->above_median)
			cursor->cost = cursor->index;
		else
			cursor->cost = size_a - cursor->index;
		if (cursor->target->above_median)
			cursor->cost += cursor->target->index;
		else
			cursor->cost += size_b - cursor->target->index;
		cursor = cursor->next;
	}
}
