/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:56:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:57:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_stack **stack)
{
	t_stack	*cursor;
	t_stack	*cheapest;

	if (!stack || !(*stack))
		return ;
	cheapest = NULL;
	cursor = *stack;
	while (cursor)
	{
		cursor->cheapest = FALSE;
		if (!cheapest)
			cheapest = cursor;
		else if (cursor->cost < cheapest->cost)
			cheapest = cursor;
		cursor = cursor->next;
	}
	cheapest->cheapest = TRUE;
}
