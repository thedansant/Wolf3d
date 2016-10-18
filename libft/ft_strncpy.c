/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 18:03:17 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/09 19:06:45 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*res;
	size_t	i;

	res = (char *)dst;
	i = n;
	while (*src && n--)
		*dst++ = *src++;
	if (n < i)
		ft_bzero(dst, n);
	return (res);
}
