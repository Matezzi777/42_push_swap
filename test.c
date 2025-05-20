/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:15:45 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/20 16:13:23 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*cursor;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 3)
		ft_printf("Not enough arguments passed.\n Minimum 2 arguments needed.\n");
	else
	{
		stack_a = create_node(ft_atoi(argv[1]));
		stack_b = create_node(ft_atoi(argv[1]));
		i = 1;
		while (++i < argc)
		{
			if (!add_stack_elem(&stack_a, create_node(ft_atoi(argv[i]))))
			{
				ft_printf("An error occured while adding an element to stack a.\n");
				return (0);
			}
			if (!add_stack_elem(&stack_b, create_node(ft_atoi(argv[i]))))
			{
				ft_printf("An error occured while adding an element to stack b.\n");
				return (0);
			}
		}
		ft_printf("STACK A : [%d]", stack_a->value);
		cursor = stack_a->next;
		while (cursor)
		{
			ft_printf(" -> [%d]", cursor->value);
			cursor = cursor->next;
		}
		ft_printf("\nSTACK B : [%d]", stack_b->value);
		cursor = stack_b->next;
		while (cursor)
		{
			ft_printf(" -> [%d]", cursor->value);
			cursor = cursor->next;
		}
		ft_printf("\n");
		rr(&stack_a, &stack_b);
		rrr(&stack_a, &stack_b);
		if (!stack_a)
			ft_printf("STACK A : EMPTY");
		else
		{
			ft_printf("STACK A : [%d]", stack_a->value);
			cursor = stack_a->next;
			while (cursor)
			{
				ft_printf(" -> [%d]", cursor->value);
				cursor = cursor->next;
			}
		}
		if (!stack_b)
			ft_printf("STACK B : EMPTY");
		else
		{
			ft_printf("\nSTACK B : [%d]", stack_b->value);
			cursor = stack_b->next;
			while (cursor)
			{
				ft_printf(" -> [%d]", cursor->value);
				cursor = cursor->next;
			}
		}
	}
}