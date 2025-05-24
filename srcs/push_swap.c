/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:32:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 04:04:47 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	The core of the program.
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*cursor;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (0);
	}
	cursor = stack_a;
	while (cursor)
	{
		ft_printf("[%d] -> ", (int)(cursor->value));
		cursor = cursor->next;
	}
	ft_printf("\n");
	(void)stack_b;
	free_stack(&stack_a);
}
