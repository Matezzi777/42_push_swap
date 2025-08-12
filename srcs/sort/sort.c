/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:45:01 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:45:18 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	if (stack_size(a) > 3 && !is_sort(a))
		pb(a, &b);
	if (stack_size(a) > 3 && !is_sort(a))
		pb(a, &b);
	while (stack_size(a) > 3 && !is_sort(a))
	{
		update_a(a, &b);
		move_a_to_b(a, &b);
	}
	small_sort(a);
	while (b)
	{
		update_b(a, &b);
		move_b_to_a(a, &b);
	}
}

void	small_sort(t_stack **a)
{
	if (((*a)->value > (*a)->next->value)
		&& ((*a)->value > (*a)->next->next->value))
		ra(a, NULL);
	else if (((*a)->next->value > (*a)->value)
		&& ((*a)->next->value > (*a)->next->next->value))
		rra(a, NULL);
	if ((*a)->value > (*a)->next->value)
		sa(a, NULL);
}
