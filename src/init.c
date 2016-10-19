/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:20:42 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/19 17:28:38 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			init_color(t_wlf *wlf)
{
	wlf->mlx.img.color1 = 0xFF0000;
	wlf->mlx.img.color2 = 0xFFFF00;
	wlf->mlx.img.color3 = 0x00FF00;
	wlf->mlx.img.color4 = 0x0000FF;
	wlf->mlx.img.color5 = 0x808080;
	wlf->mlx.img.color0 = 0x77B5FE;

}

void				ft_pos_init(t_wlf *wlf)
{
	wlf->pos.posx = 3;
	wlf->pos.posy = 3;
	wlf->pos.dirx = -1;
	wlf->pos.diry = 0;
	wlf->pos.planex = 0;
	wlf->pos.planey = 0.66;
	wlf->pos.old_time = 0;
	wlf->pos.movespeed = 0.3;
	wlf->pos.rotspeed = 0.2;
	init_color(wlf);
}

void				ft_mlx_init(t_wlf *wlf)
{
	if (!(wlf->mlx.mlx = mlx_init()))
		ft_error("failed to init mlx");
	if (!(wlf->mlx.win = mlx_new_window(wlf->mlx.mlx, W, H, "Wolf3d")))
		ft_error("failed to create new window");
	if (!(wlf->mlx.img.img = mlx_new_image(wlf->mlx.mlx, W, H)))
		ft_error("failed to create new image");
	if (!(wlf->mlx.img.data = mlx_get_data_addr(wlf->mlx.img.img,
					&wlf->mlx.img.bits, &wlf->mlx.img.size_line,
					&wlf->mlx.img.endian)))
		ft_error("failed to get image datas");
	mlx_hook(wlf->mlx.win, 2, 3, ft_key_hook, wlf);
}
