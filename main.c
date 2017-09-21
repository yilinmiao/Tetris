/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:29:47 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/19 22:29:48 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list		*list;
	t_map		*map;
	int			i;

	if (argc != 2)
	{
		ft_putstr("Error: need file\n");
		return (-1);
	}
	if ((list = init_shape(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("Error: can't read file\n");
		return (-1);
	}
	map = generate_map(list);
	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
	free_map(map);
	free_list(list);
	return (0);
}
