/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichen-m <jichen-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 22:54:32 by jichen-m          #+#    #+#             */
/*   Updated: 2016/05/21 18:58:42 by jichen-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		size_word(char *s, char c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		res++;
	}
	return (res);
}

static void		put_int_in_tab(int nb_w, char c, int *tab, char *s)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	size = 0;
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < nb_w)
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
			(s[0] != c && i == 0))
		{
			if (s[i] == c)
				i++;
			size = size_word(&s[i], c);
			tmp = ft_strsub(s, i, size);
			tab[j] = ft_atoi(tmp);
			free(tmp);
			j++;
		}
		i++;
	}
}

static int		*ft_strsplittoint(char const *s, char c)
{
	int		*tab;
	int		nb_w;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	nb_w = 0;
	while (s[++i] != '\0')
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1] != '\0') ||
			(s[0] != c && i == 0))
			nb_w++;
	}
	if (!(tab = (int *)malloc(sizeof(int) * nb_w)))
		return (NULL);
	put_int_in_tab(nb_w, c, tab, (char*)s);
	return (tab);
}

void			take_map(t_env *e, char **av)
{
	int		fd;
	char	*line;
	int		i;

	i = -1;
	line = NULL;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(1);
	while (get_next_line(fd, &line))
	{
		e->worldmap[++i] = ft_strsplittoint(line, ' ');
		free(line);
	}
	close(fd);
}
