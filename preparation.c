/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:55:39 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 21:55:41 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_init_list(t_list *list)
{
	int i;
	int j;

	i = -1;
	list = (t_list*)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			list->tetr[i][j] = 'w';
		list->tetr[i][j] = 0;
	}
	list->next = NULL;
	return (list);
}

t_data	*ft_init_data(t_data *data)
{
	int i;
	int j;

	data = (t_data*)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->point[0] = 9;
	data->point[1] = 9;
	data->point[2] = 0;
	data->point[3] = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			data->tetr[i][j] = 'w';
		data->tetr[i][j] = 0;
	}
	data->next = NULL;
	data->before = NULL;
	return (data);
}

void	init_global(void)
{
	int i;

	g_num = 0;
	i = 0;
	while (i < 26)
	{
		g_letter[i] = 'A' + i;
		i++;
	}
}

char	**ft_init_map(int mapsize)
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

t_list	*ft_pre_openfile(char *filename, t_list *list)
{
	int fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((list = ft_pre_readfile(list, fd)) == NULL)
		return (NULL);
	return (list);
}
