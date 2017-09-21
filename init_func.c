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

t_point	*new_point(int x, int y)
{
	t_point		*point;

	point = ft_memalloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_data		*new_tetris(char **pos, int width, int height, char value)
{
	t_data		*tetris;

	tetris = ft_memalloc(sizeof(t_data));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}