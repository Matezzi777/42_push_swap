/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:47:37 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:48:32 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Make a rotation on the stack (last element become first)
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
	ft_printf("ra\n");
	rotate(a);
}

/*
	rb operation
*/
void	rb(t_stack **a, t_stack **b)
{
	(void)a;
	ft_printf("rb\n");
	rotate(b);
}

/*
	rr operation
*/
void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
