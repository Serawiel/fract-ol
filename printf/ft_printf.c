/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:59:17 by cprot             #+#    #+#             */
/*   Updated: 2025/04/05 15:59:20 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_type(char format, va_list va_args, int *count)
{
	if (format == 'c')
		*count += ft_putchar(va_arg(va_args, int));
	else if (format == 's')
		*count += ft_putstr(va_arg(va_args, char *));
	else if (format == 'p')
		*count += ft_putptr(va_arg(va_args, void *));
	else if (format == 'd' || format == 'i')
		*count += ft_putnbr(va_arg(va_args, int));
	else if (format == 'u')
		*count += ft_putunnbr(va_arg(va_args, unsigned int));
	else if (format == 'x')
		*count += ft_puthex_lower(va_arg(va_args, unsigned int));
	else if (format == 'X')
		*count += ft_puthex_upper(va_arg(va_args, unsigned int));
	else if (format == '%')
		*count += ft_putchar('%');
	else
	{
		*count += ft_putchar('?');
		*count += ft_putchar(format);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			format_type(format[i + 1], args, &count);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
