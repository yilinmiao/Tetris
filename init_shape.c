/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:52:45 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/19 22:52:46 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_position(char *str, t_point *p1, t_point *p2)
{
	int i;

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
}

t_data	*get_shape(char *str, char value)
{
	t_point		*p1;
	t_point		*p2;
	char		**tab;
	t_data		*shape;
	int			i;

	p1 = new_point(3, 3);
	p2 = new_point(0, 0);
	get_position(str, p1, p2);
	tab = ft_memalloc(sizeof(char *) * (p2->x - p1->x + 1));
	i = 0;
	while (i < p2->x - p1->x + 1)
	{
		tab[i] = ft_strnew(p2->y - p1->y + 1);
		ft_strncpy(tab[i], str + (p1->y) + (i + p1->x) * 5, p2->y - p1->y + 1);
		i++;
	}
	shape = new_shape(tab, p2->y - p1->y + 1, p2->x - p1->x + 1, value);
	ft_memdel((void **)&p1);
	ft_memdel((void **)&p2);
	return (shape);
}

t_list	*init_shape(int fd)
{
	t_list	*list;
	t_data	*shape;
	char	*buf;
	char	cur;
	int		count;

	buf = ft_strnew(21);
	list = NULL;
	cur = 'A';
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (validate(buf, count) == -1
				|| (shape = get_shape(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(shape, sizeof(t_data)));
		ft_memdel((void **)&shape);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
