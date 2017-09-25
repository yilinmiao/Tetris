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

t_list	*validate(char *str, t_list *list, int count)
{
	int n;

	n = 0;
	if (list == NULL)
		return (NULL);
	if ((str[4] != '\n') || (str[9] != '\n')
			|| (str[14] != '\n') || (str[19] != '\n'))
		return (NULL);
	if ((count == 21) && (str[20] != '\n'))
		return (NULL);
	if (!ft_pre_buf_part2(str, list, n))
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
