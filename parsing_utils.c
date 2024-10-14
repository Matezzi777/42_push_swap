/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:46:33 by mmartina          #+#    #+#             */
/*   Updated: 2024/10/14 15:49:14 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Vérifie s'il y a des doublons dans les arguments passés
bool	double_found(char **argv, bool skip_first)
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
bool	ft_is_valid_int(const char *param)
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
