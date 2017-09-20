/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:30:20 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/20 11:30:21 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*free_list(t_list *list)
{
	t_data	*data;
	t_list	*next;

	while (list)
	{
		data = (t_data *)list->content;
		next = list->next;
		free_data(data);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
