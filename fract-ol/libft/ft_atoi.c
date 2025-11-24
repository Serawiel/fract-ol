/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 09:19:09 by cprot             #+#    #+#             */
/*   Updated: 2025/05/17 10:21:39 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_whitespace_and_sign(const char *str, int *i, double *sign)
{
	*sign = 1.0;
	*i = 0;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1.0;
		(*i)++;
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		nb;
	double	sign;
	int		i;

	nb = 0;
	skip_whitespace_and_sign(nptr, &i, &sign);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		nb = nb * 10 + (nptr[i++] - '0');
	return (nb * sign);
}

double	ft_atof(const char *str)
{
	double	result;
	double	sign;
	double	decimal;
	int		i;

	result = 0.0;
	skip_whitespace_and_sign(str, &i, &sign);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10.0 + (str[i++] - '0');
	if (str[i] == '.')
	{
		i++;
		decimal = 0.1;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i++] - '0') * decimal;
			decimal *= 0.1;
		}
	}
	return (result * sign);
}
