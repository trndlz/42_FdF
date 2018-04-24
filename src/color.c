/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:46:22 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/24 09:26:30 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		*color_data(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->rmin = 255;
	color->gmin = 255;
	color->bmin = 255;
	color->rmax = 255;
	color->gmax = 0;
	color->bmax = 0;
	return (color);
}


unsigned long get_color(t_inf *d, int z)
{
	int red;
	int green;
	int blue;
	//char *res;
	unsigned long hexa;
	if (d->z_min == d->z_max)
		return (0);

	//res = NULL;
	red = (z * (d->color->rmax - d->color->rmin) / (d->z_max - d->z_min)) + d->color->rmin;
	green = (z * (d->color->gmax - d->color->gmin) / (d->z_max - d->z_min)) + d->color->gmin;
	blue = (z * (d->color->bmax - d->color->bmin) / (d->z_max - d->z_min)) + d->color->bmin;

	//res = ft_strjoin("0x", ft_itoa_base(red, "0123456789ABCDEF"));
	//res = ft_strjoin(res, ft_itoa_base(green, "0123456789ABCDEF"));
	//res = ft_strjoin(res, ft_itoa_base(blue, "0123456789ABCDEF"));

	hexa = ((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff);
	//printf("%lx", hexa);

	return (hexa);
}

