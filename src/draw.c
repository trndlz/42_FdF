/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/20 14:47:10 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam		*cam_data(void)
{
	t_cam *cam;

	cam = malloc(sizeof(cam));
	cam->cx = -100;
	cam->cy = 300;
	cam->cz = 400;
	cam->ez = 500;
	cam->tx = 45;
	cam->ty = -10;
	cam->tz = -225;
	cam->a = 10;
	cam->b = 10;
	cam->c = 10;
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

void	display_infos(t_inf *d)
{
	mlx_string_put(d->mlx, d->win, 1700, 5, 0xFFFFFF, ft_strjoin("Cx (+T -Y) : ", ft_itoa(d->cam->cx)));
	mlx_string_put(d->mlx, d->win, 1700, 25, 0xFFFFFF, ft_strjoin("Cy (+G -H) : ", ft_itoa(d->cam->cy)));
	mlx_string_put(d->mlx, d->win, 1700, 45, 0xFFFFFF, ft_strjoin("Cz (+B -N) : ", ft_itoa(d->cam->cz)));

	mlx_string_put(d->mlx, d->win, 1700, 70, 0xFFFFFF, ft_strjoin("*x (+E -R) : ", ft_itoa(d->cam->tx)));
	mlx_string_put(d->mlx, d->win, 1700, 90, 0xFFFFFF, ft_strjoin("*y (+D -F) : ", ft_itoa(d->cam->ty)));
	mlx_string_put(d->mlx, d->win, 1700, 110, 0xFFFFFF, ft_strjoin("*z (+C -V) : ", ft_itoa(d->cam->tz)));
}

double	calc_dx(t_inf *d, int x, int y, int z)
{
	double dx;

	dx = d->cam->cosy * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx))
		- d->cam->siny * (d->cam->c * z - d->cam->cz);
	return (dx);
}

double	calc_dy(t_inf *d, int x, int y, int z)
{
	double dy;

	dy = d->cam->sinx * (d->cam->cosy * (d->cam->c * z - d->cam->cz)
		+ d->cam->siny * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx)))
		+ d->cam->cosx * (d->cam->cosz * (d->cam->b * y - d->cam->cy)
		- d->cam->sinz * (d->cam->a * x - d->cam->cx));
	return (dy);
}

double	calc_dz(t_inf *d, int x, int y, int z)
{
	double dz;
	
	dz = d->cam->cosx * (d->cam->cosy * (d->cam->c * z - d->cam->cz)
		+ d->cam->siny * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx)))
		- d->cam->sinx * (d->cam->cosz * (d->cam->b * y - d->cam->cy)
		- d->cam->sinz * (d->cam->a * x - d->cam->cx));
	return (dz);
}

double	calc_bx(t_inf *d, int x, int y, int z)
{
	double dx;
	double dz;
	double bx;

	dx = calc_dx(d, x, y, z);
	dz = calc_dz(d, x, y, z);
	bx = (d->cam->ez / dz) * dx;
	return (bx);
}

double	calc_by(t_inf *d, int x, int y, int z)
{
	double dy;
	double dz;
	double by;

	dy = calc_dy(d, x, y, z);
	dz = calc_dz(d, x, y, z);
	by = (d->cam->ez / dz) * dy;
	return (by);
}
void	place_point(t_inf *d)
{
	int x;
	int y;
	double bx;
	double by;

	calc_cosinus(d);
	mlx_clear_window(d->mlx, d->win);
	display_infos(d);
	y = 0;
	while (y < d->y)
	{
		x = 0;
		while (x < d->x)
		{
			bx = calc_bx(d, x, y, d->map[y][x]);
			by = calc_by(d, x, y, d->map[y][x]);
			mlx_pixel_put(d->mlx, d->win, bx, by, 0xFFFFFF);
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
	if (key == 17) // T
		data->cam->cx += 50;
	if (key == 5) // G
		data->cam->cy += 50;
	if (key == 11) // B
		data->cam->cz += 50;
	if (key == 16) // Y
		data->cam->cx -= 50;
	if (key == 4) // H
		data->cam->cy -= 50;
	if (key == 45) // N
		data->cam->cz -= 50;
	if (key == 14) // E
		data->cam->tx += 5;
	if (key == 2) // D
		data->cam->ty += 5;
	if (key == 8) // C
		data->cam->tz += 5;
	if (key == 15) // R
		data->cam->tx -= 5;
	if (key == 3) // F
		data->cam->ty -= 5;
	if (key == 9) // V
		data->cam->tz -= 5;
	if (key == 37) // O
		data->cam->a += 1;
	if (key == 31) // L
		data->cam->a -= 1;
	if (key == 46) // M
		data->cam->ez += 50;
	if (key == 38) // J
		data->cam->ez -= 50;
	if (key == 53) // ESC
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	test(data);
	return (0);
}









