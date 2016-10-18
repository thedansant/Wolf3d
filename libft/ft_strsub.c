/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:21:32 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/07 20:26:07 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s1, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(*dst) * (len + 1))))
		return (NULL);
	while (len != 0)
	{
		dst[i] = s1[start];
		len--;
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}
