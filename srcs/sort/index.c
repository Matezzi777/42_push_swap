/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:53:55 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:54:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_index(t_stack **stack)
{
	int		i;
	int		median;
	t_stack	*cursor;

	if (!stack || !(*stack))
		return ;
	median = stack_size(stack) / 2;
	cursor = *stack;
	i = -1;
	while (cursor)
	{
		cursor->index = ++i;
		if (i <= median)
			cursor->above_median = TRUE;
		else
			cursor->above_median = FALSE;
		cursor = cursor->next;
	}
}
