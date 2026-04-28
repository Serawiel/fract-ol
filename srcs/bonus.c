/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:48:46 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:29:04 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_tricorn(double cr, double ci, t_fractol *fractol)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = 0.0;
	zi = 0.0;
	iter = 0;
	while (iter < fractol->max_iter && (zr * zr + zi * zi) <= 4.0)
	{
		tmp = zr * zr - zi * zi + cr;
		zi = -2 * zr * zi + ci;
		zr = tmp;
		iter++;
	}
	return (iter);
}
