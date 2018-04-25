/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/25 18:15:27 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_inf	*data;

	if (ac != 2)
		return (0);
	if (!(data = malloc(sizeof(t_inf))))
		return (0);
	data->mlx = mlx_init();
	init_inf(data, av);
	mlx_key_hook(data->win, deal_key, data);
	if (data->fd < 0 || get_map_info(data) != 1)
		return (0);
	if (fill_map(data) != 1)
		return (0);
	z_limits(data);
	data->cam = cam_data(data);
	place_line(data);
	mlx_loop(data->mlx);
	return (0);
}
