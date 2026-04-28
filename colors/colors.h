/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 09:55:19 by cprot             #+#    #+#             */
/*   Updated: 2025/05/19 14:27:52 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include <math.h>

# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define YELLOW 0x00FFFF00
# define CYAN 0x0000FFFF
# define MAGENTA 0x00FF00FF
# define COLOR_TABLE_SIZE 1024

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

int	create_trgb(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);

int	get_color_palette(double t, int palette);
int	get_iteration_color(int iteration, int max_iteration, int color_scheme);

#endif