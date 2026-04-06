/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:35:20 by ming              #+#    #+#             */
/*   Updated: 2026/04/07 03:41:10 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <math.h>

typedef struct s_fractol
{
	void	*mlx_p;
	void	*wind_p;
	void	*img_p;
	char	*pix;
	int		bpp;
	int		line_len;
	int		endian;
	double	zoom;
	double	x;
	double	y;
	int		max;
	double	min_r;
	double	max_r;
	double	min_j;
	double	max_j;
	double	julia_r;
	double	julia_j;
	int		type;
}	t_fractol;

typedef struct s_complex
{
	double	r;
	double	j;
}	t_complex;

typedef struct s_scaled
{
	double	r;
	double	j;
}	t_scaled;

typedef struct s_mouse
{
	double	x;
	double	y;
}	t_mouse;

/*close the window*/
int		close_window(t_fractol *f);
int		key_press(int press, t_fractol *f);

/*use in main*/
int		fail_wind(t_fractol *f);
int		fail_img(t_fractol *f);
int		main_init(t_fractol *f);

/*scale the coordinate*/
double	scale(double pix_pos, double size_display, double min_j, double max_j);

/*mandelbrot*/
void	mandelbrot(int x, int y, t_fractol *f);
int		render_fractol(t_fractol *f);
void	mlx_pix_put(t_fractol *f, int x, int y, int color);
int		get_color(int r, int g, int b);
void	range_color(int i, t_fractol *f, int x, int y);

/*julia*/
void	julia(int x, int y, t_fractol *f);

/*zooming*/
void	zoom(t_fractol *f, double size_dis, t_mouse *mouse, double zoom_factor);
int		mouse(int num_mouse, int x, int y, t_fractol *f);

/*lib for main*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
double	ft_atof(const char *str);
int		check_dot(const char *str);

#endif