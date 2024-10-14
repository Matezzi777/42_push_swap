/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:26:21 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 21:09:33 by mmartina         ###   ########.fr       */
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

//MAIN
int	main(int argc, char **argv)
{
	t_node	*a;

	a = ft_parse_arguments(argc, argv);
	if (a)
	{
		dump_stack(a, 'A');
		ft_printf("\n");
		ft_sort(a);
		ft_printf("\n");
		dump_stack(a, 'A');
	}
	ft_free_stack(a);
}
