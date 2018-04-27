/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:09:07 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/27 15:36:33 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	plot_image(t_inf *d, t_points *p)
{
	p->dx = abs(p->bx1 - p->bx0);
	p->dy = -abs(p->by1 - p->by0);
	p->sx = p->bx0 < p->bx1 ? 1 : -1;
	p->sy = p->by0 < p->by1 ? 1 : -1;
	p->err = p->dx + p->dy;
	while (1)
	{
		p->color = get_color(d, p->z0 > p->z1 ? p->z1 : p->z0);
		if (p->bx0 >= 0 && p->by0 >= 0 && p->bx0 < WIN_WIDTH &&
				p->by0 < WIN_HEIGHT)
			d->imgstr[p->bx0 + p->by0 * WIN_WIDTH] = (int)p->color;
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
	plot_image(d, p);
}

void	calc_data_down(t_inf *d, t_points *p, int x, int y)
{
	p->bx0 = calc_bx(d, x, y, d->map[y][x]);
	p->by0 = calc_by(d, x, y, d->map[y][x]);
	p->bx1 = calc_bx(d, x, y + 1, d->map[y + 1][x]);
	p->by1 = calc_by(d, x, y + 1, d->map[y + 1][x]);
	p->z0 = d->map[y][x];
	p->z1 = d->map[y + 1][x];
	plot_image(d, p);
}

void	create_image(t_inf *d)
{
	calc_cosinus(d);
	d->image = mlx_new_image(d->mlx, WIN_WIDTH, WIN_HEIGHT);
	d->imgstr = (int *)mlx_get_data_addr(d->image, &d->bpp,
			&d->s_l, &d->endian);
	fill_image(d);
	mlx_put_image_to_window(d->mlx, d->win, d->image, 0, 0);
	display_infos(d);
	display_infos2(d);
	display_infos3(d);
	mlx_destroy_image(d->mlx, d->image);
	mlx_loop(d->mlx);
}

void	fill_image(t_inf *d)
{
	int			x;
	int			y;
	t_points	*p;

	if (!(p = malloc(sizeof(t_points))))
		return ;
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
	free(p);
}
