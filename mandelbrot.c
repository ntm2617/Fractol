/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 18:30:24 by ming              #+#    #+#             */
/*   Updated: 2026/04/07 02:45:24 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*mlx_get_data_addr returns memory address of the very first byte of canvas
store in f->pix*/
void	mlx_pix_put(t_fractol *f, int x, int y, int color)
{
	int	offset;

	offset = (y * f->line_len) + (x * (f->bpp / 8));
	*(unsigned int *)(f->pix + offset) = color;
}

int	get_color(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	range_color(int i, t_fractol *f, int x, int y)
{
	int	r;
	int	g;
	int	b;

	r = (i * 2) % 256;
	g = (i * 8) % 256;
	b = (i * 15) % 256;
	mlx_pix_put(f, x, y, get_color(r, g, b));
}

/*Z(n + 1) = Z(n)^ 2 + C*/
void	mandelbrot(int x, int y, t_fractol *f)
{
	t_complex	z;
	int			i;
	t_scaled	c;
	double		old_r;

	i = 0;
	z.r = 0.0;
	z.j = 0.0;
	c.r = scale(x, 800, f->min_r, f->max_r);
	c.j = scale(y, 800, f->max_j, f->min_r);
	while ((i < f->max) && ((z.r * z.r) + (z.j * z.j) < 4.0))
	{
		old_r = z.r;
		z.r = (old_r * old_r) - (z.j * z.j) + c.r;
		z.j = (2 * old_r * z.j) + c.j;
		i++;
	}
	if (i == f->max)
		mlx_pix_put(f, x, y, 0x000000);
	else
		range_color(i, f, x, y);
}

int	render_fractol(t_fractol *f)
{
	int	x;
	int	y;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			if (f->type == 1)
				mandelbrot(x, y, f);
			else if (f->type == 2)
				julia(x, y, f);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_p, f->wind_p, f->img_p, 0, 0);
	return (0);
}
