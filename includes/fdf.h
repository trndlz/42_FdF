/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmervin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:40:30 by tmervin           #+#    #+#             */
/*   Updated: 2018/05/01 14:09:11 by tmervin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define WIN_WIDTH 2048
# define WIN_HEIGHT 1024

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
	unsigned long		color;
}						t_points;

typedef struct			s_color
{
	int					col[6];
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
	void				*image;
	int					*imgstr;
	int					bpp;
	int					s_l;
	int					endian;
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

/*
** STRUCTURES INITIALISATION
*/

t_cam					*cam_data(t_inf *data);
void					calc_cosinus(t_inf *data);
int						init_inf(t_inf *data, int ac, char **av);

/*
** READ / STRING CONVERSION
*/

int						str_check(char *s);
int						get_map_info(t_inf *data);
int						fill_map(t_inf *data);
int						read_file(int ac, char **av);
void					place_point(t_inf *data);
int						expose_hook(t_inf *data);
void					free_map(t_inf *data);

/*
** COLORS
*/

t_color					*color_data(void);
t_color					*color_data_user(char **av);
void					color_check(t_color *color);
unsigned long			get_color(t_inf *data, int z);

/*
** CALCULATION
*/

double					calc_dx(t_inf *d, int x, int y, int z);
double					calc_dy(t_inf *d, int x, int y, int z);
double					calc_dz(t_inf *d, int x, int y, int z);
double					calc_bx(t_inf *d, int x, int y, int z);
double					calc_by(t_inf *d, int x, int y, int z);
void					place_line(t_inf *d);
int						ft_abs(int i);
void					plot_line(t_inf *d, t_points *p);
void					z_limits(t_inf *data);

void					fill_pixel(int x, int y, int color, t_inf *data);
void					create_image(t_inf *d);
void					fill_image(t_inf *d);
void					create_image(t_inf *d);

/*
** KEYBOARD
*/

int						deal_key(int key, t_inf *data);
void					squeeze_zoom(int key, t_inf *data);
void					translation(int key, t_inf *data);
void					rotation(int key, t_inf *data);

/*
** INFO DISPLAY
*/

void					display_infos3(t_inf *d);
void					display_infos2(t_inf *d);
void					display_infos(t_inf *d);

/*
** USAGE
*/

void					ft_usage(void);
void					ft_color_range(void);
void					ft_invalid_file(void);

#endif
