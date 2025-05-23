/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:04:17 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:47:18 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Make a reverse rotation on the stack (first item become last)
*/
static void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
}

/*
	rra operation
*/
void	rra(t_stack **a, t_stack **b)
{
	(void)b;
	ft_printf("rra\n");
	reverse_rotate(a);
}

/*
	rrb operation
*/
void	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	ft_printf("rrb\n");
	reverse_rotate(b);
}

/*
	rrr operation
*/
void	rrr(t_stack **a, t_stack **b)
{
	ft_printf("rrr\n");
	reverse_rotate(a);
	reverse_rotate(b);
}
