/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:09:07 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/26 14:01:22 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int i)
{
	return (i < 0 ? -i : i);
}

void	plot_line(t_inf *d, t_points *p)
{
	p->dx = ft_abs(p->bx1 - p->bx0);
	p->dy = -ft_abs(p->by1 - p->by0);
	p->sx = p->bx0 < p->bx1 ? 1 : -1;
	p->sy = p->by0 < p->by1 ? 1 : -1;
	p->err = p->dx + p->dy;
	while (1)
	{
		p->color = get_color(d, p->z0 > p->z1 ? p->z1 : p->z0);
		mlx_pixel_put(d->mlx, d->win, p->bx0, p->by0, p->color);
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

void	calc_data_right(t_inf *d, t_points *p, int x, int y)
{
	p->bx0 = calc_bx(d, x, y, d->map[y][x]);
	p->by0 = calc_by(d, x, y, d->map[y][x]);
	p->bx1 = calc_bx(d, x + 1, y, d->map[y][x + 1]);
	p->by1 = calc_by(d, x + 1, y, d->map[y][x + 1]);
	p->z0 = d->map[y][x];
	p->z1 = d->map[y][x + 1];
	plot_line(d, p);
}

void	calc_data_down(t_inf *d, t_points *p, int x, int y)
{
	p->bx0 = calc_bx(d, x, y, d->map[y][x]);
	p->by0 = calc_by(d, x, y, d->map[y][x]);
	p->bx1 = calc_bx(d, x, y + 1, d->map[y + 1][x]);
	p->by1 = calc_by(d, x, y + 1, d->map[y + 1][x]);
	p->z0 = d->map[y][x];
	p->z1 = d->map[y + 1][x];
	plot_line(d, p);
}

void	place_line(t_inf *d)
{
	int			x;
	int			y;
	t_points	*p;

	calc_cosinus(d);
	mlx_clear_window(d->mlx, d->win);
	display_infos(d);
	display_infos2(d);
	display_infos3(d);
	p = malloc(sizeof(t_points));
	y = 0;
	while (y < d->y)
	{
		x = 0;
		while (x < d->x)
		{
			if (x < (d->x - 1))
				calc_data_right(d, p, x, y);
			if (y < (d->y - 1))
				calc_data_down(d, p, x, y);
			x++;
		}
		y++;
	}
}
