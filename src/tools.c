/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 12:25:54 by mbompoil          #+#    #+#             */
/*   Updated: 2016/09/22 17:21:34 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		get_data(t_wlf *wlf)
{
	wlf->mlx.img_str = mlx_get_data_addr(wlf->mlx.img.img, &wlf->mlx.img.bits,
			&wlf->mlx.img.size_line, &wlf->mlx.img.endian);
}

void		draw_px(int x, int y, int color, t_wlf *wlf)
{
	get_data(wlf);
	*(int *)(unsigned long)(wlf->mlx.img_str + (wlf->mlx.img.size_line * y) +
			(x * wlf->mlx.img.bits / 8)) = color;
}
