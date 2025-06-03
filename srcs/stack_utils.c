/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:16:43 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/03 16:51:35 by maxmart2         ###   ########.fr       */
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
	Return the node with the biggest value
*/
t_stack	*get_stack_max(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*max;

	max = NULL;
	if (!stack || !(*stack))
		return (NULL);
	cursor = *stack;
	while (cursor)
	{
		if (!max)
			max = cursor;
		else
			if (cursor->value > max->value)
				max = cursor;
		cursor = cursor->next;
	}
	return (max);
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
		free(*stack);
		(*stack) = next;
	}
	return (NULL);
}

void	ft_display_stacks(t_stack **a, t_stack **b)
{
	t_stack	*cursor_a;
	t_stack	*cursor_b;

	if (!a || !(*a))
		cursor_a = NULL;
	else
		cursor_a = *a;
	if (!b || !(*b))
		cursor_b = NULL;
	else
		cursor_b = *b;
	ft_printf("\n	STACK A\nValue	  Adress	Cost	Position	Direction	  Target\n");
	if (!cursor_a)
		ft_printf("EMPTY.\n");
	while (cursor_a)
	{
		if (cursor_a)
		{
			ft_printf("[%d]	%p	 %d	   %d		    %d", cursor_a->value, cursor_a, cursor_a->cost, cursor_a->position, cursor_a->direction);
			if (cursor_a->target)
				ft_printf("		   [%d]\n", cursor_a->target->value);
			else
				ft_printf("		  %p\n", cursor_a->target);
			cursor_a = cursor_a->next;
		}
	}
	ft_printf("\n	STACK B\nValue	  Adress	Cost	Position	Direction	  Target\n");
	if (!cursor_b)
		ft_printf("EMPTY.\n");
	while (cursor_b)
	{
		if (cursor_b)
		{
			ft_printf("[%d]	%p	 %d	   %d		    %d", cursor_b->value, cursor_b, cursor_b->cost, cursor_b->position, cursor_b->direction);
			if (cursor_b->target)
				ft_printf("		  [%d]\n", cursor_b->target->value);
			else
				ft_printf("		  %p\n", cursor_b->target);
			cursor_b = cursor_b->next;
		}
	}
	ft_printf("\n");
}
