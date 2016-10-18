/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 16:53:29 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/08 19:39:32 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	tmp2;
	int				i;

	i = 0;
	tmp1 = (unsigned char *)s;
	tmp2 = (unsigned char)c;
	while (n != 0)
	{
		if (tmp1[i] == tmp2)
			return (tmp1 + i);
		i++;
		n--;
	}
	return (NULL);
}
