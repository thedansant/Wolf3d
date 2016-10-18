/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:28:17 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/08 18:52:51 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*m;

	if (len == 0)
		return (b);
	i = 0;
	m = (unsigned char *)b;
	while (i <= len)
	{
		m[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
