/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 19:04:07 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 19:04:20 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>

# define W 700
# define H 700
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W2 13
# define S 1
# define A 0
# define D 2
# define SHIFT 257

typedef struct		s_img
{
	int				bpp;
	int				bpl;
	int				endian;
	unsigned char	*buffer;
	void			*img_ptr;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct		s_ray
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			distx;
	double			disty;
	double			distnextx;
	double			distnexty;
}					t_ray;

typedef struct		s_player
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			olddirx;
	double			planex;
	double			planey;
	double			oldplanex;
	double			sprint;
	int				hit;
	int				sidewall;
	int				goup;
	int				godown;
	int				goleft;
	int				goright;
}					t_player;

typedef	struct		s_line
{
	int				lineheight;
	int				drawstart;
	int				drawend;
}					t_line;

typedef struct		s_move
{
	struct timeval	time;
	double			sec;
	double			milisec;
	double			time2;
	double			oldtime;
	double			frametime;
	double			movespeed;
	double			rotspeed;
}					t_move;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_img			img2;
	t_ray			ray;
	t_player		player;
	t_line			line;
	t_color			north;
	t_color			south;
	t_color			ouest;
	t_color			east;
	t_move			move;
	int				**worldmap;
	int				stepx;
	int				stepy;
	int				mapx;
	int				mapy;
	int				col;
	double			camera;
	double			walldist;
}					t_env;

int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				error_param(int ac);
void				draw(t_env *e, int col, int start, int end);
void				raycast(t_env *e);
void				take_map(t_env *e, char **av);
void				movement(t_env *e);
int					key_press(int keycode, t_env *e);
int					key_release(int keycode, t_env *e);
int					button_press(t_env *e);

#endif
