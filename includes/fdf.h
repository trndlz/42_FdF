/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:40:30 by tmervin           #+#    #+#             */
/*   Updated: 2018/04/24 19:24:19 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"
# define WIN_WIDTH 2048
# define WIN_LENGTH 1024

typedef struct			s_points
{
	int					z0;
	int					z1;
	int					z2;
	int					bx0;
	int					by0;
	int					bx1;
	int					by1;
	int					bx2;
	int					by2;
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}						t_points;

typedef struct			s_color
{
	int					rmin;
	int					rmax;
	int					gmin;
	int					gmax;
	int					bmin;
	int					bmax;
}						t_color;

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
	int					a;
	int					b;
	int					c;
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
	int					z_min;
	int					z_max;
	struct s_cam		*cam;
	struct s_color		*color;
}						t_inf;

int						str_check(char *s);
void					printdata(t_inf *data);
int						get_map_info(t_inf *data);
int						fill_map(t_inf *data);
int						read_file(int ac, char **av);
t_cam					*cam_data(void);
t_color					*color_data(void);
unsigned long			get_color(t_inf *data, int z);
void					place_point(t_inf *data);
int						deal_key(int key, t_inf *data);
int						expose_hook(t_inf *data);
void					calc_cosinus(t_inf *data);
void					display_infos(t_inf *d);
double					calc_dx(t_inf *d, int x, int y, int z);
double					calc_dy(t_inf *d, int x, int y, int z);
double					calc_dz(t_inf *d, int x, int y, int z);
double					calc_bx(t_inf *d, int x, int y, int z);
double					calc_by(t_inf *d, int x, int y, int z);
void					place_line(t_inf *d);
void					place_line2(t_inf *d);
int						ft_abs(int i);
void					plot_line(t_inf *d, int x0, int y0, int x1, int y1, int z);
void					plot_line2(t_inf *d, t_points *p);
void					z_limits(t_inf *data);

#endif
