/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:59:27 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:59:57 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!a || !(*a) || !b || !(*b))
		return ;
	while (*a != cheapest && *b != cheapest->target)
		rr(a, b);
	update_index(a);
	update_index(b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (!a || !(*a) || !b || !(*b))
		return ;
	while (*a != cheapest && *b != cheapest->target)
		rrr(a, b);
	update_index(a);
	update_index(b);
}
