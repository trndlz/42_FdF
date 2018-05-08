/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:01:33 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 14:26:31 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_usage(void)
{
	ft_putstr("Usage: ./fdf <mapname.fdf>\nColor option: ./fdf <mapname.fdf> ");
	ft_putstr("[Rmin.Gmin.Bmin Rmax.Gmax.Bmax]\n");
	exit(1);
}

void	ft_malloc_error_inf(void)
{
	ft_putstr("Error while structures malloc\n");
	exit(1);
}

void	ft_malloc_error(t_inf *d)
{
	ft_putstr("Error while parsing and/or structures malloc\n");
	free_structures(d);
	if (d->mlx && d->win)
		mlx_destroy_window(d->mlx, d->win);
	exit(1);
}

void	ft_color_range(void)
{
	ft_putstr("Error: Individual colors must be	 between 0 and 255\n");
	exit(1);
}

void	ft_invalid_file(void)
{
	ft_putstr("Error: Invalid file\n");
	exit(1);
}
