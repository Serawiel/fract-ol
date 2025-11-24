/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 19:05:41 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:27:48 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	ft_putstr_fd("Usage: ./fractol [mandelbrot]", 1);
	ft_putstr_fd(" or ./fractol [julia] [real] [imag]\n", 1);
	ft_putstr_fd("Examples:\n", 1);
	ft_putstr_fd("  ./fractol mandelbrot\n", 1);
	ft_putstr_fd("  ./fractol julia -0.7 0.27015\n", 1);
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	return (str[i] == '\0');
}

int	parse_args(int ac, char **av, t_fractol *f)
{
	if (!ft_strncmp(av[1], "mandelbrot", 10) || !ft_strncmp(av[1], "MANDELBROT",
			10))
	{
		if (ac != 2)
			return (1);
		f->type = MANDELBROT;
		return (0);
	}
	if (!ft_strncmp(av[1], "julia", 5) || !ft_strncmp(av[1], "JULIA", 5))
	{
		if (ac != 4 || !is_valid_number(av[2]) || !is_valid_number(av[3]))
			return (1);
		f->type = JULIA;
		f->julia_r = ft_atof(av[2]);
		f->julia_i = ft_atof(av[3]);
		return (0);
	}
	if (!ft_strncmp(av[1], "tricorn", 7) || !ft_strncmp(av[1], "TRICORN", 7))
	{
		if (ac != 2)
			return (1);
		f->type = TRICORN;
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2 || parse_args(ac, av, &fractol))
		return (print_usage(), 1);
	init_fractol(&fractol);
	apply_hooks(&fractol);
	render_fractol(&fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img.img_ptr, 0,
		0);
	mlx_loop(fractol.mlx);
	return (0);
}
