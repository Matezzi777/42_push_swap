/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 06:00:00 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/25 02:45:10 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Check if a stack is sorted.
*/
t_bool	is_sorted(t_stack **stack)
{
	int		size;
	t_stack	*cursor;

	size = stack_size(stack);
	if (size == 0)
		return (FALSE);
	if (size == 1)
		return (TRUE);
	cursor = *stack;
	while (cursor->next)
	{
		if (cursor->value > cursor->next->value)
			return (FALSE);
		cursor = cursor->next;
	}
	return (TRUE);
}
