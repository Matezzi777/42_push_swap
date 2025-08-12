/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:37 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/07 07:43:57 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Make a rotation on the stack (first element become last)
*/
static	void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || (!(*stack)->next))
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

/*
	ra operation
*/
void	ra(t_stack **a, t_stack **b)
{
	(void)b;
	rotate(a);
	ft_printf("ra\n");
}

/*
	rb operation
*/
void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	rotate(b);
	ft_printf("rb\n");
}

/*
	rr operation
*/
void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
