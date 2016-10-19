/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:39:24 by mbompoil          #+#    #+#             */
/*   Updated: 2016/10/19 17:54:31 by mbompoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# define W 1200
# define H 800
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <../libft/libft.h>

typedef struct		s_map
{
	int				nb_column;
	int				nb_line;
	int				**tab;

}					t_map;

typedef struct		s_pos
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			olddirx;
	double			olddiry;
	double			oldplanex;
	double			oldplaney;
	double			old_time;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_pos;

typedef struct		s_img
{
	void			*data;
	void			*img;
	int				bits;
	int				endian;
	int				size_line;
	int				color;
	int				color1;
	int				color2;
	int				color3;
	int				color4;
	int				color5;
	int				color0;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	char			*img_str;
	t_img			img;
}					t_mlx;

typedef struct		s_wlf
{
	t_mlx			mlx;
	t_pos			pos;
	t_map			map;
	int				tmp;
}					t_wlf;

void				ft_mlx_init(t_wlf *wlf);
void				ft_pos_init(t_wlf *wlf);
void				ft_error(char *c);
void				ft_parse(char *filename, t_wlf *wlf);
void				draw_px(int x, int y, int color, t_wlf *wlf);

int					ft_key_hook(int keycode, t_wlf *wlf);

void				wolf(t_wlf *wlf);
void				wolf1(t_wlf *wlf, int x);
void				wolf2(t_wlf *wlf);
void				wolf3(t_wlf *wlf);
void				wolf4(t_wlf *wlf);
void				wolf5(t_wlf *wlf, int x, int tmp);

#endif
