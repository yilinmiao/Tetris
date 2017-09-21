/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 22:30:46 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/19 22:30:47 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

typedef struct	s_data
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_data;

char			*ft_strnew(size_t size);
void			ft_putstr(char const *str);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_memdel(void **ap);
void			*ft_memalloc(size_t size);
t_list			*init_data(int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);

int				validate(char *str, int count);
int				valid_tetrimino(char *str);
void			print_map(t_map *map);
int				place(t_etris *tetri, t_map *map, int x, int y);
void			set_piece(t_etris *tetri, t_map *map, t_point *point, char c);

t_point			*new_point(int x, int y);
t_etris			*new_tetris(char **pos, int width, int height, char c);
t_map			*map_new(int size);
t_map			*solve(t_list *list);

void			free_tetris(t_etris *tetri);
t_list			*free_list(t_list *list);
void			free_map(t_map *map);

#endif