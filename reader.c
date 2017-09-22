/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:01:04 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 22:01:05 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_pre_readfile(t_list *list, int fd)
{
	int		ret;
	int		lastret;
	char	*buf;
	t_list	*start;

	buf = ft_strnew(21);
	start = list;
	while ((ret = read(fd, buf, 21)))
	{
		lastret = ret;
		if (g_num > 0)
		{
			list = ft_pre_newlist(list);
		}
		list = ft_pre_buf(buf, list, ret);
		if (list == NULL)
			return (NULL);
		g_num++;
	}
	if (lastret != 20 || ret != 0)
		return (NULL);
	return (start);
}

t_list	*ft_pre_newlist(t_list *list)
{
	int		i;
	int		j;
	t_list	*newlist;

	i = -1;
	newlist = (t_list*)malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			newlist->tetr[i][j] = 'w';
		newlist->tetr[i][j] = 0;
	}
	newlist->next = NULL;
	list->next = newlist;
	list = newlist;
	return (list);
}

t_data	*ft_pre_newdata(t_data *data)
{
	t_data	*newdata;
	int		i;
	int		j;

	newdata = (t_data*)malloc(sizeof(t_data));
	if (!newdata)
		return (NULL);
	newdata->point[0] = 9;
	newdata->point[1] = 9;
	newdata->point[2] = 0;
	newdata->point[3] = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			newdata->tetr[i][j] = 'w';
		newdata->tetr[i][j] = 0;
	}
	newdata->next = NULL;
	data->next = newdata;
	newdata->before = data;
	data = newdata;
	return (data);
}
