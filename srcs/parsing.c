/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:49:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/21 20:26:08 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_bool	doubles_found(t_stack *stack)
{
	
}

static t_stack	*parse_from_string(char *str)
{
	
}

static t_stack	*parse_from_array(char **argv)
{
	
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_list	*stack;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		stack = parse_from_string(argv[1]);
	else
		stack = parse_from_array(argv);
	if (!stack)
		return (NULL);
	if (doubles_found(stack))
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}
