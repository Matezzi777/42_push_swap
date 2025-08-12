/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 18:01:38 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 18:20:19 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_max(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*max;

	if (!stack || !*stack)
		return (NULL);
	max = NULL;
	cursor = *stack;
	while (cursor)
	{
		if (!max)
			max = cursor;
		else if (cursor->value > max->value)
			max = cursor;
		cursor = cursor->next;
	}
	return (max);
}

t_stack	*stack_min(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*min;

	if (!stack || !*stack)
		return (NULL);
	min = NULL;
	cursor = *stack;
	while (cursor)
	{
		if (!min)
			min = cursor;
		else if (cursor->value < min->value)
			min = cursor;
		cursor = cursor->next;
	}
	return (min);
}

t_stack	*stack_cheapest(t_stack **stack)
{
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (NULL);
	cursor = *stack;
	while (cursor)
	{
		if (cursor->cheapest)
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}
