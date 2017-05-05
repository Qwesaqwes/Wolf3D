/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 14:33:12 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 18:57:37 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	dist_ray_to_wall(t_env *e)
{
	double	xtmp;
	double	ytmp;

	xtmp = (e->mapx - e->ray.posx + (1 - e->stepx) / 2) / e->ray.dirx;
	ytmp = (e->mapy - e->ray.posy + (1 - e->stepy) / 2) / e->ray.diry;
	if (e->player.sidewall == 0)
		e->walldist = xtmp;
	else
		e->walldist = ytmp;
}

void	calcul_line(t_env *e)
{
	e->line.lineheight = (int)(H / e->walldist);
	e->line.drawstart = ((-1 * e->line.lineheight) / 2) + (H / 2);
	if (e->line.drawstart < 0)
		e->line.drawstart = 0;
	e->line.drawend = e->line.lineheight / 2 + (H / 2);
	if (e->line.drawend >= H)
		e->line.drawend = H - 1;
}

void	check_hit(t_env *e)
{
	e->player.hit = 0;
	while (e->player.hit == 0)
	{
		if (e->ray.distx < e->ray.disty)
		{
			e->ray.distx += e->ray.distnextx;
			e->mapx += e->stepx;
			e->player.sidewall = 0;
		}
		else
		{
			e->ray.disty += e->ray.distnexty;
			e->mapy += e->stepy;
			e->player.sidewall = 1;
		}
		e->player.hit = (e->worldmap[e->mapx][e->mapy] > 0) ? 1 : 0;
	}
}

void	dda_algo(t_env *e)
{
	double		xtmp;
	double		ytmp;

	e->mapx = (int)e->ray.posx;
	e->mapy = (int)e->ray.posy;
	xtmp = e->ray.dirx * e->ray.dirx;
	ytmp = e->ray.diry * e->ray.diry;
	e->ray.distnextx = sqrt(1 + (ytmp / xtmp));
	e->ray.distnexty = sqrt(1 + (xtmp / ytmp));
	e->stepx = (e->ray.dirx < 0) ? -1 : 1;
	if (e->stepx == -1)
		e->ray.distx = (e->ray.posx - e->mapx) * e->ray.distnextx;
	else
		e->ray.distx = (e->mapx + 1.0 - e->ray.posx) * e->ray.distnextx;
	e->stepy = (e->ray.diry < 0) ? -1 : 1;
	if (e->stepy == -1)
		e->ray.disty = (e->ray.posy - e->mapy) * e->ray.distnexty;
	else
		e->ray.disty = (e->mapy + 1.0 - e->ray.posy) * e->ray.distnexty;
	check_hit(e);
}

void	raycast(t_env *e)
{
	e->col = -1;
	while ((e->col += 1) < W)
	{
		e->camera = (2 * (e->col)) / (double)W - 1;
		e->ray.posx = e->player.posx;
		e->ray.posy = e->player.posy;
		e->ray.dirx = e->player.dirx + (e->player.planex * e->camera);
		e->ray.diry = e->player.diry + (e->player.planey * e->camera);
		dda_algo(e);
		dist_ray_to_wall(e);
		calcul_line(e);
		draw(e, e->col, e->line.drawstart, e->line.drawend);
	}
}
