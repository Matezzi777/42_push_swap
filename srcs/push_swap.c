/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 02:32:57 by maxmart2          #+#    #+#             */
/*   Updated: 2025/06/20 09:32:16 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	The core of the program.
*/
int	main(int argc, char **argv)
{
	int		size;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		return (0);
	}
	size = stack_size(&stack_a);
	// ft_display_stacks(&stack_a, NULL);
	if (is_sorted(&stack_a))
	{
		ft_printf("Already sort\n");
		free_stack(&stack_a);
		return (0);
	}
	else if (size <= 3)
		sort_small_stack(&stack_a, size);
	else
		sort_stack(&stack_a, size);
	free_stack(&stack_a);
}
