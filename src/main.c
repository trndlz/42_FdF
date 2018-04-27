/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/27 16:24:44 by tmervin          ###   ########.fr       */
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
	if (data->fd < 0 || get_map_info(data) != 1)
		ft_invalid_file();
	if (fill_map(data) != 1)
		return (0);
	z_limits(data);
	data->cam = cam_data(data);
	mlx_hook(data->win, 2, 3, deal_key, data);
	create_image(data);
	free(data->cam);
	free(data->color);
	free_map(data);
	free(data);
	return (0);
}
