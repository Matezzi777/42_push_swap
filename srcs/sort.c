/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:52:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/17 12:25:30 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	bring_min_top(t_stack **a, t_stack **b)
{
	t_stack	*min;

	min = get_stack_min(a);
	while (*a != min)
		ra(a, b);
}

/*
	Sort a stack containing 2 or 3 nodes.
*/
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

/*
	Sort a stack containing 4 to n nodes.
*/
void	sort_stack(t_stack **a, int size)
{
	t_stack	*b;

	(void)size;
	b = NULL;
	pb(a, &b);
	pb(a, &b);
	ft_display_stacks(a, &b);
	while (stack_size(a) > 3 && !is_sorted(a))
	{
		bring_cheapest_top(a, &b);
		pb(a, &b);
	}
	ft_display_stacks(a, &b);
	sort_small_stack(a, stack_size(a));
	ft_display_stacks(a, &b);
	while (b)
		push_to_place(a, &b);
	ft_display_stacks(a, &b);
	bring_min_top(a, &b);
	ft_display_stacks(a, &b);
	// while (b)
	// 	push_to_place(a, &b);
	// ft_display_stacks(a, &b);
	// // Met l'élément le plus petit en haut de a.
}
