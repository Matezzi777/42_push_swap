/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 16:27:09 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/03 18:22:28 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static long	biggest(long a, long b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static t_stack *find_cheapest(t_stack **a)
{
	int		cost;
	t_stack	*cursor;
	t_stack	*cheapest;

	if (!a || !(*a))
		return NULL;
	cheapest = NULL;
	cursor = *a;
	while (cursor)
	{
		if (!cheapest)
			cheapest = cursor;
		else
		{
			if (cursor->direction == cursor->target->direction)
				cost = biggest(cursor->cost, cursor->target->cost);
			else
				cost = cursor->cost + cursor->target->cost;
			if (cost < cheapest->cost + cheapest->target->cost)
				cheapest = cursor;
		}
		cursor = cursor->next;
	}
	// ft_printf("cheapest = [%d]	dir:%d	target_dir:%d	cost:%d	target_cost:%d\n", cheapest->value, cheapest->direction, cheapest->target->direction, cheapest->cost, cheapest->target->cost);
	return (cheapest);
}

static void	make_logic_move(t_stack *cheapest, t_stack **a, t_stack **b)
{
	if (cheapest->direction == cheapest->target->direction)
	{
		if (cheapest->direction == UP)
			rr(a, b);
		else if (cheapest->direction == DOWN)
			rrr(a, b);
	}
	else
	{
		if (cheapest->direction == UP)
			ra(a, b);
		else if (cheapest->direction == DOWN)
			rra(a, b);
		if (cheapest->target->direction == UP)
			rb(a, b);
		else if (cheapest->target->direction == DOWN)
			rrb(a, b);
	}
}

void	bring_cheapest_top(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	
	define_targets(a, b);
	define_costs(a, b);
	cheapest = find_cheapest(a);
	while (cheapest != *a || cheapest->target != *b)
	{
		make_logic_move(cheapest, a, b);
		define_targets(a, b);
		define_costs(a, b);
		cheapest = find_cheapest(a);
	}
}
