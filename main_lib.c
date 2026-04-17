/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ming <ming@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 02:49:08 by ming              #+#    #+#             */
/*   Updated: 2026/04/14 16:11:49 by ming             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return ((unsigned char )s1[i] - (unsigned char )s2[i]);
	}
	return (0);
}

int	check_dot(const char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			count++;
		else if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		i++;
	}
	if (count > 1)
		return (-1);
	return (count);
}

double	ft_atof(const char *str)
{
	int		i;
	double	n;
	int		neg;
	double	j;

	neg = 1;
	n = 0.0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
		n = (n * 10) + (str[i++] - '0');
	if (str[i] == '.')
		i++;
	j = 10.0;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		n = n + ((str[i++] - '0') / j);
		j = j * 10.0;
	}
	return (neg * n);
}
