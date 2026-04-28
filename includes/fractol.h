/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:56:29 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 13:27:34 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "colors.h"
# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MANDELBROT 1
# define JULIA 2
# define TRICORN 3
# define BUFFALO 4
# define CELTIC 5
# define DEFAULT_MAX_ITER 100
# define MOVE_LEFT 1
# define MOVE_RIGHT 2
# define MOVE_UP 3
# define MOVE_DOWN 4

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	struct		s_img
	{
		void	*img_ptr;
		char	*addr;
		int		bpp;
		int		line_len;
		int		endian;
	} img;
	int			type;
	double		min_r;
	double		max_r;
	double		min_i;
	double		max_i;
	double		julia_r;
	double		julia_i;
	int			max_iter;
	int			color_scheme;
}				t_fractol;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

void			exit_error(char *s);
void			init_fractol(t_fractol *fractol);
void			my_mlx_pixel_put(t_fractol *fractol, int x, int y, int color);
void			apply_hooks(t_fractol *fractol);
int				calculate_julia(double zr, double zi, t_fractol *fractol);
int				calculate_mandelbrot(double cr, double ci, t_fractol *fractol);
int				calculate_tricorn(double cr, double ci, t_fractol *fractol);
void			render_fractol(t_fractol *fractol);
int				close_window(void *param);

#endif