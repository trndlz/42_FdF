/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 11:42:49 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/20 13:51:18 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_inf	data;


	if (ac != 2)
		return (-1);
	data.file = av[1];
	data.fd = open(av[1], O_RDONLY);
	if (data.fd < 0)
		return (-1);
	if (get_map_info(&data) != 1)
		return (-1);
	if (fill_map(&data) != 1)
		return (-1);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 2048, 1024, av[1]);
	data.cam = cam_data();
	mlx_expose_hook(data.win, expose_hook, &data);
	mlx_key_hook(data.win, deal_key, &data);
	
	
	
	test(&data);
	//change(&data);
	//test(&data);

	mlx_loop(data.mlx);
	close(data.fd);

	return (0);
}
