/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:36:13 by jichen-m          #+#    #+#             */
/*   Updated: 2015/09/20 16:09:01 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	char		*tmp;

	if (s)
	{
		tmp = (char *)s;
		while (n--)
		{
			*tmp = '\0';
			tmp++;
		}
	}
}
