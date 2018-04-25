/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:44:47 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/25 16:17:22 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam	*cam_data(void)
{
	t_cam *cam;

	if (!(cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	cam->cx = -50;
	cam->cy = 250;
	cam->cz = 350;
	cam->ez = 1000;
	cam->tx = 60;
	cam->ty = -25;
	cam->tz = -170;
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
	mlx_string_put(d->mlx, d->win, 1700, 5, 0xFFFFFF,
			ft_strjoin("Cx (+T -Y) : ", ft_itoa(d->cam->cx)));
	mlx_string_put(d->mlx, d->win, 1700, 25, 0xFFFFFF,
			ft_strjoin("Cy (+G -H) : ", ft_itoa(d->cam->cy)));
	mlx_string_put(d->mlx, d->win, 1700, 45, 0xFFFFFF,
			ft_strjoin("Cz (+B -N) : ", ft_itoa(d->cam->cz)));
	mlx_string_put(d->mlx, d->win, 1700, 70, 0xFFFFFF,
			ft_strjoin("*x (+E -R) : ", ft_itoa(d->cam->tx)));
	mlx_string_put(d->mlx, d->win, 1700, 90, 0xFFFFFF,
			ft_strjoin("*y (+D -F) : ", ft_itoa(d->cam->ty)));
	mlx_string_put(d->mlx, d->win, 1700, 110, 0xFFFFFF,
			ft_strjoin("*z (+C -V) : ", ft_itoa(d->cam->tz)));
}

void	init_inf(t_inf *data, char **av)
{
	data->cam = cam_data();
	data->color = color_data();
	data->fd = open(av[1], O_RDONLY);
	data->file = av[1];
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_LENGTH, "FILS DE FER");
}
