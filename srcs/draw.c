/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 15:51:03 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 18:49:19 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	palette(int r, int g, int b, t_color *color)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	put_pixel_to_image(t_env *e, int line, int col, t_color *color)
{
	int		res;

	res = (col * e->img.bpp / 8) + (line * e->img.bpl);
	e->img.buffer[res] = color->r;
	e->img.buffer[res + 1] = color->g;
	e->img.buffer[res + 2] = color->b;
}

void	draw2(t_env *e, int col, int start)
{
	if (e->player.sidewall == 0 && e->ray.dirx < 0)
	{
		palette(0, 255, 128, &(e->north));
		put_pixel_to_image(e, start, col, &(e->north));
	}
	else if (e->player.sidewall == 0 && e->ray.dirx > 0)
	{
		palette(255, 0, 255, &(e->south));
		put_pixel_to_image(e, start, col, &(e->south));
	}
	else if (e->player.sidewall == 1 && e->ray.diry > 0)
	{
		palette(255, 128, 0, &(e->east));
		put_pixel_to_image(e, start, col, &(e->east));
	}
	else
	{
		palette(120, 120, 64, &(e->ouest));
		put_pixel_to_image(e, start, col, &(e->ouest));
	}
}

void	draw(t_env *e, int col, int start, int end)
{
	int		line;
	t_color	color;

	line = -1;
	while (++line < start)
	{
		palette(96, 96, 96, &color);
		put_pixel_to_image(e, line, col, &color);
	}
	while (start < end)
	{
		draw2(e, col, start);
		start++;
	}
	while (end < H)
	{
		palette(96, 96, 96, &color);
		put_pixel_to_image(e, end, col, &color);
		end++;
	}
}
