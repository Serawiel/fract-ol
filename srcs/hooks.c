/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:26:23 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:38:15 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_to(t_fractol *fractol, int direction)
{
	double	move_factor;
	int		sign;

	move_factor = 0.1 * (fractol->max_r - fractol->min_r);
	sign = -1;
	if (direction == MOVE_RIGHT || direction == MOVE_DOWN)
		sign = 1;
	if (direction == MOVE_LEFT || direction == MOVE_RIGHT)
	{
		fractol->min_r += sign * move_factor;
		fractol->max_r += sign * move_factor;
	}
	else
	{
		fractol->min_i += sign * move_factor;
		fractol->max_i += sign * move_factor;
	}
	render_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0,
		0);
}

int	key_press(int keycode, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (keycode == 65307)
		close_window(fractol);
	else if (keycode == 99)
	{
		fractol->color_scheme = (fractol->color_scheme + 1) % 3;
		render_fractol(fractol);
		mlx_put_image_to_window(fractol->mlx, fractol->win,
			fractol->img.img_ptr, 0, 0);
	}
	else if (keycode == 65361)
		move_to(fractol, MOVE_LEFT);
	else if (keycode == 65363)
		move_to(fractol, MOVE_RIGHT);
	else if (keycode == 65362)
		move_to(fractol, MOVE_UP);
	else if (keycode == 65364)
		move_to(fractol, MOVE_DOWN);
	return (0);
}

int	expose_handler(void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0,
		0);
	return (0);
}

int	handle_zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button != 4 && button != 5)
		return (0);
	mouse_re = fractol->min_r + (double)x / WIDTH * (fractol->max_r
			- fractol->min_r);
	mouse_im = fractol->min_i + (double)y / HEIGHT * (fractol->max_i
			- fractol->min_i);
	if (button == 4)
		zoom_factor = 0.9;
	else
		zoom_factor = 1.1;
	fractol->min_r = mouse_re - (mouse_re - fractol->min_r) * zoom_factor;
	fractol->max_r = mouse_re + (fractol->max_r - mouse_re) * zoom_factor;
	fractol->min_i = mouse_im - (mouse_im - fractol->min_i) * zoom_factor;
	fractol->max_i = mouse_im + (fractol->max_i - mouse_im) * zoom_factor;
	fractol->max_iter = DEFAULT_MAX_ITER + log((4.0) / (fractol->max_r
				- fractol->min_r)) * 50;
	render_fractol(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img_ptr, 0,
		0);
	return (0);
}

void	apply_hooks(t_fractol *fractol)
{
	mlx_hook(fractol->win, 17, 0, close_window, fractol);
	mlx_hook(fractol->win, 2, 1L << 0, key_press, fractol);
	mlx_hook(fractol->win, 12, 1L << 15, expose_handler, fractol);
	mlx_hook(fractol->win, 4, 1L << 2, handle_zoom, fractol);
}
