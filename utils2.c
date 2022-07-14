/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:57:37 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 14:58:28 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		if (n < 10)
			ft_putchar_fd(n + '0', fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}

int	ft_exit(t_so_long *so_long)
{
	if (so_long->map[so_long->p_position[1] / 40][so_long->p_position[0]
		/ 40] == 'E' && so_long->nb_c == so_long->nb_c_p)
	{
		so_long->move++;
		ft_nb_move(so_long);
	}
	free_str(so_long->map);
	mlx_destroy_image(so_long->mlx, so_long->img_coeur);
	mlx_destroy_image(so_long->mlx, so_long->img_perso);
	mlx_destroy_image(so_long->mlx, so_long->img_exit);
	mlx_destroy_image(so_long->mlx, so_long->img_sand);
	mlx_destroy_image(so_long->mlx, so_long->img_wall);
	mlx_destroy_window(so_long->mlx, so_long->new_window);
	mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
	free(so_long);
	exit(EXIT_SUCCESS);
}

void	ft_nb_move(t_so_long *so_long)
{
	ft_putstr_fd("Nombre de deplacement : ", 1);
	ft_putnbr_fd(so_long->move, 1);
	ft_putstr_fd("\n", 1);
	return ;
}
