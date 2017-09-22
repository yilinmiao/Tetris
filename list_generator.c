/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 13:53:05 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/22 13:53:07 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*new_list(void)
{
	t_list	*list;
	int		i;
	int		j;

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

t_list		*generate_tetris_list(char *filename, t_list *list)
{
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((list = ft_pre_readfile(list, fd)) == NULL)
		return (NULL);
	return (list);
}