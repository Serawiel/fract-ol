/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:31:44 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:31:56 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(double cr, double ci, t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (iter < fractol->max_iter && zr * zr + zi * zi <= 4)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}

int	calculate_julia(double zr, double zi, t_fractol *fractol)
{
	double	tmp;
	int		iter;

	iter = 0;
	while (iter < fractol->max_iter && zr * zr + zi * zi <= 4)
	{
		tmp = zr * zr - zi * zi + fractol->julia_r;
		zi = 2 * zr * zi + fractol->julia_i;
		zr = tmp;
		iter++;
	}
	return (iter);
}
