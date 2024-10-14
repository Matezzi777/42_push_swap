/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:38 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:20:39 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_node *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

//	Print le message d'erreur
//		Return : 1
int	print_error(void)
{
	ft_printf("Error\n");
	return (1);
}
