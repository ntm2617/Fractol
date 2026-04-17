/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:38:16 by ming              #+#    #+#             */
/*   Updated: 2026/04/15 15:07:36 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractol *f)
{
	mlx_destroy_image(f->mlx_p, f->img_p);
	mlx_destroy_window(f->mlx_p, f->wind_p);
	mlx_destroy_display(f->mlx_p);
	free(f->mlx_p);
	exit (0);
}

void	for_move(int press, t_fractol *f)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_j - f->min_j;
	if (press == 65361)
	{
		f->min_r = f->min_r - (width * 0.05);
		f->max_r = f->max_r - (width * 0.05);
	}
	else if (press == 65363)
	{
		f->min_r = f->min_r + (width * 0.05);
		f->max_r = f->max_r + (width * 0.05);
	}
	else if (press == 65364)
	{
		f->min_j = f->min_j - (height * 0.05);
		f->max_j = f->max_j - (height * 0.05);
	}
	else if (press == 65362)
	{
		f->min_j = f->min_j + (height * 0.05);
		f->max_j = f->max_j + (height * 0.05);
	}
}

int	key_press(int press, t_fractol *f)
{
	if (press == 65307)
		close_window(f);
	else
		for_move(press, f);
	render_fractol(f);
	return (0);
}

int	fail_wind(t_fractol *f)
{
	void	*wind;

	wind = mlx_new_window(f->mlx_p, 800, 800, "Fract-ol");
	if (wind == NULL)
	{
		mlx_destroy_display(f->mlx_p);
		free(f->mlx_p);
		return (1);
	}
	f->wind_p = wind;
	return (0);
}

int	fail_img(t_fractol *f)
{
	void	*img;

	img = mlx_new_image(f->mlx_p, 800, 800);
	if (img == NULL)
	{
		mlx_destroy_window(f->mlx_p, f->wind_p);
		mlx_destroy_display(f->mlx_p);
		free(f->mlx_p);
		return (1);
	}
	f->img_p = img;
	return (0);
}