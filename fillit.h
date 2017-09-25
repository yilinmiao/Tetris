/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymiao <ymiao@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 21:45:08 by ymiao             #+#    #+#             */
/*   Updated: 2017/09/21 21:45:09 by ymiao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** Global Variables;
*/

int		g_num;
char	g_letter[26];

/*
** Global Functions;
*/

typedef struct	s_data
{
	char			tetr[4][5];
	int				point[4];
	int				n;
	struct s_data	*next;
	struct s_data	*before;
}				t_data;

typedef struct	s_list
{
	char			tetr[4][5];
	struct s_list	*next;
}				t_list;

/*
** list_generator.c
*/

t_list			*new_list(void);
t_list			*generate_tetris_list(int fd);
void			define_global_variable(void);
t_data			*new_tetris(void);

/*
** c_lib.c
*/

void			ft_putchar(char c);
void			ft_putstr(char const *str);
char			*ft_strnew(size_t size);

/*
** validation.c
*/

t_list			*validate(char *str, t_list *list, int count);
int				ft_pre_buf_part2(char *buf, t_list *list, int n);
int				ft_invaild_list(t_list *list);
int				ft_invaild_list_around(t_list *list, int i, int j);

/*
** map_preparation.c
*/

int				get_min_size(int num);
char			**new_map(int mapsize);
void			print_map(char **map);

/*
** map_generator.c
*/

char			**generate_map(t_list *list);
char			**ft_putmap_check(t_data *data, char **map,
						int *i, int mapsize);
char			**try_map(t_data *data, char **map, int mapsize, int *i);
char			**ft_checkmap_samemapsize(t_data *data, int mapsize,
						char **map);
char			ft_point_check(char a_data, char b_map);

/*
** tetris_generator.c
*/

t_data			*get_tetris(t_list *list);
t_data			*get_position(t_data *data, int i, int j);
t_data			*ft_list_to_tetris(t_list *list, t_data *data, char a);

/*
** map_cleaner.c
*/

void			ft_free_map(char **map, int mapsize);
char			**ft_map_clean(char **map, int n, int mapsize);

#endif
