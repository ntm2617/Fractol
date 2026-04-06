/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 00:25:41 by ming              #+#    #+#             */
/*   Updated: 2026/04/07 03:41:10 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

void	main_init2(t_fractol *f)
{
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_j = -2.0;
	f->max_j = 2.0;
}

int	main_init(t_fractol *f)
{
	void	*mlx;
	char	*pix;

	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	f->mlx_p = mlx;
	if (fail_wind(f) == 1)
		return (1);
	if (fail_img(f) == 1)
		return (1);
	pix = mlx_get_data_addr(f->img_p, &f->bpp, &f->line_len, &f->endian);
	if (pix == NULL)
	{
		close_window(f);
		return (1);
	}
	f->pix = pix;
	f->max = 50;
	main_init2(f);
	mlx_hook(f->wind_p, 17, 0, close_window, f);
	mlx_key_hook(f->wind_p, key_press, f);
	mlx_mouse_hook(f->wind_p, mouse, f);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 11) == 0)
	{
		f.type = 1;
		if (main_init(&f) == 1)
			return (1);
		render_fractol(&f);
		mlx_loop(f.mlx_p);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 6) == 0)
	{
		f.type = 2;
		if (check_dot(av[2]) != 1 || check_dot(av[3]) != 1)
		{
			write(1, "Error: Invalid Julia parameters. Use decimals (e.g., -0.8)\n", 59);
			return (1);
		}
		f.julia_r = ft_atof(av[2]);
		f.julia_j = ft_atof(av[3]);
		if (main_init(&f) == 1)
			return (1);
		render_fractol(&f);
		mlx_loop(f.mlx_p);
	}
	else
	{
		write(1, "Please type: './fractol mandelbrot'\n", 36);
		write(1, "-----------------or----------------\n", 36);
		write(1, "'./fractol julia <real> <imaginary>'\n", 37);
		return (1);
	}
	return (0);
}
