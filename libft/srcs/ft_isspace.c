/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 23:03:40 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:18:17 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Returns TRUE if the character is a kind of space character.
*/
t_bool	ft_isspace(int c)
{
	if (('\t' <= c && c <= '\r') || c == ' ')
		return (TRUE);
	return (FALSE);
}
