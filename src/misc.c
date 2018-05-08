/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <tmervin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:45:40 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/07 14:27:21 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_two(char **s, char *l)
{
	free(s);
	free(l);
}

int		inside(int x, int y)
{
	if (x < 0 || y < 0 || x > WIDTH || y > HEIGHT)
		return (0);
	return (1);
}

void	free_structures(t_inf *d)
{
	if (d->cam)
		free(d->cam);
	if (d->color)
		free(d->color);
	if (d)
		free(d);
}
