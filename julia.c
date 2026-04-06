/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 02:35:25 by ming              #+#    #+#             */
/*   Updated: 2026/04/07 02:38:46 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(int x, int y, t_fractol *f)
{
	t_complex	z;
	int			i;
	t_scaled	c;
	double		old_r;

	i = 0;
	z.r = scale(x, 800, f->min_r, f->max_r);
	z.j = scale(y, 800, f->max_j, f->min_r);
	c.r = f->julia_r;
	c.j = f->julia_j;
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