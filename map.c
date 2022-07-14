/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:58:50 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 21:47:52 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_malloc_map_2(t_so_long *so_long)
{
	int	i;

	i = -1;
	while (so_long->map_gnl[++i] != '\0')
	{
		if (so_long->map_gnl[i] != '\n')
			so_long->j++;
		else
		{
			so_long->map[so_long->k] = malloc(sizeof(char) * (so_long->j + 1));
			if (!so_long->map[so_long->k])
				return (-1);
			so_long->j = 1;
			so_long->k++;
		}
	}
	if (so_long->map_gnl[i] == '\0' && so_long->map_gnl[i - 1] != '\n')
	{
		so_long->map[so_long->k] = malloc(sizeof(char) * so_long->j);
		if (!so_long->map[so_long->k])
			return (-1);
	}
	so_long->k = 0;
	return (0);
}

int	ft_malloc_map(t_so_long *so_long)
{
	int	i;

	i = ft_strlen(so_long->map_gnl);
	if (so_long->map_gnl[i] == '\0' && so_long->map_gnl[i - 1] != '\n')
		so_long->j++;
	i = -1;
	while (so_long->map_gnl[++i] != '\0')
		if (so_long->map_gnl[i] == '\n')
			so_long->j++;
	so_long->map = malloc(sizeof(char *) * (so_long->j + 1));
	if (!so_long->map)
		return (-1);
	so_long->k = 0;
	so_long->j = 1;
	so_long->i = 0;
	return (0);
}

void	ft_fill_map(t_so_long *so_long)
{
	while (so_long->map_gnl[so_long->i])
	{
		while (so_long->map_gnl[so_long->i] != '\n'
			&& so_long->map_gnl[so_long->i] != '\0')
		{
			so_long->map[so_long->j][so_long->k] = so_long->map_gnl[so_long->i];
			so_long->i++;
			so_long->k++;
		}
		so_long->map[so_long->j][so_long->k] = so_long->map_gnl[so_long->i];
		if (so_long->map_gnl[so_long->i] == '\0' && so_long->map_gnl[so_long->i
				- 1] != '\n')
		{
			so_long->map[so_long->j][so_long->k] = '\0';
			so_long->j++;
			break ;
		}
		so_long->map[so_long->j][so_long->k + 1] = '\0';
		so_long->k++;
		so_long->i++;
		so_long->j++;
		so_long->k = 0;
	}
	so_long->map[so_long->j] = NULL;
}
