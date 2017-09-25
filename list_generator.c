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

void		define_global_variable(void)
{
	int		i;

	g_num = 0;
	i = 0;
	while (i < 26)
	{
		g_letter[i] = 'A' + i;
		i++;
	}
}

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

t_list		*generate_tetris_list(int fd)
{
	int		ret;
	char	*buf;
	t_list	*list;
	t_list	*head;
	int		lastret;

	list = new_list();
	head = list;
	buf = ft_strnew(21);
	while ((ret = read(fd, buf, 21)) >= 20)
	{
		lastret = ret;
		if (g_num > 0)
		{
			list->next = new_list();
			list = list->next;
		}
		list = validate(buf, list, ret);
		if (list == NULL)
			return (NULL);
		g_num++;
	}
	if (lastret != 20 || ret != 0)
		return (NULL);
	return (head);
}

t_data		*new_tetris(void)
{
	t_data		*data;
	int			i;
	int			j;

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
