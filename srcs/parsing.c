/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:49:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 03:35:16 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
	Create the stack from the string when push_swap is used with an unic
	argument and check if the arguments are numbers.
	Return NULL if an error occured during stack creation or if the argument
	is invalid.
*/
static t_stack	*parse_from_string(char *str)
{
	int		i;
	t_bool	digit_found;

	digit_found = FALSE;
	if (!str || !str[0])
		return (NULL);
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

/*
	Create the stack from the arguments given when push_swap is used with
	multiple arguments and check if the arguments are numbers.
	Return NULL if an error occured during stack creation or if an argument is
	invalid.
*/
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
			return (free_stack(&stack));
		add_stack_elem(&stack, node);
	}
	return (stack);
}

/*
	Parse the argument(s) passed to push_swap and check if the arguments are
	unic numbers that fits in an integer.
	Return NULL if an error occured during stack creation or if an argument is
	invalid.
*/
t_stack	*parse_arguments(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
		stack = parse_from_string(argv[1]);
	else
		stack = parse_from_array(argc, argv);
	if (!stack)
		return (NULL);
	if (double_detected(stack) || overflow_detected(stack, argc, argv))
		return (free_stack(&stack));
	return (stack);
}
