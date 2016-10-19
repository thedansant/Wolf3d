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
	wlf->pos.olddirx = wlf->pos.dirx;
	wlf->pos.dirx = wlf->pos.dirx * cos(wlf->pos.rotspeed) -
		wlf->pos.diry * sin(wlf->pos.rotspeed);
	wlf->pos.diry = wlf->pos.olddirx * sin(wlf->pos.rotspeed) +
		wlf->pos.diry * cos(wlf->pos.rotspeed);
	wlf->pos.oldplanex = wlf->pos.planex;
	wlf->pos.planex = wlf->pos.planex * cos(wlf->pos.rotspeed) -
		wlf->pos.planey * sin(wlf->pos.rotspeed);
	wlf->pos.planey = wlf->pos.oldplanex * sin(wlf->pos.rotspeed) +
		wlf->pos.planey * cos(wlf->pos.rotspeed);
}

static void		rot_right(t_wlf *wlf)
{
	wlf->pos.olddirx = wlf->pos.dirx;
	wlf->pos.dirx = wlf->pos.dirx * cos(-wlf->pos.rotspeed) -
		wlf->pos.diry * sin(-wlf->pos.rotspeed);
	wlf->pos.diry = wlf->pos.olddirx * sin(-wlf->pos.rotspeed) +
		wlf->pos.diry * cos(-wlf->pos.rotspeed);
	wlf->pos.oldplanex = wlf->pos.planex;
	wlf->pos.planex = wlf->pos.planex * cos(-wlf->pos.rotspeed) -
		wlf->pos.planey * sin(-wlf->pos.rotspeed);
	wlf->pos.planey = wlf->pos.oldplanex * sin(-wlf->pos.rotspeed) +
		wlf->pos.planey * cos(-wlf->pos.rotspeed);
}

static void		move2(int keycode, t_wlf *wlf)
{
	if (keycode == 13)
	{
		if (wlf->map.tab[(int)(wlf->pos.posx + wlf->pos.dirx *
					wlf->pos.movespeed)][(int)(wlf->pos.posy)] == 0)
			wlf->pos.posx += wlf->pos.dirx * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posx)][(int)(wlf->pos.posy +
					wlf->pos.diry * wlf->pos.movespeed)] == 0)
			wlf->pos.posy += wlf->pos.diry * wlf->pos.movespeed;
	}
	if (keycode == 1)
	{
		if (wlf->map.tab[(int)(wlf->pos.posx - wlf->pos.dirx *
					wlf->pos.movespeed)][(int)wlf->pos.posy] == 0)
			wlf->pos.posx -= wlf->pos.dirx * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posx)][(int)(wlf->pos.posy -
					wlf->pos.diry * wlf->pos.movespeed)] == 0)
			wlf->pos.posy -= wlf->pos.diry * wlf->pos.movespeed;
	}
}

static void		move(int keycode, t_wlf *wlf)
{
	if (keycode == 0)
	{
		if (wlf->map.tab[(int)(wlf->pos.posx - wlf->pos.planex *
					wlf->pos.movespeed)][(int)(wlf->pos.posy)] == 0)
			wlf->pos.posx -= wlf->pos.planex * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posx)][(int)(wlf->pos.posy -
					wlf->pos.planey * wlf->pos.movespeed)] == 0)
			wlf->pos.posy -= wlf->pos.planey * wlf->pos.movespeed;
	}
	if (keycode == 2)
	{
		if (wlf->map.tab[(int)(wlf->pos.posx + wlf->pos.planex *
					wlf->pos.movespeed)][(int)(wlf->pos.posy)] == 0)
			wlf->pos.posx += wlf->pos.planex * wlf->pos.movespeed;
		if (wlf->map.tab[(int)(wlf->pos.posx)][(int)(wlf->pos.posy +
					wlf->pos.planey * wlf->pos.movespeed)] == 0)
			wlf->pos.posy += wlf->pos.planey * wlf->pos.movespeed;
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
