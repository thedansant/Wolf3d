/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:46:03 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/19 17:28:47 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf1(t_wlf *wlf, int x)
{
	wlf->pos.camerax = 2 * x / (double)W - 1;
	wlf->pos.rayposx = wlf->pos.posx;
	wlf->pos.rayposy = wlf->pos.posy;
	wlf->pos.raydirx = wlf->pos.dirx + wlf->pos.planex * wlf->pos.camerax;
	wlf->pos.raydiry = wlf->pos.diry + wlf->pos.planey * wlf->pos.camerax;
	wlf->pos.mapx = (int)wlf->pos.rayposx;
	wlf->pos.mapy = (int)wlf->pos.rayposy;
	wlf->pos.deltadistx = sqrt(1 + (wlf->pos.raydiry * wlf->pos.raydiry)
			/ (wlf->pos.raydirx * wlf->pos.raydirx));
	wlf->pos.deltadisty = sqrt(1 + (wlf->pos.raydirx * wlf->pos.raydirx)
			/ (wlf->pos.raydiry * wlf->pos.raydiry));
}

void			wolf2(t_wlf *wlf)
{
	wlf->pos.hit = 0;
	if (wlf->pos.raydirx < 0)
	{
		wlf->pos.stepx = -1;
		wlf->pos.sidedistx = (wlf->pos.rayposx - wlf->pos.mapx) *
			wlf->pos.deltadistx;
	}
	else
	{
		wlf->pos.stepx = 1;
		wlf->pos.sidedistx = (wlf->pos.mapx + 1.0 - wlf->pos.rayposx) *
			wlf->pos.deltadistx;
	}
	if (wlf->pos.raydiry < 0)
	{
		wlf->pos.stepy = -1;
		wlf->pos.sidedisty = (wlf->pos.rayposy - wlf->pos.mapy) *
			wlf->pos.deltadisty;
	}
	else
	{
		wlf->pos.stepy = 1;
		wlf->pos.sidedisty = (wlf->pos.mapy + 1.0 - wlf->pos.rayposy)
			* wlf->pos.deltadisty;
	}
}

void			wolf3(t_wlf *wlf)
{
	while (wlf->pos.hit == 0)
	{
		if (wlf->pos.sidedistx < wlf->pos.sidedisty)
		{
			wlf->pos.sidedistx += wlf->pos.deltadistx;
			wlf->pos.mapx += wlf->pos.stepx;
			wlf->pos.side = 0;
		}
		else
		{
			wlf->pos.sidedisty += wlf->pos.deltadisty;
			wlf->pos.mapy += wlf->pos.stepy;
			wlf->pos.side = 1;
		}
		if (wlf->map.tab[wlf->pos.mapx][wlf->pos.mapy] > 0)
			wlf->pos.hit = 1;
	}
}

void			wolf4(t_wlf *wlf)
{
	if (wlf->pos.side == 0)
		wlf->pos.perpwalldist = (wlf->pos.mapx - wlf->pos.rayposx +
				(1 - wlf->pos.stepx) / 2) / wlf->pos.raydirx;
	else
		wlf->pos.perpwalldist = (wlf->pos.mapy - wlf->pos.rayposy +
				(1 - wlf->pos.stepy) / 2) / wlf->pos.raydiry;
	wlf->pos.lineheight = (int)(H / wlf->pos.perpwalldist);
	wlf->pos.drawstart = -wlf->pos.lineheight / 2 + H / 2;
	if (wlf->pos.drawstart < 0)
		wlf->pos.drawstart = 0;
	wlf->pos.drawend = wlf->pos.lineheight / 2 + H / 2;
	if (wlf->pos.drawend >= H)
		wlf->pos.drawend = H - 1;
}

void			wolf5(t_wlf *wlf, int x, int tmp)
{
	if (wlf->pos.side == 0)
		wlf->mlx.img.color = wlf->pos.mapx > wlf->pos.posx ?
			wlf->mlx.img.color1 : wlf->mlx.img.color2;
	else
		wlf->mlx.img.color = wlf->pos.mapy > wlf->pos.posy ?
			wlf->mlx.img.color3 : wlf->mlx.img.color4;
	while (tmp < wlf->pos.drawstart)
	{
		draw_px(x, tmp, wlf->mlx.img.color0, wlf);
		tmp++;
	}
	while (tmp < wlf->pos.drawend)
	{
		draw_px(x, tmp, wlf->mlx.img.color, wlf);
		tmp++;
	}
	while (tmp < H)
	{
		draw_px(x, tmp, wlf->mlx.img.color5, wlf);
		tmp++;
	}
}
