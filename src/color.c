/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 10:46:22 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/26 11:05:53 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color				*color_data(void)
{
	t_color *color;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	color->col[0] = 178;
	color->col[1] = 77;
	color->col[2] = 194;
	color->col[3] = 61;
	color->col[4] = 220;
	color->col[5] = 93;
	return (color);
}

void				color_check(t_color *color)
{
	int i;

	i = 0;
	while (i < 6)
	{
		if (color->col[i] < 0 || color->col[i] > 255)
			ft_color_range();
		i++;
	}
}

t_color				*color_data_user(char **av)
{
	t_color		*color;
	int			i;
	int			j;
	int			a;

	if (!(color = (t_color*)malloc(sizeof(t_color))))
		return (NULL);
	j = 1;
	a = -1;
	while (++j <= 3)
	{
		i = -1;
		while (av[j][++i])
		{
			if (!ft_isdigit(av[j][i]) && av[j][i] != '.')
				return (NULL);
			if (i == 0)
				color->col[++a] = ft_atoi(&av[j][i]);
			if (ft_isdigit(av[j][i]) && av[j][i - 1] == '.')
				color->col[++a] = ft_atoi(&av[j][i]);
		}
	}
	if (a != 5)
		return (NULL);
	return (color);
}

unsigned long		get_color(t_inf *d, int z)
{
	int				red;
	int				green;
	int				blue;

	red = d->color->col[0];
	green = d->color->col[1];
	blue = d->color->col[2];
	if (d->z_min == d->z_max)
		return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
	red = (z * (d->color->col[3] - d->color->col[0])
			+ d->color->col[0] * d->z_max - d->color->col[3] * d->z_min)
		/ (d->z_max - d->z_min);
	green = (z * (d->color->col[4] - d->color->col[1])
			+ d->color->col[1] * d->z_max - d->color->col[4] * d->z_min)
			/ (d->z_max - d->z_min);
	blue = (z * (d->color->col[5] - d->color->col[2])
			+ d->color->col[2] * d->z_max - d->color->col[5] * d->z_min)
			/ (d->z_max - d->z_min);
	return (((red & 0xff) << 16) + ((green & 0xff) << 8) + (blue & 0xff));
}
