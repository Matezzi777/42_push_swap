/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <mmartina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:18:16 by mmartina          #+#    #+#             */
/*   Updated: 2024/09/23 04:02:05 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//OK
static int	absolute(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

//OK (inclus le \0)
static int	size_to_malloc(int n)
{
	int	i;

	i = 2;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

//OK
char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*result;

	len = size_to_malloc(n);
	i = len - 2;
	result = (char *)malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n < 0)
		result[0] = '-';
	while (n != 0)
	{
		result[i] = absolute(n % 10) + '0';
		i--;
		n = n / 10;
	}
	result[len - 1] = '\0';
	return (result);
}
