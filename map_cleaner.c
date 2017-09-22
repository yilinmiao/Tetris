/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:19:06 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 22:19:07 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_map(char **map, int mapsize)
{
	int		i;

	i = -1;
	while (++i < mapsize)
		free(map[i]);
	free(map);
}

char	**ft_map_clean(char **map, int n, int mapsize)
{
	int i;
	int j;

	i = -1;
	while (++i < mapsize)
	{
		j = -1;
		while (++j < mapsize)
		{
			if (map[i][j] == g_letter[n])
				map[i][j] = '.';
		}
	}
	return (map);
}
