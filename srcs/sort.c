/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:52:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 06:46:08 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// 1 2 3 None
// 1 3 2 ra + sa
// 2 1 3 sa
// 2 3 1 ra
// 3 1 2 rra
// 3 2 1 rra + sa
void	sort_small_stack(t_stack **a, int size)
{
	long	x;
	long	y;
	long	z;
	if (size == 2)
		return (sa(a, NULL));
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && x < z)
		return (sa(a, NULL));
	if (x < y && x > z)
		return (rra(a, NULL));
	if (x > z && y < z)
		return (ra(a, NULL));
	if (x < y && y > z)
		rra(a, NULL);
	else
		ra(a, NULL);
	return (sa(a, NULL));
	
}

void	sort_stack(t_stack **a, t_stack **b, int size)
{
	(void)a;
	(void)b;
	(void)size;
	return ;
}
