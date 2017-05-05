/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 17:51:45 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 19:35:58 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		expose_hook(t_env *e)
{
	movement(e);
	raycast(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img.img_ptr, 0, 0);
	mlx_string_put(e->mlx, e->win, 10, 10, 0xFFFFFF,
				"Move with AWDS or with Arrow");
	mlx_string_put(e->mlx, e->win, 10, 30, 0xFFFFFF,
				"Sprint with SHIFT");
	return (0);
}

int		button_press(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img.img_ptr);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
	return (0);
}

int		key_press(int keycode, t_env *e)
{
	if (keycode == UP || keycode == W2)
		e->player.goup = 1;
	else if (keycode == DOWN || keycode == S)
		e->player.godown = 1;
	else if (keycode == LEFT || keycode == A)
		e->player.goleft = 1;
	else if (keycode == RIGHT || keycode == D)
		e->player.goright = 1;
	else if (keycode == SHIFT)
		e->player.sprint = 0.1;
	expose_hook(e);
	return (0);
}

int		key_release(int keycode, t_env *e)
{
	if (keycode == ESC)
	{
		mlx_destroy_image(e->mlx, e->img.img_ptr);
		mlx_destroy_window(e->mlx, e->win);
		exit(1);
	}
	else if (keycode == UP || keycode == W2)
		e->player.goup = 0;
	else if (keycode == DOWN || keycode == S)
		e->player.godown = 0;
	else if (keycode == LEFT || keycode == A)
		e->player.goleft = 0;
	else if (keycode == RIGHT || keycode == D)
		e->player.goright = 0;
	else if (keycode == SHIFT)
		e->player.sprint = 0;
	expose_hook(e);
	return (0);
}
