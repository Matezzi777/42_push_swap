/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:20:03 by maxmart2          #+#    #+#             */
/*   Updated: 2025/08/11 17:21:13 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*parse_from_string(char *str)
{
	int		i;
	t_bool	digit_found;

	if (!str || !str[0])
		return (NULL);
	digit_found = FALSE;
	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
		{
			digit_found = TRUE;
			if (str[i + 1] && !ft_isdigit(str[i + 1]) && str[i + 1] != ' ')
				return (NULL);
		}
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			return (NULL);
		if (str[i] == '+' || str[i] == '-')
			if (!ft_isdigit(str[i + 1]))
				return (NULL);
	}
	if (!digit_found)
		return (NULL);
	return (get_stack_from_string(str));
}

static t_stack	*parse_from_array(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*node;

	stack = parse_from_string(argv[1]);
	if (!stack)
		return (NULL);
	i = 1;
	while (++i < argc)
	{
		node = parse_from_string(argv[i]);
		if (!node)
			return (free_stack(&stack), NULL);
		add_stack_elem(&stack, node);
	}
	return (stack);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;

	if (argc == 2)
		stack = parse_from_string(argv[1]);
	else
		stack = parse_from_array(argc, argv);
	if (!stack)
		return (NULL);
	if (overflow_detected(stack, argc, argv) || double_detected(stack))
		return (free_stack(&stack), NULL);
	return (stack);
}
