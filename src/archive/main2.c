/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:11:50 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/18 18:12:05 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "../libft/includes/libft.h"
#include "../includes/fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

void	plot_line(int x0, int y0, int x1, int y1, void *mlx_ptr, void *win_ptr)
{
	int dx;
	int dy;
	int e2;
	int sx;
	int sy;
	int err;

	dx = ft_abs(x1 - x0);
	dy = -ft_abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0xFFFFFF);
		if (x0 == x1 && x0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
	ft_putchar('X');
	ft_putchar('X');
	ft_putchar('X');
	ft_putchar('X');
}

/*
int		deal_key(int key, void *param)
{
	int x;
	int y;

	ft_putchar('X');

	//mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
	return (0);
}*/




int		map_dimensions(int fd)
{
	//int		x;
	//int		y;
	int		dim[2];
	char	*line;

	dim[1] = 0;
	while (get_next_line(fd, &line))
	{
		dim[0] = 0;
		while (*line)
		{
			if (*line == '-')
				line++;
			if (*line != '-' && !ft_isdigit(*line))
				return (0);
			if (ft_isdigit(*line))
			{
				dim[0]++;
				printf("%d\n", ft_atoi(line));
				while (ft_isdigit(*line))
					line++;
			}
			else
				line++;
		}
		dim[1]++;
	printf(">>>>>>>>>> %d\n", dim[1]);
	}
	return (1);
}

int		read_file(int ac, char **av)
{
	int fd;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	map_dimensions(fd);
	close(fd);

	return (0);
}


int		main(int ac, char **av)
{
	//void *mlx_ptr;
	//void *win_ptr;


	read_file(ac, av);
	//mlx_ptr = mlx_init();
	//win_ptr = mlx_new_window(mlx_ptr, 700, 700, "mlx 42");
	//mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF);
	//mlx_pixel_put(mlx_ptr, win_ptr, 150, 450, 0x00FF44);

	//plot_line(0, 0, 250, 250, mlx_ptr, win_ptr);
	//mlx_string_put(mlx_ptr, win_ptr, 50, 150, 0x00FF44, "Les choses se passnet");
	//mlx_key_hook(win_ptr, deal_key, (void *)0);
	//mlx_loop(mlx_ptr);

	return (0);
}
