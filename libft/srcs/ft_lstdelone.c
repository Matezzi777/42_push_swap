/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxmart2 <maxmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 03:25:36 by maxmart2          #+#    #+#             */
/*   Updated: 2025/07/02 19:23:57 by maxmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Free a list element and his content with the function passed as parameter.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
