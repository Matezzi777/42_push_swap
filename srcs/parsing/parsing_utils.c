/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:32:54 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:33:16 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		if (str[i])
		{
			node = create_node(ft_atol(&str[i]));
			if (!node)
				return (free_stack(&stack), NULL);
			add_stack_elem(&stack, node);
		}
	}
	return (stack);
}

static t_bool	overflow_detected_from_chars(char *str)
{
	int	i;
	int	nb_digits;

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '+' || str[i] == '-')
			i++;
		nb_digits = 0;
		while (ft_isdigit(str[i]))
		{
			nb_digits++;
			i++;
		}
		if (nb_digits > 10)
			return (TRUE);
	}
	return (FALSE);
}

t_bool	overflow_detected(t_stack *stack, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (overflow_detected_from_chars(argv[i]))
			return (TRUE);
	while (stack)
	{
		if (stack->value < INT_MIN || stack->value > INT_MAX)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

t_bool	double_detected(t_stack *stack)
{
	t_stack	*cursor;
	t_stack	*next;

	cursor = stack;
	while (cursor && cursor->next)
	{
		next = cursor->next;
		while (next)
		{
			if (cursor->value == next->value)
				return (TRUE);
			next = next->next;
		}
		cursor = cursor->next;
	}
	return (FALSE);
}
