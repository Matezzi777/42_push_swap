/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:16:33 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:16:34 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_last_value(t_node *stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack->value);
}

void	reverse_rotate(t_node *stack)
{
	int	new_first_value;

	new_first_value = get_last_value(stack);
	while (stack->next)
		stack = stack->next;
	while (stack->prev)
	{
		stack->value = stack->prev->value;
		stack = stack->prev;
	}
	stack->value = new_first_value;
}

void	rra(t_node *a)
{
	ft_printf("rra\n");
	if (!a)
		return ;
	reverse_rotate(a);
}

void	rrb(t_node *b)
{
	ft_printf("rrb\n");
	if (!b)
		return ;
	reverse_rotate(b);
}

void	rrr(t_node *a, t_node *b)
{
	ft_printf("rrr\n");
	if (!a)
		(void)a;
	else
		reverse_rotate(a);
	if (!b)
		(void)b;
	else
		reverse_rotate(b);
}
