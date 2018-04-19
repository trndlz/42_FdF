/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/19 17:21:24 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cam		*cam_data(void)
{
	t_cam *cam;

	cam = malloc(sizeof(cam));
	cam->cx = 100;
	cam->cy = 100;
	cam->cz = 100;
	cam->ex = -100;
	cam->ey = -200;
	cam->ez = 100;
	cam->tx = 70;
	cam->ty = 0;
	cam->tz = 0;
	return (cam);
}

void	calc_cosinus(t_inf *data)
{
	data->cam->cosx = cos(data->cam->tx * M_PI / 180);
	data->cam->cosy = cos(data->cam->ty * M_PI / 180);
	data->cam->cosz = cos(data->cam->tz * M_PI / 180);
	data->cam->sinx = sin(data->cam->tx * M_PI / 180);
	data->cam->siny = sin(data->cam->ty * M_PI / 180);
	data->cam->sinz = sin(data->cam->tz * M_PI / 180);
}

int		expose_hook(t_inf *data)
{
	if (!data)
		return (-1);
	return (0);
}

void	test(t_inf *data)
{
	int x;
	int y;
	int z;
	double cosx;
	double cosy;
	double cosz;
	double sinx;
	double siny;
	double sinz;
	int cx;
	int cy;
	int cz;
	int ex;
	int ey;
	int ez;
	int a;
	double dx;
	double dy;
	double dz;
	double bx;
	double by;

	calc_cosinus(data);
	cosx = data->cam->cosx;
	cosy = data->cam->cosy;
	cosz = data->cam->cosz;
	sinx = data->cam->sinx;
	siny = data->cam->siny;
	sinz = data->cam->sinz;
	cx = data->cam->cx;
	cy = data->cam->cy;
	cz = data->cam->cz;
	ex = data->cam->ex;
	ey = data->cam->ey;
	ez = data->cam->ez;


	printf("%d\n", data->cam->tx);

	a = 1;
	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			z = data->map[y][x];
			dx = cosy * (sinz * (a * y - cy) + cosz * (a * x - cx)) - siny * (a * z - cz);
			dy = sinx * (cosy * (a * z - cz) + siny * (sinz * (a * y - cy) + cosz * (a * x - cx)))
					+ cosx * (cosz * (a * y - cy) - sinz * (a * x - cx));
			dz = cosx * (cosy * (a * z - cz) + siny * (sinz * (a * y - cy) + cosz * (a * x - cx)))
					- sinx * (cosz * (a * y - cy) - sinz * (a * x - cx));
			bx = (ez / dz) * dx - ex;
			by = (ez / dz) * dy - ey;
			mlx_pixel_put(data->mlx, data->win, bx, by, 0xFFFFFF);
			//printf("bx: %f\tby: %f\n", bx, by);
			x++;
		}
		y++;
	}
}

void	change(t_inf *data)
{
	data->cam->tx += 30;
}

int		deal_key(int key, t_inf *data)
{
	printf("KEY: %d\n", key);
	if (key == 31) // 'o' key
	{
		data->cam->tx += 45;
	}
	if (key == 12) // 'q' key
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	test(data);
	return (0);
}









