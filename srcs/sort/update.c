/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:50:07 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:56:07 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_a(t_stack **a, t_stack **b)
{
	update_index(a);
	update_index(b);
	update_targets_a(a, b);
	update_costs(a, b);
	set_cheapest(a);
}

void	update_b(t_stack **a, t_stack **b)
{
	update_index(a);
	update_index(b);
	update_targets_b(a, b);
}
