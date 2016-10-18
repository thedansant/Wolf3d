/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 16:46:03 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/10 14:07:48 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			wolf1(t_wlf *wlf, int x)
{
	wlf->pos.cameraX = 2 * x / (double)W - 1;
	wlf->pos.rayposX = wlf->pos.posX;
	wlf->pos.rayposY = wlf->pos.posY;
	wlf->pos.raydirX = wlf->pos.dirX + wlf->pos.planeX * wlf->pos.cameraX;
	wlf->pos.raydirY = wlf->pos.dirY + wlf->pos.planeY * wlf->pos.cameraX;
	wlf->pos.mapX = (int)wlf->pos.rayposX;
	wlf->pos.mapY = (int)wlf->pos.rayposY;
	wlf->pos.deltadistX = sqrt(1 + (wlf->pos.raydirY * wlf->pos.raydirY)
			/ (wlf->pos.raydirX * wlf->pos.raydirX));
	wlf->pos.deltadistY = sqrt(1 + (wlf->pos.raydirX * wlf->pos.raydirX)
			/ (wlf->pos.raydirY * wlf->pos.raydirY));
}

void			wolf2(t_wlf *wlf)
{
	wlf->pos.hit = 0;
	if (wlf->pos.raydirX < 0)
	{
		wlf->pos.stepX = -1;
		wlf->pos.sidedistX = (wlf->pos.rayposX - wlf->pos.mapX) *
			wlf->pos.deltadistX;
	}
	else
	{
		wlf->pos.stepX = 1;
		wlf->pos.sidedistX = (wlf->pos.mapX + 1.0 - wlf->pos.rayposX) *
			wlf->pos.deltadistX;
	}
	if (wlf->pos.raydirY < 0)
	{
		wlf->pos.stepY = -1;
		wlf->pos.sidedistY = (wlf->pos.rayposY - wlf->pos.mapY) *
			wlf->pos.deltadistY;
	}
	else
	{
		wlf->pos.stepY = 1;
		wlf->pos.sidedistY = (wlf->pos.mapY + 1.0 - wlf->pos.rayposY)
			* wlf->pos.deltadistY;
	}
}

void			wolf3(t_wlf *wlf)
{
	while (wlf->pos.hit == 0)
	{
		if (wlf->pos.sidedistX < wlf->pos.sidedistY)
		{
			wlf->pos.sidedistX += wlf->pos.deltadistX;
			wlf->pos.mapX += wlf->pos.stepX;
			wlf->pos.side = 0;
		}
		else
		{
			wlf->pos.sidedistY += wlf->pos.deltadistY;
			wlf->pos.mapY += wlf->pos.stepY;
			wlf->pos.side = 1;
		}
		if (wlf->map.tab[wlf->pos.mapX][wlf->pos.mapY] > 0)
			wlf->pos.hit = 1;
	}
}

void			wolf4(t_wlf *wlf)
{
	if (wlf->pos.side == 0)
		wlf->pos.perpwalldist = (wlf->pos.mapX - wlf->pos.rayposX +
				(1 - wlf->pos.stepX) / 2) / wlf->pos.raydirX;
	else
		wlf->pos.perpwalldist = (wlf->pos.mapY - wlf->pos.rayposY +
				(1 - wlf->pos.stepY) / 2) / wlf->pos.raydirY;
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
		wlf->mlx.img.color = wlf->pos.mapX > wlf->pos.posX ?
			wlf->mlx.img.color1 : wlf->mlx.img.color2;
	else
		wlf->mlx.img.color = wlf->pos.mapY > wlf->pos.posY ?
			wlf->mlx.img.color3 : wlf->mlx.img.color4;
	while (tmp < wlf->pos.drawstart)
	{
		draw_px(x, tmp, 0x77B5FE, wlf);
		tmp++;
	}
	while (tmp < wlf->pos.drawend)
	{
		draw_px(x, tmp, wlf->mlx.img.color, wlf);
		tmp++;
	}
	while (tmp < H)
	{
		draw_px(x, tmp, 0x808080, wlf);
		tmp++;
	}
}
