/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:04:17 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/07 07:43:34 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Make a reverse rotation on the stack (last item become first)
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
	reverse_rotate(a);
	ft_printf("rra\n");
}

/*
	rrb operation
*/
void	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	reverse_rotate(b);
	ft_printf("rrb\n");
}

/*
	rrr operation
*/
void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
