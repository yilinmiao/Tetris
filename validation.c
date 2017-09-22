/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 22:25:40 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 22:25:41 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*ft_pre_buf(char *buf, t_list *list, int ret)
{
	int n;

	n = 0;
	if (list == NULL)
		return (NULL);
	if ((buf[4] != '\n') || (buf[9] != '\n')
			|| (buf[14] != '\n') || (buf[19] != '\n'))
		return (NULL);
	if ((ret == 21) && (buf[20] != '\n'))
		return (NULL);
	if (!ft_pre_buf_part2(buf, list, n))
		return (NULL);
	if (ft_invaild_list(list) == 0)
		return (NULL);
	return (list);
}

int		ft_pre_buf_part2(char *buf, t_list *list, int n)
{
	int		i;
	int		j;
	int		z;

	i = -1;
	z = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if ((z == 4) || (z == 9) || (z == 14))
				z++;
			if (buf[z] != '#' && buf[z] != '.')
				return (0);
			list->tetr[i][j] = buf[z];
			if (list->tetr[i][j] == '#')
				n++;
			z++;
		}
	}
	if (n != 4)
		return (0);
	return (1);
}

int		ft_invaild_list_around(t_list *list, int i, int j)
{
	int n;

	n = 0;
	if (list->tetr[i - 1][j] == '#')
		n++;
	if (list->tetr[i + 1][j] == '#')
		n++;
	if (list->tetr[i][j + 1] == '#')
		n++;
	if (list->tetr[i][j - 1] == '#')
		n++;
	return (n);
}

int		ft_invaild_list(t_list *list)
{
	int i;
	int j;
	int n;
	int temp;

	n = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (list->tetr[i][j] == '#')
			{
				temp = 0;
				if (!(temp = ft_invaild_list_around(list, i, j)))
					return (0);
				if (temp == 1)
					n++;
			}
		}
	}
	if (n == 4)
		return (0);
	return (1);
}

char	ft_point_check(char a_data, char b_map)
{
	if (b_map != '.' && a_data != '.')
		return (0);
	if (b_map != '.' && a_data == '.')
		return (b_map);
	else
		return (a_data);
}
