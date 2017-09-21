/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 13:30:31 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/20 13:30:32 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		validate(char *str, int count)
{
	int i;
	int block;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (-1);
			if (str[i] == '#' && ++block > 4)
				return (-1);
		}
		else if (str[i] != '\n')
			return (-1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (-1);
	if (!valid_shape(str))
		return (-1);
	return (0);
}

int		valid_shape(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}
