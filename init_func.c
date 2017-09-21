/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:44:55 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/20 21:44:56 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_point		*new_point(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_data		*new_shape(char **tab, int width, int height, char value)
{
	t_data		*shape;

	shape = ft_memalloc(sizeof(t_data));
	shape->tab = tab;
	shape->width = width;
	shape->height = height;
	shape->value = value;
	return (shape);
}

t_map		*new_map(int size)
{
	char	**map;
	int		i;
	int		j;

	i = -1;
	map = (char**)malloc(sizeof(char*) * size + 1);
	map[size] = NULL;
	while (++i < size)
	{
		j = -1;
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		while (++j < size)
			map[i][j] = '.';
		map[i][size] = '\0';
	}
	return (map);
}
