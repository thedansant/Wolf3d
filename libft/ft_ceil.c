/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ceil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 17:54:59 by mbompoil          #+#    #+#             */
/*   Updated: 2015/12/14 18:45:15 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ceil(double x)
{
	return (((int)x == x) ? x : (int)x + 1);
}
