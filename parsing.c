/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:53:29 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 21:49:53 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_size(t_so_long *so_long)
{
	int	j;
	int	i;
	int	k;
	int	l;

	i = 0;
	j = 1;
	k = 0;
	while (so_long->map[j])
	{
		l = ft_strlen(so_long->map[j]);
		if (so_long->map[j][l] == '\0' && so_long->map[j][l - 1] != '\n')
			k++;
		if (ft_strlen(so_long->map[i]) == (k + l))
			j++;
		else
		{
			write(2, "Error\nMap is not rectangle\n", 27);
			free_str(so_long->map);
			free(so_long);
			exit(EXIT_FAILURE);
		}
	}
	return ;
}

void	ft_check_inside2(t_so_long *so_long)
{
	so_long->j = 0;
	while (so_long->map[so_long->i][so_long->j])
	{
		if (so_long->map[so_long->i][so_long->j] == 'P')
			so_long->nb_p++;
		else if (so_long->map[so_long->i][so_long->j] == 'E')
			so_long->nb_e++;
		else if (so_long->map[so_long->i][so_long->j] == 'C')
			so_long->nb_c++;
		if (so_long->map[so_long->i][so_long->j] != 'P'
			&& so_long->map[so_long->i][so_long->j] != 'E'
			&& so_long->map[so_long->i][so_long->j] != 'C'
			&& so_long->map[so_long->i][so_long->j] != '0'
			&& so_long->map[so_long->i][so_long->j] != '1'
			&& so_long->map[so_long->i][so_long->j] != '\n')
		{
			write(2, "Error\nMap contains a forbidden character\n", 42);
			free_str(so_long->map);
			free(so_long);
			exit(EXIT_FAILURE);
		}
		so_long->j++;
	}
	so_long->i++;
}

void	ft_check_inside(t_so_long *so_long)
{
	while (so_long->map[so_long->i])
		ft_check_inside2(so_long);
	if (so_long->nb_p != 1)
	{
		write(2, "Error\nToo many character on the map\n", 36);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (so_long->nb_e < 1)
	{
		write(2, "Error\nMiss 1 exit on the map\n", 29);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (so_long->nb_c < 1)
	{
		write(2, "Error\nMiss 1 exit on the map\n", 29);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
}

int	ft_open_and_gnl(char **argv, t_so_long *so_long)
{
	so_long->map_gnl = gnl(argv);
	if (!so_long->map_gnl)
	{
		write(2, "Error\nOpen has failed or empty map\n", 35);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(so_long->map_gnl) < 17)
	{
		write(2, "Error\nMap is too small\n", 23);
		free(so_long->map_gnl);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	return (0);
}
