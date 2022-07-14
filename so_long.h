/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:54:15 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 22:05:03 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_so_long
{
	char	**map;
	char	*map_gnl;
	int		i;
	int		j;
	int		k;
	int		width;
	int		height;
	int		x;
	int		y;
	void	*img_perso;
	void	*img_coeur;
	void	*img_exit;
	void	*img_sand;
	void	*img_wall;
	void	*mlx;
	void	*new_window;
	int		width_window;
	int		height_window;
	int		p_position[2];
	int		nb_c;
	int		nb_c_p;
	int		nb_p;
	int		nb_e;
	int		move;
}			t_so_long;

int			ft_malloc_map_2(t_so_long *so_long);
int			key_press(int keycode, t_so_long *so_long);
int			ft_check_img(void);
int			ft_exit(t_so_long *so_long);
int			ft_strlen(char *str);
int			ft_malloc_map(t_so_long *so_long);
int			ft_check_first_line(t_so_long *so_long);
int			ft_open_and_gnl(char **argv, t_so_long *so_long);
int			ft_check_mid_line(t_so_long *so_long);
int			ft_check_last_line(t_so_long *so_long);

char		*gnl(char **argv);

void		ft_parsing2(t_so_long *so_long);
void		ft_check_all(char **argv, t_so_long *so_long);
void		ft_check_argc(int argc);
void		ft_check_inside2(t_so_long *so_long);
void		ft_init_window2(t_so_long *so_long, int i, int j);
void		ft_nb_move(t_so_long *so_long);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		move_up(t_so_long *so_long);
void		move_down(t_so_long *so_long);
void		move_left(t_so_long *so_long);
void		move_right(t_so_long *so_long);
void		ft_put_img(t_so_long *so_long, void *img, char c);
void		ft_init_window(t_so_long *so_long);
void		free_str(char **s);
void		ft_check_inside(t_so_long *so_long);
void		ft_check_side(t_so_long *so_long);
void		ft_get_img(t_so_long *so_long);
void		ft_parsing(char **argv, t_so_long *so_long);
void		ft_fill_map(t_so_long *so_long);
void		ft_bzero(void *s, size_t n);
void		ft_check_size(t_so_long *so_long);

#endif
