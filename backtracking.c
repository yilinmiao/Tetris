/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 11:32:27 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 11:32:28 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_piece(t_data *shape, t_map *map, t_point *p, char c)
{
	int i;
	int j;

	i = 0;
	while (i < shape->height)
	{
		j = 0;
		while (j < shape->width)
		{
			if (shape->tab[i][j] == '#')
				map->tab[p->x + i][p->y + j] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&p);
}

int		is_fit(t_data *shape, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < shape->height)
	{
		j = 0;
		while (j < shape->width)
		{
			if (shape->tab[i][j] == '#' && map->tab[x + j][y + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(shape, map, new_point(x, y), shape->value);
	return (1);
}

/*
** Recursion: continue to find fit for all shapes. Otherwise return 0;
*/

int		try_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_data		*shape;

	if (list == NULL)
		return (1);
	x = 0;
	shape = (t_data *)(list->content);
	while (x < map->size - shape->height + 1)
	{
		y = 0;
		while (y < map->size - shape->width + 1)
		{
			if (is_fit(shape, map, x, y))
			{
				if (try_map(map, list->next))
					return (1);
				else
					set_piece(shape, map, new_point(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

t_map	*generate_map(t_list *list)
{
	t_map	*map;
	int		size;

	size = 2;
	while (size * size < ft_lstcount(list) * 4)
		size++;
	map = new_map(size);
	while (!try_map(map, list))
	{
		free_map(map);
		map = new_map(++size);
	}
	return (map);
}
