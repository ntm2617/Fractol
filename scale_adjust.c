/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_adjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:58:08 by ming              #+#    #+#             */
/*   Updated: 2026/04/15 16:14:09 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double pix_pos, double size_display, double min, double max)
{
	double	complex_value;

	complex_value = (pix_pos / size_display) * (max - min) + min;
	return (complex_value);
}
