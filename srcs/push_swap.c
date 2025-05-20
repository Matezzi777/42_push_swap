/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:32:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/20 02:46:51 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return ;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
		ft_printf("PARSING ERROR.\n");
		return ;
	}
	stack_b = NULL;
	while (TRUE)
	{
		if (is_sort(stack_a))
			break ;
		make_action(&stack_a, &stack_b);
	}
}