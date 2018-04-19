/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:40:30 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/19 15:52:52 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../includes/fdf.h"

typedef struct			s_cam
{
	int					cx;
	int					cy;
	int					cz;
	int					tx;
	int					ty;
	int					tz;
	int					ex;
	int					ey;
	int					ez;
	double				cosx;
	double				cosy;
	double				cosz;
	double				sinx;
	double				siny;
	double				sinz;
}						t_cam;

typedef struct			s_inf
{
	void				*mlx;
	void				*win;
	int					fd;
	char				*file;
	int					**map;
	int					y;
	int					x;
	struct s_cam		*cam;
}						t_inf;

int						str_check(char *s);
void					printdata(t_inf *data);
int						get_map_info(t_inf *data);
int						fill_map(t_inf *data);
int						read_file(int ac, char **av);
t_cam					*cam_data(void);
void					test(t_inf *data);
int						deal_key(int key, t_inf *data);
int						expose_hook(t_inf *data);

#endif
