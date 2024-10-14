/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:23:15 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 17:47:50 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Vérifie la validité d'un paramètre
static bool	check_param(char *param)
{
	int	i;

	i = -1;
	if (ft_strlen(param) == 1 && (param[0] == '-' || param[0] == '+'))
		return (false);
	while (param[++i])
	{
		if (i == 0 && !(ft_isdigit(param[i])
				|| param[i] == '-' || param[i] == '+'))
			return (false);
		else if (i > 0 && !ft_isdigit(param[i]))
			return (false);
	}
	if (!ft_is_valid_int(param))
		return (false);
	return (true);
}

//Vérifie la validité des paramètres passés
static bool	check_params_validity(char **params, bool skip_first)
{
	int	i;

	i = -1;
	if (skip_first)
		i++;
	while (params[++i])
		if (!check_param(params[i]))
			return (false);
	if (double_found(params, skip_first))
		return (false);
	return (true);
}

//Vérifie la validité des arguments et remplis une
//stack avec les arguments (depuis une string (argc==2))
static t_node	*ft_parse_from_string(char **argv)
{
	char	**arguments;
	t_node	*stack;
	int		i;

	i = -1;
	arguments = ft_split(argv[1], ' ');
	if (check_params_validity(arguments, false))
	{
		stack = populate_stack(arguments, false);
		while (arguments[++i])
			free(arguments[i]);
		free(arguments);
		return (stack);
	}
	else
	{
		while (arguments[++i])
			free(arguments[i]);
		print_error();
		free(arguments);
		return (NULL);
	}
}

//Vérifie la validité des arguments et remplis une
//stack avec les arguments (depuis un tab (argc > 2))
static t_node	*ft_parse_from_tab(char **argv)
{
	if (check_params_validity(argv, true))
		return (populate_stack(argv, true));
	else
	{
		print_error();
		return (NULL);
	}
}

//Fonction d'entrée vers le parsing
t_node	*ft_parse_arguments(int argc, char **argv)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (NULL);
	if (argc == 2)
		return (ft_parse_from_string(argv));
	else
		return (ft_parse_from_tab(argv));
}
