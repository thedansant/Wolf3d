/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:06:39 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/09 19:19:16 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	i = 0;
	if (tmp2 < tmp1)
	{
		while (++i <= len)
			tmp1[len - i] = tmp2[len - i];
	}
	else
	{
		while (i < len)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	return (dst);
}
