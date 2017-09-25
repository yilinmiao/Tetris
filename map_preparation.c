/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:09:44 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 22:09:45 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**new_map(int mapsize)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * mapsize + 1);
	map[mapsize] = NULL;
	while (++i < mapsize)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (mapsize + 1));
		while (++j < mapsize)
			map[i][j] = '.';
		map[i][mapsize] = '\0';
	}
	return (map);
}

int			get_min_size(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

void		print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putchar(map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
