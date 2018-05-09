/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 16:24:56 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/09 14:18:27 by tmervin          ###   ########.fr       */
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
	mlxst(d->mlx, d->win, 1920, 25, 0xFFFFFF, cx);
	mlx_string_put(d->mlx, d->win, 1750, 45, 0xFFFFFF, "Y AXIS (A / D) : ");
	mlxst(d->mlx, d->win, 1920, 45, 0xFFFFFF, cy);
	mlx_string_put(d->mlx, d->win, 1750, 65, 0xFFFFFF, "Z AXIS (Q / E) : ");
	mlxst(d->mlx, d->win, 1920, 65, 0xFFFFFF, cz);
	mlx_string_put(d->mlx, d->win, 1700, 85, 0xC8C8C8, "> CAM ROTATION (DEG)");
	mlx_string_put(d->mlx, d->win, 1750, 105, 0xFFFFFF, "X AXIS (I / K) : ");
	mlxst(d->mlx, d->win, 1920, 105, 0xFFFFFF, tx);
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
	mlxst(d->mlx, d->win, 1920, 145, 0xFFFFFF, tz);
	mlx_string_put(d->mlx, d->win, 1700, 165, 0xC8C8C8, "> STRETCH (SIZE + X)");
	mlx_string_put(d->mlx, d->win, 1750, 185, 0xFFFFFF, "X AXIS (4 / 1) : ");
	mlxst(d->mlx, d->win, 1920, 185, 0xFFFFFF, a);
	mlx_string_put(d->mlx, d->win, 1700, 285, 0xC8C8C8, "> COLORS");
	mlx_string_put(d->mlx, d->win, 1750, 305, get_color(d, d->z_min),
			"MIN HEIGHT");
	mlx_string_put(d->mlx, d->win, 1750, 325, get_color(d, d->z_max),
			"MAX HEIGHT");
	mlx_string_put(d->mlx, d->win, 1750, 125, 0xFFFFFF, "Y AXIS (J / L) : ");
	mlxst(d->mlx, d->win, 1920, 125, 0xFFFFFF, ty);
	mlx_string_put(d->mlx, d->win, 10, 5, 0xC8C8C8, "EXIT : ESC");
	mlx_string_put(d->mlx, d->win, 10, 25, 0xC8C8C8, "REINITIALIZE : ENTER");
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
	mlxst(d->mlx, d->win, 1920, 205, 0xFFFFFF, b);
	mlx_string_put(d->mlx, d->win, 1750, 225, 0xFFFFFF, "Z AXIS (6 / 3) : ");
	mlxst(d->mlx, d->win, 1920, 225, 0xFFFFFF, c);
	mlx_string_put(d->mlx, d->win, 1700, 245, 0xC8C8C8, "> FIELD OF VIEW (PX)");
	mlx_string_put(d->mlx, d->win, 1750, 265, 0xFFFFFF, "Z AXIS (- / +) : ");
	mlxst(d->mlx, d->win, 1920, 265, 0xFFFFFF, ez);
	free(b);
	free(c);
	free(ez);
}
