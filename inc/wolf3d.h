/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbompoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:39:24 by mbompoil          #+#    #+#             */
/*   Updated: 2016/09/30 18:02:13 by mbompoil         ###   ########.fr       */
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


#include <stdio.h>

typedef struct		s_map
{
	int				nb_column;
	int				nb_line;
	int				**tab;

}					t_map;


typedef struct		s_pos
{
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			time;
	double			olddirX;
	double			olddirY;
	double			oldplaneX;
	double			oldplaneY;
	double			old_time;
	double			frametime;
	double			movespeed;
	double			rotspeed;
	double			cameraX;
	double			rayposX;
	double			rayposY;
	double			raydirX;
	double			raydirY;
	int				mapX;
	int				mapY;
	double			sidedistX;
	double			sidedistY;
	double			deltadistX;
	double			deltadistY;
	double			perpwalldist;
	int				stepX;
	int				stepY;
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
