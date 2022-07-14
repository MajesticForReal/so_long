/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:55:47 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/27 21:59:05 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_first_line(t_so_long *so_long)
{
	int	i;

	i = 0;
	while (so_long->map[0][i] != '\n' && so_long->map[0][i])
	{
		if (so_long->map[0][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_mid_line(t_so_long *so_long)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = -1;
	while (so_long->map[++k])
		j = 0;
	k = k - 2;
	while (i <= k)
	{
		j = ft_strlen(so_long->map[i]);
		j = j - 2;
		if (so_long->map[i][0] != '1' || so_long->map[i][j] != '1')
			return (-1);
		i++;
	}
	j++;
	so_long->width_window = j * 40;
	return (0);
}

int	ft_check_last_line(t_so_long *so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long->map[++i])
		j = 0;
	i--;
	while (so_long->map[i][j] != '\n' && so_long->map[i][j])
	{
		if (so_long->map[i][j] != '1')
			return (-1);
		j++;
	}
	i++;
	so_long->height_window = i * 40;
	return (0);
}

void	ft_check_side(t_so_long *so_long)
{
	if (ft_check_first_line(so_long) == -1)
	{
		write(2, "Error\nMiss a wall on the first line\n", 36);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (ft_check_mid_line(so_long) == -1)
	{
		write(2, "Error\nMiss a wall on a mid line\n", 32);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	if (ft_check_last_line(so_long) == -1)
	{
		write(2, "Error\nMiss a wall on the last line\n", 35);
		free_str(so_long->map);
		free(so_long);
		exit(EXIT_FAILURE);
	}
	so_long->i = 0;
	so_long->j = 0;
}
