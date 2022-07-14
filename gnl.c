/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:58:36 by anrechai          #+#    #+#             */
/*   Updated: 2022/06/21 19:15:49 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_line(int fd, int size_malloc)
{
	char	*str;
	int		read_buffer;
	int		j;
	char	*buff;

	j = 0;
	read_buffer = 1;
	str = (char *)malloc(sizeof(char) * size_malloc + 1);
	buff = (char *)malloc(sizeof(char) * 1);
	if (str == NULL || buff == NULL)
	{
		free(buff);
		free(str);
		return (NULL);
	}
	while (read_buffer > 0)
	{
		read_buffer = read(fd, buff, 1);
		str[j] = buff[0];
		j++;
	}
	free(buff);
	str[j - 1] = '\0';
	return (str);
}

static int	ft_size(int fd)
{
	char	*buff;
	int		read_buffer;
	int		j;

	j = 0;
	buff = (char *)malloc(sizeof(char) * 1);
	if (buff == NULL)
		return (0);
	read_buffer = 1;
	while (read_buffer > 0)
	{
		read_buffer = read(fd, buff, 1);
		if (read_buffer == -1 || buff[0] < 0 || buff[0] > 126)
		{
			free(buff);
			return (-1);
		}
		j++;
	}
	close(fd);
	free(buff);
	return (j);
}

static int	ft_empty_files(int fd)
{
	char	*buff;

	buff = (char *)malloc(sizeof(char) * 1);
	if (!buff)
		return (1);
	if (read(fd, buff, 1) == 0)
	{
		free(buff);
		return (1);
	}
	else
	{
		free(buff);
		return (0);
	}
}

char	*gnl(char **argv)
{
	char	*str;
	int		fd;
	int		size_malloc;

	str = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	if (ft_empty_files(fd) == 1)
	{
		close(fd);
		return (NULL);
	}
	size_malloc = ft_size(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (NULL);
	str = ft_line(fd, size_malloc);
	close(fd);
	return (str);
}
