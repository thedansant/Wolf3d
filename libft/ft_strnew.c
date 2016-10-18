/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 17:19:54 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/09 15:26:25 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size != 0)
	{
		dst[size] = '\0';
		size--;
	}
	dst[size] = '\0';
	return (dst);
}
