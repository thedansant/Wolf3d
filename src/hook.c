/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:33:52 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/18 19:12:36 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		rot_left(t_wlf *wlf)
{
	wlf->pos.olddirX = wlf->pos.dirX;
	wlf->pos.dirX = wlf->pos.dirX * cos(wlf->pos.rotspeed) -
		wlf->pos.dirY * sin(wlf->pos.rotspeed);
	wlf->pos.dirY = wlf->pos.olddirX * sin(wlf->pos.rotspeed) +
		wlf->pos.dirY * cos(wlf->pos.rotspeed);
	wlf->pos.oldplaneX = wlf->pos.planeX;
	wlf->pos.planeX = wlf->pos.planeX * cos(wlf->pos.rotspeed) -
		wlf->pos.planeY * sin(wlf->pos.rotspeed);
	wlf->pos.planeY = wlf->pos.oldplaneX * sin(wlf->pos.rotspeed) +
		wlf->pos.planeY * cos(wlf->pos.rotspeed);
}

static void		rot_right(t_wlf *wlf)
{
	wlf->pos.olddirX = wlf->pos.dirX;
	wlf->pos.dirX = wlf->pos.dirX * cos(-wlf->pos.rotspeed) -
		wlf->pos.dirY * sin(-wlf->pos.rotspeed);
	wlf->pos.dirY = wlf->pos.olddirX * sin(-wlf->pos.rotspeed) +
		wlf->pos.dirY * cos(-wlf->pos.rotspeed);
	wlf->pos.oldplaneX = wlf->pos.planeX;
	wlf->pos.planeX = wlf->pos.planeX * cos(-wlf->pos.rotspeed) -
		wlf->pos.planeY * sin(-wlf->pos.rotspeed);
	wlf->pos.planeY = wlf->pos.oldplaneX * sin(-wlf->pos.rotspeed) +
		wlf->pos.planeY * cos(-wlf->pos.rotspeed);
}

static void		move2(int keycode, t_wlf *wlf)
{
	if (keycode == 13)
	{
		if (wlf->map.tab[(int)(wlf->pos.posX + wlf->pos.dirX *
					wlf->pos.movespeed)][(int)(wlf->pos.posY)] == 0)
			wlf->pos.posX += wlf->pos.dirX * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posX)][(int)(wlf->pos.posY +
					wlf->pos.dirY * wlf->pos.movespeed)] == 0)
			wlf->pos.posY += wlf->pos.dirY * wlf->pos.movespeed;
	}
	if (keycode == 1)
	{
		if (wlf->map.tab[(int)(wlf->pos.posX - wlf->pos.dirX *
					wlf->pos.movespeed)][(int)wlf->pos.posY] == 0)
			wlf->pos.posX -= wlf->pos.dirX * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posX)][(int)(wlf->pos.posY -
					wlf->pos.dirY * wlf->pos.movespeed)] == 0)
			wlf->pos.posY -= wlf->pos.dirY * wlf->pos.movespeed;
	}
}

static void		move(int keycode, t_wlf *wlf)
{
	if (keycode == 0)
	{
		if (wlf->map.tab[(int)(wlf->pos.posX - wlf->pos.planeX *
					wlf->pos.movespeed)][(int)(wlf->pos.posY)] == 0)
			wlf->pos.posX -= wlf->pos.planeX * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posX)][(int)(wlf->pos.posY -
					wlf->pos.planeY * wlf->pos.movespeed)] == 0)
			wlf->pos.posY -= wlf->pos.planeY * wlf->pos.movespeed;
	}
	if (keycode == 2)
	{
		if (wlf->map.tab[(int)(wlf->pos.posX + wlf->pos.planeX *
					wlf->pos.movespeed)][(int)(wlf->pos.posY)] == 0)
			wlf->pos.posX += wlf->pos.planeX * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posX)][(int)(wlf->pos.posY +
					wlf->pos.planeY * wlf->pos.movespeed)] == 0)
			wlf->pos.posY += wlf->pos.planeY * wlf->pos.movespeed;
	}
	move2(keycode, wlf);
}

int				ft_key_hook(int keycode, t_wlf *wlf)
{
	if (keycode == 53)
		exit(0);
	move(keycode, wlf);
	if (keycode == 123)
		rot_left(wlf);
	if (keycode == 124)
		rot_right(wlf);
	wolf(wlf);
	return (0);
}
