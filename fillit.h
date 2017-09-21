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
# include <stdio.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_map
{
	int			size;
	char		**tab;
}				t_map;

typedef struct	s_data
{
	char		**tab;
	int			width;
	int			height;
	char		value;
}				t_data;

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

char			*ft_strnew(size_t size);
void			ft_putstr(char const *str);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_memdel(void **ap);
void			*ft_memalloc(int size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
t_list			*init_shape(int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstrev(t_list **alst);
int				ft_lstcount(t_list *lst);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);

int				validate(char *str, int count);
void			print_map(t_map *map);
int				place(t_data *shape, t_map *map, int x, int y);
void			set_piece(t_data *shape, t_map *map, t_point *point, char c);

t_point			*new_point(int x, int y);
t_data			*new_shape(char **tab, int width, int height, char c);
t_map			*new_map(int size);
t_map			*generate_map(t_list *list);

void			free_shape(t_data *shape);
t_list			*free_list(t_list *list);
void			free_map(t_map *map);

#endif
