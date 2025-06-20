/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bring_top.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:56:21 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/20 12:56:57 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	bring_min_top(t_stack **a, t_stack **b)
{
	t_stack	*min;

	define_targets(a, b);
	define_costs(a, b);
	min = get_stack_min(a);
	while (*a != min)
	{
		if (min->direction == UP)
			ra(a, b);
		else
			rra(a, b);
	}
}

void	bring_max_top(t_stack **a, t_stack **b)
{
	t_stack	*max;

	define_targets(a, b);
	define_costs(a, b);
	max = get_stack_max(b);
	while (*b != max)
	{
		if (max->direction == UP)
			rb(a, b);
		else
			rrb(a, b);
	}
}
