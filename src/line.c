/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:09:07 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/24 22:28:15 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_max(int x, int y, int z)
{
	int max = x;
	if (y > max)
		max = y;
	if (z > max)
		max = z;
	return (max);
}

int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

void	plot_line(t_inf *d, int x0, int y0, int x1, int y1, int z)
{
	int dx;
	int dy;
	int e2;
	int sx;
	int sy;
	int err;
	unsigned long iii;

	dx = ft_abs(x1 - x0);
	dy = -ft_abs(y1 - y0);
	sx = x0 < x1 ? 1 : -1;
	sy = y0 < y1 ? 1 : -1;
	err = dx + dy;
	while (1)
	{
		iii = get_color(d, z);
		mlx_pixel_put(d->mlx, d->win, x0, y0, iii);
		if (x0 == x1 && y0 == y1)
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
}

void	plot_line2(t_inf *d, t_points *p)
{
	unsigned long iii;

	p->dx = ft_abs(p->bx1 - p->bx0);
	p->dy = -ft_abs(p->by1 - p->by0);
	p->sx = p->bx0 < p->bx1 ? 1 : -1;
	p->sy = p->by0 < p->by1 ? 1 : -1;
	p->err = p->dx + p->dy;
	while (1)
	{
		printf("z0 %d / z1 %d / bx0 %d / bx1 / %d\n", p->z0, p->z1, p->by0, p->by1);
		iii = get_color(d, p->z0);
		mlx_pixel_put(d->mlx, d->win, p->bx0, p->by0, iii);
		if (p->bx0 == p->bx1 && p->by0 == p->by1)
			break ;
		p->e2 = 2 * p->err;
		if (p->e2 >= p->dy)
		{
			p->err += p->dy;
			p->bx0 += p->sx;
		}
		if (p->e2 <= p->dx)
		{
			p->err += p->dx;
			p->by0 += p->sy;
		}
	}
}

void	place_line2(t_inf *d)
{
	int x;
	int y;
	t_points *p;

	calc_cosinus(d);
	mlx_clear_window(d->mlx, d->win);
	display_infos(d);
	p = malloc(sizeof(t_points));
	y = 0;
	while (y < d->y)
	{
		x = 0;
		while (x < d->x)
		{
			p->bx0 = calc_bx(d, x, y, d->map[y][x]);
			p->by0 = calc_by(d, x, y, d->map[y][x]);
			p->z0 = d->map[y][x];
			if (x < (d->x - 1))
			{
				p->bx1 = calc_bx(d, x + 1, y, d->map[y][x + 1]);
				p->by1 = calc_by(d, x + 1, y, d->map[y][x + 1]);
				p->z1 = d->map[y][x + 1];
				plot_line2(d, p);
			}
			p->bx0 = calc_bx(d, x, y, d->map[y][x]);
			p->by0 = calc_by(d, x, y, d->map[y][x]);
			if (y < (d->y - 1))
			{
				p->bx1 = calc_bx(d, x, y + 1, d->map[y + 1][x]);
				p->by1 = calc_by(d, x, y + 1, d->map[y + 1][x]);
				p->z1 = d->map[y + 1][x];
				plot_line2(d, p);
			}
			x++;
		}
		y++;
	}
}


void	place_line(t_inf *d)
{
	int x;
	int y;
	double bx0;
	double bx1;
	double bx2;
	double by0;
	double by1;
	double by2;

	calc_cosinus(d);
	mlx_clear_window(d->mlx, d->win);
	display_infos(d);
	y = 0;
	while (y < d->y)
	{
		x = 0;
		while (x < d->x)
		{
			bx0 = calc_bx(d, x, y, d->map[y][x]);
			by0 = calc_by(d, x, y, d->map[y][x]);
			if (x < (d->x - 1))
			{
				bx1 = calc_bx(d, x + 1, y, d->map[y][x + 1]);
				by1 = calc_by(d, x + 1, y, d->map[y][x + 1]);
				plot_line(d, bx0, by0, bx1, by1, d->map[y][x]);
			}
			if (y < (d->y - 1))
			{
				bx2 = calc_bx(d, x, y + 1, d->map[y + 1][x]);
				by2 = calc_by(d, x, y + 1, d->map[y + 1][x]);
				plot_line(d, bx0, by0, bx2, by2, d->map[y][x]);
			}
			x++;
		}
		y++;
	}
}


