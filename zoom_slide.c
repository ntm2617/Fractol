/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_slide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 23:20:36 by ming              #+#    #+#             */
/*   Updated: 2026/04/07 02:28:21 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_fractol *f, double size_dis, t_mouse *mouse, double zoom_factor)
{
	double	percent;
	double	new_width;
	double	pos_r;
	double	pos_j;

	percent = (mouse->x / size_dis);
	new_width = (f->max_r - f->min_r) * zoom_factor;
	pos_r = scale(mouse->x, size_dis, f->min_r, f->max_r);
	pos_j = scale(mouse->y, size_dis, f->max_j, f->min_j);
	f->min_r = pos_r - (percent * new_width);
	f->max_r = f->min_r + new_width;
	percent = (mouse->y / size_dis);
	f->max_j = pos_j + (percent * new_width);
	f->min_j = f->max_j - new_width;
}

int	mouse(int num_mouse, int x, int y, t_fractol *f)
{
	t_mouse	mouse;

	mouse.x = (double)x;
	mouse.y = (double)y;
	if (num_mouse == 4)
	{
		zoom(f, 800.0, &mouse, 0.9);
		render_fractol(f);
	}
	else if (num_mouse == 5)
	{
		zoom(f, 800.0, &mouse, 1.1);
		render_fractol(f);
	}
	return (0);
}