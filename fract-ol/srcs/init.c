/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:05:50 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:31:21 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, "Fractol");
	fractol->img.img_ptr = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->img.addr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	fractol->color_scheme = 1;
	fractol->min_r = -2.0;
	fractol->max_iter = DEFAULT_MAX_ITER;
	if (fractol->type == MANDELBROT)
	{
		fractol->max_r = 1.0;
		fractol->min_i = -1.5;
		fractol->max_i = 1.5;
	}
	else
	{
		fractol->max_r = 2.0;
		fractol->min_i = -2.0;
		fractol->max_i = 2.0;
	}
	if (fractol->type == TRICORN)
	{
		fractol->max_iter = 500;
		fractol->color_scheme = 2;
	}
}
