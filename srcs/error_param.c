/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 18:13:23 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/14 18:16:09 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	error_param(int ac)
{
	if (ac > 2)
		ft_putstr(">> Too many parameter, plis tap only 1 parameter <<\n");
	if (ac < 2)
		ft_putstr(">> Too few parameter, plis tap only 1 parameter <<\n");
}
