/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:35:31 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/20 12:58:23 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Swap the 2 first elements of the stack and return the address
	of the new first element.
*/
static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->prev = second;
	second->prev = NULL;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/*
	Execute a swap() on stack a.
*/
void	sa(t_stack **a, t_stack **b)
{
	(void)b;
	swap(a);
	ft_printf("sa\n");
}

/*
	Execute a swap() on stack b.
*/
void	sb(t_stack **a, t_stack **b)
{
	(void)a;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
