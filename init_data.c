/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:52:45 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/19 22:52:46 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_data	*get_tetrip1o(char *str, char value);
void	get_size(char *str, t_point *min, t_point *p2);


t_list	*init_data(int fd)
{
	t_list	*list;
	t_data	*data;
	char	*buf;
	char	cur;
	int		count;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (validate(buf, count) == -1
				|| (data = get_tetrimino(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(data, sizeof(t_data)));
		ft_memdel((void **)&data);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}

t_data	*get_tetrimino(char *str, char value)
{
	t_point		*p1;
	t_point		*p2;
	char		**pos;
	int			i;
	t_data		*data;

	p1 = new_point(3, 3);
	p2 = new_point(0, 0);
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (p1->x > i / 5)
				p1->x = i / 5;
			if (p2->x < i / 5)
				p2->x = i / 5;
			if (p1->y > i % 5)
				p1->y = i % 5;
			if (p2->y < i % 5)
				p2->y = i % 5;
		}
		i++;
	}
	pos = ft_memalloc(sizeof(char *) * (p2->x - p1->x + 1));
	i = 0;
	while (i < p2->x - p1->x + 1)
	{
		pos[i] = ft_strnew(p2->y - p1->y + 1);
		ft_strncpy(pos[i], str + (p1->y) + (i + p1->x) * 5, p2->y - p1->y + 1);
		i++;
	}
	data = new_tetris(pos, p2->y - p1->y + 1, p2->x - p1->x + 1, value);
	ft_memdel((void **)&p1);
	ft_memdel((void **)&p2);
	return (data);
}
