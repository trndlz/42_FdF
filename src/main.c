/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/20 16:58:23 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_inf(t_inf *data, char **av)
{

	data->cam = cam_data();
	data->fd = open(av[1], O_RDONLY);
	data->file = av[1];
	data->win = mlx_new_window(data->mlx, 2048, 1024, "TEST");
}


int		main(int ac, char **av)
{
	t_inf	*data;

	if (ac != 2)
		return (0);
	if (!(data = malloc(sizeof(t_inf))))
		return (0);
	data->mlx = mlx_init();
	init_inf(data, av);
	mlx_expose_hook(data->win, expose_hook, data);
	mlx_key_hook(data->win, deal_key, data);
	if (data->fd < 0 || get_map_info(data) != 1)
		return (0);
	if (fill_map(data) != 1)
		return (0);
	place_point(data);
	mlx_loop(data->mlx);
	return (0);
}
