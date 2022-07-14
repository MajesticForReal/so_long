/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:53:50 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 22:00:58 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_parsing2(t_so_long *so_long)
{
	if (ft_malloc_map(so_long) == -1)
	{
		write(2, "Error\nMalloc has failed\n", 24);
		free(so_long->map_gnl);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (ft_malloc_map_2(so_long) == -1)
	{
		write(2, "Error\nMalloc has failed\n", 24);
		free(so_long->map_gnl);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_parsing(char **argv, t_so_long *so_long)
{
	int	i;

	i = ft_strlen(argv[1]);
	i--;
	if (argv[1][i] != 'r' || argv[1][i - 1] != 'e' || argv[1][i - 2] != 'b'
		|| argv[1][i - 3] != '.')
	{
		write(2, "Error\nThis is not a .ber map\n", 29);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	ft_open_and_gnl(argv, so_long);
	ft_parsing2(so_long);
	so_long->j = 0;
	ft_fill_map(so_long);
	free(so_long->map_gnl);
	return ;
}

void	ft_check_all(char **argv, t_so_long *so_long)
{
	ft_parsing(argv, so_long);
	ft_check_size(so_long);
	ft_check_side(so_long);
	ft_check_inside(so_long);
	if (ft_check_img() == -1)
	{
		write(2, "Error\nMiss an img or an open failed\n", 36);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	return ;
}

void	ft_check_argc(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		exit(EXIT_FAILURE);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_so_long	*so_long;

	ft_check_argc(argc);
	so_long = malloc(sizeof(t_so_long));
	ft_bzero(so_long, sizeof(t_so_long));
	if (!so_long)
		return (-1);
	ft_check_all(argv, so_long);
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
	{
		write(2, "Error\nMlx init failed\n", 22);
		free_str(so_long->map);
		free(so_long);
		return (-1);
	}
	ft_get_img(so_long);
	ft_init_window(so_long);
	mlx_hook(so_long->new_window, 17, 1L << 17, ft_exit, so_long);
	mlx_hook(so_long->new_window, 2, 1L << 0, key_press, so_long);
	mlx_loop(so_long->mlx);
	return (0);
}
