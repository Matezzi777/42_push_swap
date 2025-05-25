/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 05:52:30 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/25 03:13:06 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
	while (stack_size(a) > 3 && !is_sorted(a))
	{
		// Définit la cible de chaque élément.
		// Calcule le coût de chaque élément.
		// Effectue les mouvements nécessaires pour placer l'élément
		// 	le moins cher de a à sa place dans b.
	}
	sort_small_stack(a, stack_size(a));
	while (stack_size(&b) > 0)
	{
		// Pousse l'élément en haut de b à sa place dans a.
	}
	// Met l'élément le plus petit en haut de a.
	ft_display_stacks(a, &b);
}
