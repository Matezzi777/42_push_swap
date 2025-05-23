/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 01:49:10 by maxmart2          #+#    #+#             */
/*   Updated: 2025/05/24 01:20:07 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_stack	*parse_from_string(char *str)
{
	int		i;

	if (!str || !str[0])
		return (NULL);
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '+' && str[i] != '-')
			return (NULL);
	return (get_stack_from_string(str));
}

static t_stack	*parse_from_array(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (NULL);
}

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
	if (double_detected(stack) || overflow_detected(stack))
		return (free_stack(&stack));
	return (stack);
}
