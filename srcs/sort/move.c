/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:58:21 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:59:03 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	prep_for_push_a(t_stack **a, t_stack *cheapest)
{
	if (!a || !(*a) || !cheapest || *a == cheapest)
		return ;
	while (*a != cheapest)
	{
		if (cheapest->above_median)
			ra(a, NULL);
		else
			rra(a, NULL);
	}
}

static void	prep_for_push_b(t_stack **b, t_stack *target)
{
	if (!b || !(*b) || !target || *b == target)
		return ;
	while (*b != target)
	{
		if (target->above_median)
			rb(NULL, b);
		else
			rrb(NULL, b);
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = stack_cheapest(a);
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target->above_median))
		rev_rotate_both(a, b, cheapest);
	prep_for_push_a(a, cheapest);
	prep_for_push_b(b, cheapest->target);
	pb(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push_a(a, (*b)->target);
	pa(a, b);
}
