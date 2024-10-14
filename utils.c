/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:20:38 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 18:25:42 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
