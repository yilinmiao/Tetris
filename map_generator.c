/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:04:56 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 22:04:57 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**generate_map(t_list *list, t_data *data)
{
	int		mapsize;
	char	**map;

	mapsize = ft_minmapsize(g_num);
	map = ft_init_map(mapsize);
	data = ft_give_me_data(list, data);
	while ((ft_checkmap_samemapsize(data, mapsize, map)) == NULL)
	{
		ft_free_map(map, mapsize);
		mapsize++;
		map = ft_init_map(mapsize);
	}
	return (map);
}

t_data	*ft_give_me_data(t_list *list, t_data *data)
{
	int		i;
	t_data	*start;

	start = data;
	i = 0;
	while (i < g_num)
	{
		data = ft_list_to_data(list, data, g_letter[i]);
		data->n = i;
		i++;
		list = list->next;
		if (i < g_num)
			data = ft_pre_newdata(data);
	}
	return (start);
}

t_data	*ft_list_to_data(t_list *list, t_data *data, char c)
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			data->tetr[i][j] = list->tetr[i][j];
			if (data->tetr[i][j] == '#')
			{
				data = ft_list_to_data_point(data, i, j);
				data->tetr[i][j] = c;
			}
		}
	}
	return (data);
}

t_data	*ft_list_to_data_point(t_data *data, int i, int j)
{
	if (data->point[0] > i)
		data->point[0] = i;
	if (data->point[1] > j)
		data->point[1] = j;
	if (data->point[2] < i)
		data->point[2] = i;
	if (data->point[3] < j)
		data->point[3] = j;
	return (data);
}

void	print_map(char **map)
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
