/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/26 14:05:50 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_inf	*data;

	if (!(ac == 2 || ac == 4))
		ft_usage();
	if (!(data = malloc(sizeof(t_inf))))
		return (0);
	data->mlx = mlx_init();
	init_inf(data, ac, av);
	mlx_key_hook(data->win, deal_key, data);
	if (data->fd < 0 || get_map_info(data) != 1)
		return (0);
	if (fill_map(data) != 1)
		return (0);
	z_limits(data);
	data->cam = cam_data(data);
	place_line(data);
	mlx_loop(data->mlx);
	free_map(data);
	return (0);
}
