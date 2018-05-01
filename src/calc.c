/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:08:54 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 14:44:05 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		calc_dx(t_inf *d, int x, int y, int z)
{
	double dx;

	dx = d->cam->cosy * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx))
		- d->cam->siny * (d->cam->c * z - d->cam->cz);
	return (dx);
}

double		calc_dy(t_inf *d, int x, int y, int z)
{
	double dy;

	dy = d->cam->sinx * (d->cam->cosy * (d->cam->c * z - d->cam->cz)
		+ d->cam->siny * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx)))
		+ d->cam->cosx * (d->cam->cosz * (d->cam->b * y - d->cam->cy)
		- d->cam->sinz * (d->cam->a * x - d->cam->cx));
	return (dy);
}

double		calc_dz(t_inf *d, int x, int y, int z)
{
	double dz;

	dz = d->cam->cosx * (d->cam->cosy * (d->cam->c * z - d->cam->cz)
		+ d->cam->siny * (d->cam->sinz * (d->cam->b * y - d->cam->cy)
		+ d->cam->cosz * (d->cam->a * x - d->cam->cx)))
		- d->cam->sinx * (d->cam->cosz * (d->cam->b * y - d->cam->cy)
		- d->cam->sinz * (d->cam->a * x - d->cam->cx));
	return (dz);
}

double		calc_bx(t_inf *d, int x, int y, int z)
{
	double dx;
	double dz;
	double bx;

	dx = calc_dx(d, x, y, z);
	dz = calc_dz(d, x, y, z);
	bx = (d->cam->ez / dz) * dx;
	return (bx);
}

double		calc_by(t_inf *d, int x, int y, int z)
{
	double dy;
	double dz;
	double by;

	dy = calc_dy(d, x, y, z);
	dz = calc_dz(d, x, y, z);
	by = (d->cam->ez / dz) * dy;
	return (by);
}
