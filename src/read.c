/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:31:41 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/27 15:28:57 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_check(char *s)
{
	while (*s)
	{
		if (*s != '-' && !ft_isdigit(*s))
			return (0);
		s++;
	}
	return (1);
}

int		get_map_info(t_inf *data)
{
	char	*line;
	char	**str;
	int		x;

	data->y = 0;
	while ((get_next_line(data->fd, &line)) == 1)
	{
		x = 0;
		str = ft_strsplit(line, ' ');
		while (str[x])
		{
			if (!str_check(str[x]))
				return (-1);
			free(str[x]);
			x++;
		}
		free(str);
		free(line);
		data->y++;
		data->x = x;
	}
	free(line);
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	return (1);
}

void	z_limits(t_inf *d)
{
	int x;
	int y;

	d->z_max = d->map[0][0];
	d->z_min = 0;
	y = 0;
	while (y < d->y)
	{
		x = 0;
		while (x < d->x)
		{
			if (d->map[y][x] > d->z_max)
				d->z_max = d->map[y][x];
			if (d->map[y][x] < d->z_min)
				d->z_min = d->map[y][x];
			x++;
		}
		y++;
	}
}

int		fill_map(t_inf *data)
{
	int		x;
	int		y;
	char	**str;
	char	*line;

	if (!(data->map = (int**)malloc(sizeof(int*) * data->y)))
		return (-1);
	y = -1;
	while ((get_next_line(data->fd, &line)) == 1)
	{
		x = -1;
		if (!(data->map[++y] = (int*)malloc(sizeof(int) * data->x)))
			return (-1);
		str = ft_strsplit(line, ' ');
		while (str[++x])
		{
			data->map[y][x] = ft_atoi(str[x]);
			free(str[x]);
		}
		free(str);
		free(line);
	}
	free(line);
	close(data->fd);
	return (1);
}

void	free_map(t_inf *data)
{
	int y;

	y = 0;
	while (y < data->y)
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
}
