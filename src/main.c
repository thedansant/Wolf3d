/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:54:08 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/18 18:18:22 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_error(char *c)
{
	ft_putendl(c);
	exit(-1);
}

static void		map(char *av, t_wlf *wlf)
{
	if (ft_strcmp(av, "lvl1") == 0)
		ft_parse("lvl/lvl1", wlf);
	else if (ft_strcmp(av, "lvl2") == 0)
		ft_parse("lvl/lvl2", wlf);
	else if (ft_strcmp(av, "lvl3") == 0)
		ft_parse("lvl/lvl3", wlf);
	else
		ft_error("lvl1\nlvl2\nlvl3");
}

void			wolf(t_wlf *wlf)
{
	int		x;

	x = 0;
	while (x < W)
	{
		wolf1(wlf, x);
		wolf2(wlf);
		wolf3(wlf);
		wolf4(wlf);
		wolf5(wlf, x, 0);
		x++;
	}
	mlx_put_image_to_window(wlf->mlx.mlx, wlf->mlx.win, wlf->mlx.img.img, 0, 0);
}

int				main(int ac, char **av)
{
	t_wlf		wlf;

	if (ac != 2)
		ft_error("lvl1\nlvl2\nlvl3");
	map(av[1], &wlf);
	ft_pos_init(&wlf);
	ft_mlx_init(&wlf);
	wolf(&wlf);
	mlx_loop(wlf.mlx.mlx);
}
