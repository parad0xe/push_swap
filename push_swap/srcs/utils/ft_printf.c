/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:38:50 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 14:09:48 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	size_putstr(const char *s)
{
	int	size;

	if (!s)
		s = "(null)";
	size = -1;
	while (s[++size])
		;
	return (write(1, s, size));
}

static int	size_putnbr(int64_t n)
{
	int		size;
	char	c;

	size = 0;
	if (n < 0)
	{
		size += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		size += size_putnbr(n / 10);
	c = n % 10 + '0';
	return (size + write(1, &c, 1));
}

static int	size_puthex(uint64_t n, char a, char c)
{
	int		size;
	char	b[16];
	int		res;
	int		i;

	size = 0;
	i = 0;
	if (n == 0 && c == 'p')
		return (size_putstr("(nil)"));
	if (n == 0)
		return (write(1, "0", 1));
	if (c == 'p')
		size += size_putstr("0x");
	while (n)
	{
		res = (unsigned int)(n & 0xF);
		if (res < 10)
			b[i++] = '0' + res;
		else
			b[i++] = a + (res - 10);
		n >>= 4;
	}
	while (i--)
		size += write(1, &b[i], 1);
	return (size);
}

static int	size_put_param(va_list pm, char c)
{
	int	n;
	int	tmp;

	n = 0;
	if (c == 'c')
	{
		tmp = va_arg(pm, int);
		n += write(1, &tmp, 1);
	}
	else if (c == 's')
		n += size_putstr(va_arg(pm, const char *));
	else if (c == 'p')
		n += size_puthex((uint64_t)va_arg(pm, void *), 'a', c);
	else if (c == 'd' || c == 'i')
		n += size_putnbr((int)va_arg(pm, int));
	else if (c == 'u')
		n += size_putnbr((unsigned int)va_arg(pm, unsigned int));
	else if (c == 'x')
		n += size_puthex((uint64_t)va_arg(pm, unsigned int), 'a', c);
	else if (c == 'X')
		n += size_puthex((uint64_t)va_arg(pm, unsigned int), 'A', c);
	else if (c == '%')
		n += write(1, "%", 1);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	t_printf	printf;

	printf = (t_printf){0};
	va_start(printf.param, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			printf.current = size_put_param(printf.param, *s);
		}
		else
			printf.current = write(1, s, 1);
		if (*s)
			s++;
		if (printf.current > -1)
			printf.n += printf.current;
		else
		{
			printf.n = -1;
			break ;
		}
	}
	va_end(printf.param);
	return (printf.n);
}
