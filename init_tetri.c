/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:52:45 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/19 22:52:46 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		validate(char *str, int count);

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
		if (validate(buf, count) != 0
				|| (data = get_piece(buf, cur++)) == NULL)
		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(data, sizeof(t_etris)));
		ft_memdel((void **)&data);
	}
	ft_memdel((void **)&buf);
	if (count != 0)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}
