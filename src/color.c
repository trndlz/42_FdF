/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:46:22 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/25 14:44:47 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color				*color_data(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->rmin = 178;
	color->gmin = 77;
	color->bmin = 194;
	color->rmax = 61;
	color->gmax = 220;
	color->bmax = 93;
	return (color);
}

unsigned long		get_color(t_inf *d, int z)
{
	int				red;
	int				green;
	int				blue;

	red = d->color->rmin;
	blue = d->color->bmin;
	green = d->color->gmin;
	if (d->z_min == d->z_max)
		return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
	red = (z * (d->color->rmax - d->color->rmin)
			+ d->color->rmin * d->z_max - d->color->rmax * d->z_min)
		/ (d->z_max - d->z_min);
	green = (z * (d->color->gmax - d->color->gmin)
			+ d->color->gmin * d->z_max - d->color->gmax * d->z_min)
			/ (d->z_max - d->z_min);
	blue = (z * (d->color->bmax - d->color->bmin)
			+ d->color->bmin * d->z_max - d->color->bmax * d->z_min)
			/ (d->z_max - d->z_min);
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}
