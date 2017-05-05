/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 18:54:10 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 19:33:12 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	init_env(t_env *e)
{
	e->player.posy = 12;
	e->player.posx = 12;
	e->player.dirx = -1;
	e->player.diry = 0;
	e->player.planex = 0;
	e->player.planey = 0.66;
	e->move.time2 = 0;
	e->move.oldtime = 0;
	e->player.goup = 0;
	e->player.godown = 0;
	e->player.goleft = 0;
	e->player.goright = 0;
	e->player.sprint = 0;
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac == 2)
	{
		take_map(&e, av);
		if (!(e.mlx = mlx_init()) ||
			!(e.win = mlx_new_window(e.mlx, W, H, "Wolf3D")) ||
			!(e.img.img_ptr = (mlx_new_image(e.mlx, W, H))) ||
			!(e.img.buffer = (unsigned char *)mlx_get_data_addr(e.img.img_ptr, \
			&e.img.bpp, &e.img.bpl, &e.img.endian)))
			return (0);
		init_env(&e);
		mlx_hook(e.win, 2, (1L << 0), &key_press, &e);
		mlx_hook(e.win, 3, (1L << 1), &key_release, &e);
		mlx_hook(e.win, 17, (1L << 17), &button_press, &e);
		mlx_loop_hook(e.mlx, &expose_hook, &e);
		mlx_loop(e.mlx);
	}
	error_param(ac);
	return (0);
}
