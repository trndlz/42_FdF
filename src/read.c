/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:31:41 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/20 08:56:47 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		str_check(char *s)
{
	while (*s)
	{
		if (*s != '-' && !ft_isdigit(*s))
			return (-1);
		s++;
	}
	return (1);
}

void	printdata(t_inf *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			printf("%d", data->map[y][x]);
			x++;
		}
		y++;
	}
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
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	return (1);
}

int		fill_map(t_inf *data)
{
	int		x;
	int		y;
	char	**str;
	char	*line;

	if (!(data->map = (int**)malloc(sizeof(int*) * data->y)))
		return (-1);
	y = 0;
	while ((get_next_line(data->fd, &line)) == 1)
	{
		x = 0;
		if (!(data->map[y] = (int*)malloc(sizeof(int) * data->x)))
			return (-1);
		str = ft_strsplit(line, ' ');
		while (str[x])
		{
			data->map[y][x] = ft_atoi(str[x]);
			//printf("%d\t%d\t%d\n", x, y, data->map[y][x]);
			free(str[x]);
			x++;
		}
		y++;
		free(str);
		free(line);
	}
	return (1);
}
