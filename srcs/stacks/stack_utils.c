/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:38:24 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/12 10:48:11 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **stack)
{
	int		i;
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (0);
	cursor = *stack;
	i = 0;
	while (cursor)
	{
		i++;
		cursor = cursor->next;
	}
	return (i);
}

t_bool	is_sort(t_stack **stack)
{
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (FALSE);
	cursor = *stack;
	while (cursor->next)
	{
		if (cursor->value > cursor->next->value)
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}

void	min_on_top(t_stack **a)
{
	t_stack	*min;

	update_index(a);
	min = stack_min(a);
	while ((*a)->value != min->value)
	{
		if (min->above_median)
			ra(a, NULL);
		else
			rra(a, NULL);
	}
}
