/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_adjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 17:58:08 by ming              #+#    #+#             */
/*   Updated: 2026/04/06 23:37:28 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double pix_pos, double size_display, double min_j, double max_j)
{
	double	complex_value;

	complex_value = (pix_pos / size_display) * (max_j - min_j) + min_j;
	return (complex_value);
}
