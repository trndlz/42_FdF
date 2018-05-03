/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:24:59 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/03 16:06:35 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotation(int key, t_inf *data)
{
	if (key == 40)
		data->cam->tx += 2;
	if (key == 38)
		data->cam->ty += 2;
	if (key == 32)
		data->cam->tz += 2;
	if (key == 34)
		data->cam->tx -= 2;
	if (key == 37)
		data->cam->ty -= 2;
	if (key == 31)
		data->cam->tz -= 2;
}

void	translation(int key, t_inf *data)
{
	if (key == 0)
		data->cam->cx += 5;
	if (key == 13)
		data->cam->cy += 5;
	if (key == 14)
		data->cam->cz += 5;
	if (key == 2)
		data->cam->cx -= 5;
	if (key == 1)
		data->cam->cy -= 5;
	if (key == 12)
		data->cam->cz -= 5;
}

void	squeeze_zoom(int key, t_inf *data)
{
	if (key == 86 && data->cam->a < 10)
		data->cam->a += 1;
	if (key == 83 && data->cam->a > -10)
		data->cam->a -= 1;
	if (key == 87 && data->cam->b < 10)
		data->cam->b += 1;
	if (key == 84 && data->cam->b > -10)
		data->cam->b -= 1;
	if (key == 88 && data->cam->c < 10)
		data->cam->c += 1;
	if (key == 85 && data->cam->c > -10)
		data->cam->c -= 1;
	if (key == 69)
		data->cam->ez += 50;
	if (key == 78)
		data->cam->ez -= 50;
}

int		deal_key(int key, t_inf *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(1);
	}
	if (key == 36)
		data->cam = cam_data(data);
	rotation(key, data);
	translation(key, data);
	squeeze_zoom(key, data);
	create_image(data);
	return (0);
}
