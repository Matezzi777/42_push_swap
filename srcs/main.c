/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:11:48 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:36:33 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = parse_arguments(argc, argv);
	if (!a)
		return (ft_putstr_fd("Error\n", STDERR), 0);
	if (!is_sort(&a))
	{
		if (stack_size(&a) == 2)
			sa(&a, NULL);
		else if (stack_size(&a) == 3)
			small_sort(&a);
		else
			sort(&a);
	}
	min_on_top(&a);
	free_stack(&a);
	return (0);
}
