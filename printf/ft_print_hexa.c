/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprot <cprot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:59:09 by cprot             #+#    #+#             */
/*   Updated: 2025/04/05 15:59:11 by cprot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned long n, char *tab)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_put_hex(n / 16, tab);
	i += ft_putchar(tab[n % 16]);
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	addr = (unsigned long)ptr;
	count = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	count += 2;
	if (addr == 0)
		count += ft_putchar('0');
	else
		count += ft_put_hex(addr, "0123456789abcdef");
	return (count);
}

int	ft_puthex_lower(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		count = ft_put_hex(n, "0123456789abcdef");
	return (count);
}

int	ft_puthex_upper(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		count = ft_put_hex(n, "0123456789ABCDEF");
	return (count);
}
