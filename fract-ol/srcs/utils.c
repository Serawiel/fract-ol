/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:31:09 by cprot             #+#    #+#             */
/*   Updated: 2025/05/17 15:05:25 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = fractol->img.addr + (y * fractol->img.line_len + x
				* (fractol->img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	exit_error(char *s)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

int	close_window(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_destroy_image(fractol->mlx, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(0);
	return (0);
}
