/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:24:47 by mmartina          #+#    #+#             */
/*   Updated: 2024/01/17 15:24:49 by mmartina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dst;
	osrc = src;
	n = dsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
