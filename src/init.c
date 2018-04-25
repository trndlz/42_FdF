/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/25 18:53:28 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	*cam_data(t_inf *data)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	cam->cx = 6 * data->x;
	cam->cy = 4 * data->y;
	cam->cz = 5 * data->x;
	cam->ez = 1000;
	cam->tx = 90;
	cam->ty = -30;
	cam->tz = 90;
	cam->a = 1;
	cam->b = 1;
	cam->c = 1;
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

void	display_infos(t_inf *d)
{
	mlx_string_put(d->mlx, d->win, 1700, 5, 0xFFFFFF, "CAMERA POSITION (PX)");
	mlx_string_put(d->mlx, d->win, 1750, 25, 0xFFFFFF,
			ft_strjoin("X AXIS (S / W) : ", ft_itoa(d->cam->cx)));
	mlx_string_put(d->mlx, d->win, 1750, 45, 0xFFFFFF,
			ft_strjoin("Y AXIS (A / D) : ", ft_itoa(d->cam->cy)));
	mlx_string_put(d->mlx, d->win, 1750, 65, 0xFFFFFF,
			ft_strjoin("Z AXIS (Q / E) : ", ft_itoa(d->cam->cz)));
	mlx_string_put(d->mlx, d->win, 1700, 85, 0xFFFFFF, "CAMERA ROTATION (DEG)");
	mlx_string_put(d->mlx, d->win, 1750, 105, 0xFFFFFF,
			ft_strjoin("X AXIS (I / K) : ", ft_itoa(d->cam->tx)));
	mlx_string_put(d->mlx, d->win, 1750, 125, 0xFFFFFF,
			ft_strjoin("Y AXIS (J / L) : ", ft_itoa(d->cam->ty)));
	mlx_string_put(d->mlx, d->win, 1750, 145, 0xFFFFFF,
			ft_strjoin("Z AXIS (U / O) : ", ft_itoa(d->cam->tz)));
	mlx_string_put(d->mlx, d->win, 1700, 165, 0xFFFFFF, "MAP STRETCH (SIZE + X)");
	mlx_string_put(d->mlx, d->win, 1750, 185, 0xFFFFFF,
			ft_strjoin("X AXIS (4 / 1) : ", ft_itoa(d->cam->a)));
	mlx_string_put(d->mlx, d->win, 1750, 205, 0xFFFFFF,
			ft_strjoin("Y AXIS (5 / 2) : ", ft_itoa(d->cam->b)));
	mlx_string_put(d->mlx, d->win, 1750, 225, 0xFFFFFF,
			ft_strjoin("Z AXIS (6 / 3) : ", ft_itoa(d->cam->c)));
	mlx_string_put(d->mlx, d->win, 1700, 245, 0xFFFFFF, "FIELD OF VIEW (PX)");
	mlx_string_put(d->mlx, d->win, 1750, 265, 0xFFFFFF,
			ft_strjoin("Z AXIS (- / +) : ", ft_itoa(d->cam->ez)));


}

void	init_inf(t_inf *data, char **av)
{
	data->color = color_data();
	data->fd = open(av[1], O_RDONLY);
	data->file = av[1];
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_LENGTH, "FILS DE FER");
}
