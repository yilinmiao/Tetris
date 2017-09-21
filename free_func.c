/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:30:20 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/20 11:30:21 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*free_list(t_list *list)
{
	t_data	*shape;
	t_list	*next;

	while (list)
	{
		shape = (t_data *)list->content;
		next = list->next;
		free_shape(shape);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		free_shape(t_data *shape)
{
	int y;

	y = 0;
	while (y < shape->height)
	{
		ft_memdel((void **)(&(shape->pos[y])));
		y++;
	}
	ft_memdel((void **)(&(shape->pos)));
	ft_memdel((void **)&shape);
}

void		free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
