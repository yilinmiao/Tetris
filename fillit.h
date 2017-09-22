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
t_list			*generate_tetris_list(char *filename, t_list *list);

/*
** preparation.c
*/

void			define_global_variable(void);

/*
** c_lib.c
*/

void			ft_putchar(char c);
void			ft_putstr(char const *str);

/*
** ft_pre_list.c
*/
t_data			*new_tetris(void);
t_list			*ft_pre_newlist(t_list *list);

int				ft_invaild_list(t_list *list);

int				ft_pre_buf_part2(char *buf, t_list *list, int n);

t_list			*ft_pre_buf(char *buf, t_list *list, int ret);

char			*ft_strnew(size_t size);

t_list			*ft_pre_readfile(t_list *list, int fd);

/*
** ft_list_to_data.c
*/

t_data			*ft_pre_newdata(t_data *data);

t_data			*ft_list_to_data_point(t_data *data, int i, int j);

t_data			*ft_list_to_data(t_list *list, t_data *data, char a);

t_data			*ft_give_me_data(t_list *list, t_data *data);

/*
** ft_slover.c
*/

int				ft_minmapsize(int num);

char			**ft_init_map(int mapsize);

void			ft_free_map(char **map, int mapsize);

char			ft_point_check(char a_data, char b_map);

char			**ft_map_clean(char **map, int n, int mapsize);

char			**ft_putmap_check(t_data *data, char **map,
						int *i, int mapsize);

char			**ft_try_map(t_data *data, char **map, int mapsize, int *i);

char			**ft_checkmap_samemapsize(t_data *data, int mapsize,
						char **map);

char			**generate_map(t_list *list, t_data *data);

/*
** fillit.c
*/

void			print_map(char **map);

void			ft_fillit(int argc, char **argv);

#endif
