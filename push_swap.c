/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:26:21 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/17 01:09:43 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
			ETAT ACTUEL
	- Parsing	:	OK
	- Tri		:	small_sort()	OK
					big_sort()		En cours..
*/

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = ft_parse_arguments(argc, argv);
	b = NULL;
	dump_both_stacks(a, b);
	ft_printf("\n");
	if (a)
	{
		// ft_sort(a);
		pb(&a, &b);
		ft_printf("\n");
		dump_both_stacks(a, b);
		ft_printf("\n");
		// ra(a);
		sa(a);
	}
	ft_printf("\n");
	dump_both_stacks(a, b);
	ft_free_stack(go_to_top(a));
	ft_free_stack(go_to_top(b));
}
