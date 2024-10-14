/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:26:21 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:27:17 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
			ETAT ACTUEL
	- Parsing	:	OK
	- Tri		:	En cours...
*/

//Trie la stack passée (coeur du programme)
// static void	ft_sort(t_node *a)
// {
// 	t_node	*b;

// 	b = NULL;
// }

void	dump_stack(t_node *stack, char name)
{
	t_node	*current;

	ft_printf("%c :	", name);
	current = stack;
	if (!current)
	{
		ft_printf("Empty.\n");
		return ;
	}
	while (current)
	{
		ft_printf("[%d] ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}

void	dump_both_stacks(t_node *a, t_node *b)
{
	dump_stack(a, 'A');
	dump_stack(b, 'B');
}

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = ft_parse_arguments(argc, argv);
	if (!a)
		return (1);
	b = NULL;
	ft_printf("\n=============================================\n");
	dump_both_stacks(a, b);
	// == TESTS ==
	sa(a);
	sb(b);
	dump_both_stacks(a, b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	dump_both_stacks(a, b);
	ra(a);
	rb(b);
	dump_both_stacks(a, b);
	rra(a);
	rrb(b);
	dump_both_stacks(a, b);
	sa(a);
	dump_both_stacks(a, b);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	// ===========
	dump_both_stacks(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
}
