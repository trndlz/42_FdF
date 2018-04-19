/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/19 16:16:17 by tmervin          ###   ########.fr       */
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
	cam->tx = 0;
	cam->ty = 0;
	cam->tz = 0;
	cam->cosx = cos(cam->tx * M_PI / 180);
	cam->cosy = cos(cam->ty * M_PI / 180);
	cam->cosz = cos(cam->tz * M_PI / 180);
	cam->sinx = sin(cam->tx * M_PI / 180);
	cam->siny = sin(cam->ty * M_PI / 180);
	cam->sinz = sin(cam->tz * M_PI / 180);
	return (cam);
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

	data->cam = cam_data();
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


	mlx_clear_window(data->mlx, data->win);

	a = 5;
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



int		deal_key(int key, t_inf *data)
{
	printf("KEY: %d\n", key);
	if (key == 31) // 'o' key
	{
		mlx_clear_window(data->mlx, data->win);
		data->cam->tx += 45;
	}
	if (key == 12) // 'q' key
	{
		mlx_destroy_window(data->mlx, data->win);
	}
	test(data);
	return (0);
}









