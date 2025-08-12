/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:38:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:39:18 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(long value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->cost = -1;
	node->above_median = FALSE;
	node->cheapest = FALSE;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

t_bool	add_stack_elem(t_stack **stack, t_stack *node)
{
	t_stack	*cursor;

	if (!stack || !node)
		return (FALSE);
	if (!(*stack))
		*stack = node;
	else
	{
		cursor = *stack;
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = node;
		node->prev = cursor;
	}
	return (TRUE);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		(*stack) = next;
	}
}
