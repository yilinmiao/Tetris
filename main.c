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
	t_data	*data;
	char	**map;

	list = NULL;
	data = NULL;
	list = ft_init_list(list);
	data = ft_init_data(data);
	init_global();
	if (argc != 2)
	{
		ft_putstr("error\n");
		return (-1);
	}
	if ((list = ft_pre_openfile(argv[1], list)) == NULL)
	{
		ft_putstr("error\n");
		return (-1);
	}
	map = ft_give_me_map(list, data);
	ft_printmap(map);
	return (0);
}
