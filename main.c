/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:42:07 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 21:42:09 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list	*list;
	char	**map;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (-1);
	}
	define_global_variable();
	if ((list = generate_tetris_list(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	map = generate_map(list);
	print_map(map);
	return (0);
}
