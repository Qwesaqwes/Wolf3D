/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 16:17:21 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 18:57:56 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	movement_to_right(t_env *e)
{
	e->player.olddirx = e->player.dirx;
	e->player.dirx = (e->player.dirx * cos((e->move.rotspeed) * -1)) -
	(e->player.diry * sin((e->move.rotspeed) * -1));
	e->player.diry = (e->player.olddirx * sin((e->move.rotspeed) * -1)) +
	(e->player.diry * cos((e->move.rotspeed) * -1));
	e->player.oldplanex = e->player.planex;
	e->player.planex = (e->player.planex * cos((e->move.rotspeed) * -1)) -
	(e->player.planey * sin((e->move.rotspeed) * -1));
	e->player.planey = (e->player.oldplanex * sin((e->move.rotspeed) * -1))
	+ (e->player.planey * cos((e->move.rotspeed) * -1));
}

void	movement_to_left(t_env *e)
{
	e->player.olddirx = e->player.dirx;
	e->player.dirx = (e->player.dirx * cos(e->move.rotspeed)) -
	(e->player.diry * sin(e->move.rotspeed));
	e->player.diry = (e->player.olddirx * sin(e->move.rotspeed)) +
	(e->player.diry * cos(e->move.rotspeed));
	e->player.oldplanex = e->player.planex;
	e->player.planex = (e->player.planex * cos(e->move.rotspeed)) -
	(e->player.planey * sin(e->move.rotspeed));
	e->player.planey = (e->player.oldplanex * sin(e->move.rotspeed)) +
	(e->player.planey * cos(e->move.rotspeed));
}

void	movement_to_up(t_env *e)
{
	if (e->worldmap[(int)(e->player.posx +
		(e->player.dirx * e->move.movespeed))][(int)e->player.posy] == 0)
		e->player.posx += e->player.dirx * e->move.movespeed;
	if (e->worldmap[(int)e->player.posx][(int)(e->player.posy +
		(e->player.diry * e->move.movespeed))] == 0)
		e->player.posy += e->player.diry * e->move.movespeed;
}

void	movement_to_down(t_env *e)
{
	if (e->worldmap[(int)(e->player.posx -
		(e->player.dirx * e->move.movespeed))][(int)e->player.posy] == 0)
		e->player.posx -= e->player.dirx * e->move.movespeed;
	if (e->worldmap[(int)e->player.posx][(int)(e->player.posy -
		(e->player.diry * e->move.movespeed))] == 0)
		e->player.posy -= e->player.diry * e->move.movespeed;
}

void	movement(t_env *e)
{
	e->move.oldtime = e->move.time2;
	gettimeofday(&(e->move.time), NULL);
	e->move.milisec = e->move.time.tv_usec;
	e->move.sec = e->move.time.tv_sec;
	e->move.time2 = ((e->move.sec) * 1000.0 + e->move.milisec / 1000.0) + 0.5;
	e->move.frametime = (e->move.time2 - e->move.oldtime);
	e->move.movespeed = e->move.frametime * 0.0042 + e->player.sprint;
	e->move.rotspeed = e->move.frametime * 0.0023;
	if (e->player.goup == 1)
		movement_to_up(e);
	if (e->player.godown == 1)
		movement_to_down(e);
	if (e->player.goright == 1)
		movement_to_right(e);
	if (e->player.goleft == 1)
		movement_to_left(e);
}
