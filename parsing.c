/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:23:15 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:25:23 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	double_found(char **argv, bool skip_first)
{
	int	i;
	int	j;

	i = -1;
	if (skip_first)
		i++;
	while (argv[++i])
	{
		j = i;
		while (argv[++j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
		}
	}
	return (false);
}

//Vérifie si le nombre représenté par la string en argument tient dans un int
static bool	ft_is_valid_int(const char *param)
{
	int			i;
	long int	num;
	int			sign;

	num = 0;
	sign = 1;
	i = -1;
	if (param[0] == '-')
		sign = -1;
	if (param[0] == '-' || param[0] == '+')
		i++;
	while (param[++i])
		num = num * 10 + param[i] - '0';
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
		return (false);
	return (true);
}

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
		ft_printf("Argument invalide détecté.\n");
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
		ft_printf("Argument invalide détecté.\n");
		return (NULL);
	}
}

//Fonction d'entrée vers le parsing
t_node	*ft_parse_arguments(int argc, char **argv)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Pas d'argument.\n");
		return (NULL);
	}
	if (argc == 2)
	{
		ft_printf("Arguments passés sous string.\n");
		return (ft_parse_from_string(argv));
	}
	else
	{
		ft_printf("Arguments passés sous tab.\n");
		return (ft_parse_from_tab(argv));
	}
}
