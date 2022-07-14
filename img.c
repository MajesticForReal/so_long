/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:59:34 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 21:56:28 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_img(void)
{
	int	fd;

	fd = open("./image/coeur.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open("./image/exit.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open("./image/perso.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open("./image/sand.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	fd = open("./image/wall.xpm", O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

void	ft_get_img(t_so_long *so_long)
{
	so_long->img_coeur = mlx_xpm_file_to_image(so_long->mlx,
			"./image/coeur.xpm",
			&so_long->width,
			&so_long->height);
	so_long->img_wall = mlx_xpm_file_to_image(so_long->mlx, "./image/wall.xpm",
			&so_long->width, &so_long->height);
	so_long->img_perso = mlx_xpm_file_to_image(so_long->mlx,
			"./image/perso.xpm",
			&so_long->width,
			&so_long->height);
	so_long->img_exit = mlx_xpm_file_to_image(so_long->mlx, "./image/exit.xpm",
			&so_long->width, &so_long->height);
	so_long->img_sand = mlx_xpm_file_to_image(so_long->mlx, "./image/sand.xpm",
			&so_long->width, &so_long->height);
	if (so_long->img_coeur == NULL || so_long->img_exit == NULL
		|| so_long->img_perso == NULL || so_long->img_sand == NULL
		|| so_long->img_wall == NULL)
	{
		write(2, "Error\nMiss an img\n", 18);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_put_img(t_so_long *so_long, void *img, char c)
{
	mlx_put_image_to_window(so_long->mlx, so_long->new_window, img, so_long->x,
		so_long->y);
	if (c == 'P')
	{
		so_long->p_position[0] = so_long->x;
		so_long->p_position[1] = so_long->y;
	}
	so_long->x += 40;
}

void	ft_init_window2(t_so_long *so_long, int i, int j)
{
	while (so_long->map[i][j])
	{
		if (so_long->map[i][j] == 'P')
			ft_put_img(so_long, so_long->img_perso, 'P');
		if (so_long->map[i][j] == 'E')
			ft_put_img(so_long, so_long->img_exit, 'E');
		if (so_long->map[i][j] == 'C')
			ft_put_img(so_long, so_long->img_coeur, 'C');
		if (so_long->map[i][j] == '0')
			ft_put_img(so_long, so_long->img_sand, '0');
		if (so_long->map[i][j] == '1')
			ft_put_img(so_long, so_long->img_wall, '1');
		if (so_long->map[i][j] == '\n')
		{
			so_long->x = 0;
			so_long->y += 40;
		}
		j++;
	}
}

void	ft_init_window(t_so_long *so_long)
{
	int	i;
	int	j;

	i = 0;
	so_long->new_window = mlx_new_window(so_long->mlx, so_long->width_window,
			so_long->height_window, "so_long");
	while (so_long->map[i])
	{
		j = 0;
		ft_init_window2(so_long, i, j);
		i++;
	}
}
