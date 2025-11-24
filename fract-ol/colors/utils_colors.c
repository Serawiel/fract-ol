/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:55:58 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:27:44 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

static int	get_tricorn_fire_dark(double t)
{
	int		r;
	int		g;
	int		b;
	double	q;

	if (t < 0.2)
	{
		r = 40 + t * 150 / 0.2;
		g = 0;
		b = 0;
	}
	else
	{
		q = (t - 0.2) / 0.3;
		r = 190 + 65 * q;
		g = 0 + 50 * q;
		b = 0;
	}
	return (create_trgb(0, r, g, b));
}

static int	get_tricorn_fire_bright(double t)
{
	int		r;
	int		g;
	int		b;
	double	q;

	if (t < 0.7)
	{
		q = (t - 0.5) / 0.2;
		r = 255;
		g = 50 + 100 * q;
		b = 0;
	}
	else
	{
		q = (t - 0.7) / 0.3;
		r = 255;
		g = 150 + 55 * q;
		b = 0 + 80 * q;
	}
	return (create_trgb(0, r, g, b));
}

static int	get_tricorn_palette_values(double t)
{
	if (t < 0.5)
		return (get_tricorn_fire_dark(t));
	else
		return (get_tricorn_fire_bright(t));
}

int	get_color_palette(double t, int palette)
{
	double	angle;
	int		r;
	int		g;
	int		b;

	if (t > 1.0)
		t = 1.0;
	if (t < 0.0)
		t = 0.0;
	if (palette == 1)
	{
		angle = t * 5.0 * M_PI;
		r = 128 + 127 * cos(angle);
		g = 128 + 127 * cos(angle - 2.0);
		b = 128 + 127 * cos(angle - 4.0);
	}
	else if (palette == 2)
		return (get_tricorn_palette_values(t));
	else
	{
		r = t * 255;
		g = t * 255;
		b = t * 255;
	}
	return (create_trgb(0, r, g, b));
}

int	get_iteration_color(int iteration, int max_iteration, int color_scheme)
{
	double	t;

	if (iteration >= max_iteration)
		return (0x000000);
	if (color_scheme == 2)
	{
		t = (double)iteration / max_iteration;
		t = pow(t, 0.95);
	}
	else
		t = (double)iteration / max_iteration;
	return (get_color_palette(t, color_scheme));
}
