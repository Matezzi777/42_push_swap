/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:18:08 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:18:09 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_pos(t_node *stack)
{
	int	i;

	i = -1;
	while (stack)
	{
		stack->pos = ++i;
		stack = stack->next;
	}
	return ;
}

static void	push(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	(*a)->prev = NULL;
}

void	pa(t_node **a, t_node **b)
{
	ft_printf("pa\n");
	if (!b)
		return ;
	else
		push(a, b);
	update_pos(*a);
	update_pos(*b);
}

void	pb(t_node **a, t_node **b)
{
	ft_printf("pb\n");
	if (!a)
		return ;
	else
		push(b, a);
	update_pos(*a);
	update_pos(*b);
}
