/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:01:33 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/26 14:03:30 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_infos(t_inf *d)
{
	char *cx;
	char *cy;
	char *cz;
	char *tx;

	cx = ft_itoa(d->cam->cx);
	cy = ft_itoa(d->cam->cy);
	cz = ft_itoa(d->cam->cz);
	tx = ft_itoa(d->cam->tx);
	mlx_string_put(d->mlx, d->win, 1700, 5, 0xC8C8C8, "> CAM POSITION (PX)");
	mlx_string_put(d->mlx, d->win, 1750, 25, 0xFFFFFF, "X AXIS (S / W) : ");
	mlx_string_put(d->mlx, d->win, 1920, 25, 0xFFFFFF, cx);
	mlx_string_put(d->mlx, d->win, 1750, 45, 0xFFFFFF, "Y AXIS (A / D) : ");
	mlx_string_put(d->mlx, d->win, 1920, 45, 0xFFFFFF, cy);
	mlx_string_put(d->mlx, d->win, 1750, 65, 0xFFFFFF, "Z AXIS (Q / E) : ");
	mlx_string_put(d->mlx, d->win, 1920, 65, 0xFFFFFF, cz);
	mlx_string_put(d->mlx, d->win, 1700, 85, 0xC8C8C8, "> CAM ROTATION (DEG)");
	mlx_string_put(d->mlx, d->win, 1750, 105, 0xFFFFFF, "X AXIS (I / K) : ");
	mlx_string_put(d->mlx, d->win, 1920, 105, 0xFFFFFF, tx);
	free(cx);
	free(cy);
	free(cz);
	free(tx);
}

void	display_infos2(t_inf *d)
{
	char *tz;
	char *ty;
	char *a;

	ty = ft_itoa(d->cam->ty);
	tz = ft_itoa(d->cam->tz);
	a = ft_itoa(d->cam->a);
	mlx_string_put(d->mlx, d->win, 1750, 145, 0xFFFFFF, "Z AXIS (U / O) : ");
	mlx_string_put(d->mlx, d->win, 1920, 145, 0xFFFFFF, tz);
	mlx_string_put(d->mlx, d->win, 1700, 165, 0xC8C8C8, "> STRETCH (SIZE + X)");
	mlx_string_put(d->mlx, d->win, 1750, 185, 0xFFFFFF, "X AXIS (4 / 1) : ");
	mlx_string_put(d->mlx, d->win, 1920, 185, 0xFFFFFF, a);
	mlx_string_put(d->mlx, d->win, 1700, 285, 0xC8C8C8, "> COLORS");
	mlx_string_put(d->mlx, d->win, 1750, 305, get_color(d, d->z_min),
			"MIN HEIGHT");
	mlx_string_put(d->mlx, d->win, 1750, 325, get_color(d, d->z_max),
			"MAX HEIGHT");
	mlx_string_put(d->mlx, d->win, 1750, 125, 0xFFFFFF, "Y AXIS (J / L) : ");
	mlx_string_put(d->mlx, d->win, 1920, 125, 0xFFFFFF, ty);
	mlx_string_put(d->mlx, d->win, 10, 5, 0xC8C8C8, "EXIT : ESC");
	free(tz);
	free(ty);
	free(a);
}

void	display_infos3(t_inf *d)
{
	char *b;
	char *c;
	char *ez;

	b = ft_itoa(d->cam->b);
	c = ft_itoa(d->cam->c);
	ez = ft_itoa(d->cam->ez);
	mlx_string_put(d->mlx, d->win, 1750, 205, 0xFFFFFF, "Y AXIS (5 / 2) : ");
	mlx_string_put(d->mlx, d->win, 1920, 205, 0xFFFFFF, b);
	mlx_string_put(d->mlx, d->win, 1750, 225, 0xFFFFFF, "Z AXIS (6 / 3) : ");
	mlx_string_put(d->mlx, d->win, 1920, 225, 0xFFFFFF, c);
	mlx_string_put(d->mlx, d->win, 1700, 245, 0xC8C8C8, "> FIELD OF VIEW (PX)");
	mlx_string_put(d->mlx, d->win, 1750, 265, 0xFFFFFF, "Z AXIS (- / +) : ");
	mlx_string_put(d->mlx, d->win, 1920, 265, 0xFFFFFF, ez);
	free(b);
	free(c);
	free(ez);
}

void	ft_usage(void)
{
	ft_putstr("Usage: ./fdf <mapname.fdf>\nColor option: ./fdf <mapname.fdf> ");
	ft_putstr("[Rmin.Gmin.Bmin Rmax.Gmax.Bmax]\n");
	exit(1);
}

void	ft_color_range(void)
{
	ft_putstr("Error: Individual colors must be	 between 0 and 255\n");
	exit(1);
}
