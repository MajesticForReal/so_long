/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:56:30 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 15:06:04 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->p_position[0] / 40;
	y = (so_long->p_position[1] - 40) / 40;
	if (so_long->map[y][x] == '1')
		return ;
	if (so_long->map[y][x] == 'E' && so_long->nb_c != so_long->nb_c_p)
		return ;
	if (so_long->map[y][x] == 'C')
	{
		so_long->nb_c_p++;
		so_long->map[y][x] = '0';
	}
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_sand, so_long->p_position[0], so_long->p_position[1]);
	so_long->p_position[1] -= 40;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_perso, so_long->p_position[0], so_long->p_position[1]);
	if (so_long->map[y][x] == 'E' && so_long->nb_c == so_long->nb_c_p)
		ft_exit(so_long);
	so_long->move++;
	ft_nb_move(so_long);
}

void	move_down(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->p_position[0] / 40;
	y = (so_long->p_position[1] + 40) / 40;
	if (so_long->map[y][x] == '1')
		return ;
	if (so_long->map[y][x] == 'C')
	{
		so_long->nb_c_p++;
		so_long->map[y][x] = '0';
	}
	if (so_long->map[y][x] == 'E' && so_long->nb_c != so_long->nb_c_p)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_sand, so_long->p_position[0], so_long->p_position[1]);
	so_long->p_position[1] += 40;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_perso, so_long->p_position[0], so_long->p_position[1]);
	if (so_long->map[y][x] == 'E' && so_long->nb_c == so_long->nb_c_p)
		ft_exit(so_long);
	so_long->move++;
	ft_nb_move(so_long);
}

void	move_left(t_so_long *so_long)
{
	int	x;
	int	y;

	x = (so_long->p_position[0] - 40) / 40;
	y = so_long->p_position[1] / 40;
	if (so_long->map[y][x] == '1')
		return ;
	if (so_long->map[y][x] == 'C')
	{
		so_long->nb_c_p++;
		so_long->map[y][x] = '0';
	}
	if (so_long->map[y][x] == 'E' && so_long->nb_c != so_long->nb_c_p)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_sand, so_long->p_position[0], so_long->p_position[1]);
	so_long->p_position[0] -= 40;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_perso, so_long->p_position[0], so_long->p_position[1]);
	if (so_long->map[y][x] == 'E' && so_long->nb_c == so_long->nb_c_p)
		ft_exit(so_long);
	so_long->move++;
	ft_nb_move(so_long);
}

void	move_right(t_so_long *so_long)
{
	int	x;
	int	y;

	x = (so_long->p_position[0] + 40) / 40;
	y = so_long->p_position[1] / 40;
	if (so_long->map[y][x] == '1')
		return ;
	if (so_long->map[y][x] == 'C')
	{
		so_long->nb_c_p++;
		so_long->map[y][x] = '0';
	}
	if (so_long->map[y][x] == 'E' && so_long->nb_c != so_long->nb_c_p)
		return ;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_sand, so_long->p_position[0], so_long->p_position[1]);
	so_long->p_position[0] += 40;
	mlx_put_image_to_window(so_long->mlx, so_long->new_window,
		so_long->img_perso, so_long->p_position[0], so_long->p_position[1]);
	if (so_long->map[y][x] == 'E' && so_long->nb_c == so_long->nb_c_p)
		ft_exit(so_long);
	so_long->move++;
	ft_nb_move(so_long);
}

int	key_press(int keycode, t_so_long *so_long)
{
	if (keycode == 119)
	{
		move_up(so_long);
	}
	if (keycode == 115)
	{
		move_down(so_long);
	}
	if (keycode == 97)
	{
		move_left(so_long);
	}
	if (keycode == 100)
	{
		move_right(so_long);
	}
	if (keycode == 65307)
	{
		ft_exit(so_long);
	}
	(void)so_long;
	return (0);
}
