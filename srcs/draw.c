/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:30:02 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 13:26:41 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	calculate_fractol(t_complex c, t_fractol *fractol)
{
	if (fractol->type == MANDELBROT)
		return (calculate_mandelbrot(c.re, c.im, fractol));
	else if (fractol->type == JULIA)
		return (calculate_julia(c.re, c.im, fractol));
	else if (fractol->type == TRICORN)
		return (calculate_tricorn(c.re, c.im, fractol));
	else
		return (0);
}

static t_complex	pixel_to_complex(int x, int y, t_fractol *fractol)
{
	t_complex	c;

	c.re = fractol->min_r + (double)x / WIDTH * (fractol->max_r
			- fractol->min_r);
	c.im = fractol->min_i + (double)y / HEIGHT * (fractol->max_i
			- fractol->min_i);
	return (c);
}

void	render_fractol(t_fractol *fractol)
{
	int			x;
	int			y;
	t_complex	c;
	int			iter;
	int			color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c = pixel_to_complex(x, y, fractol);
			iter = calculate_fractol(c, fractol);
			color = get_iteration_color(iter, fractol->max_iter,
					fractol->color_scheme);
			my_mlx_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
}
