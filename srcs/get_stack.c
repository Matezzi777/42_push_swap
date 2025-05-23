/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 01:19:58 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:36:04 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Convert the single string argument given to a stack.
	The string given is considered as valid.
	Return NULL if an error occured during stack creation.
	Example : 
		"1 5 45 -8" become :
			NULL <- [1] <-> [5] <-> [45] <-> [-8] -> NULL
*/
t_stack	*get_stack_from_string(char *str)
{
	int		i;
	t_stack	*stack;
	t_stack	*node;

	stack = create_node(ft_atol(str));
	if (!stack)
		return (NULL);
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i])
		{
			node = create_node(ft_atol(&str[i]));
			if (!node)
				return (free_stack(&stack));
			add_stack_elem(&stack, node);
		}
	}
	return (stack);
}
