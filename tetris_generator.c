/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_generator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:53:27 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/22 13:53:28 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data	*get_tetris(t_list *list)
{
	int		i;
	t_data	*start;
	t_data	*tetris;

	tetris = new_tetris();
	start = tetris;
	i = 0;
	while (i < g_num)
	{
		tetris = ft_list_to_tetris(list, tetris, g_letter[i]);
		tetris->n = i;
		i++;
		list = list->next;
		if (i < g_num)
		{
			tetris->next = new_tetris();
			tetris = tetris->next;
		}
	}
	return (start);
}

t_data	*ft_list_to_tetris(t_list *list, t_data *data, char c)
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
				data = get_position(data, i, j);
				data->tetr[i][j] = c;
			}
		}
	}
	return (data);
}

t_data	*get_position(t_data *data, int i, int j)
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
