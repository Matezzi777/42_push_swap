/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:16:43 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:50:24 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Create and initialize a new stack node.
*/
t_stack	*create_node(long value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->cost = -1;
	node->position = -1;
	node->direction = NONE;
	node->target = NULL;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

/*
	Add a node to the end of the stack.
*/
t_bool	add_stack_elem(t_stack **stack, t_stack *node)
{
	t_stack	*cursor;

	if (!stack || !(*stack) || !node)
		return (FALSE);
	cursor = *stack;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = node;
	node->prev = cursor;
	return (TRUE);
}

/*
	Return the number of nodes contained in the stack.
*/
int	stack_size(t_stack **stack)
{
	int		count;
	t_stack	*cursor;

	if (!stack || !(*stack))
		return (0);
	cursor = *stack;
	count = 1;
	while (cursor->next)
	{
		cursor = cursor->next;
		count++;
	}
	return (count);
}

/*
	Free all the memory allocated for the stack.
*/
t_stack	*free_stack(t_stack **stack)
{
	t_stack	*next;

	if (!stack)
		return (NULL);
	while (*stack)
	{
		next = (*stack)->next;
		ft_printf("Block [%d] freed!\n", (int)((*stack)->value));
		free(*stack);
		(*stack) = next;
	}
	return (NULL);
}
