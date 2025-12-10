/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldecavel <ldecavel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 18:38:50 by ldecavel          #+#    #+#             */
/*   Updated: 2025/12/10 18:12:28 by nlallema         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	size_putstr(int fd, const char *s)
{
	int	size;

	if (!s)
		s = "(null)";
	size = -1;
	while (s[++size])
		;
	return (write(fd, s, size));
}

static int	size_putnbr(int fd, int64_t n)
{
	int		size;
	char	c;

	size = 0;
	if (n < 0)
	{
		size += write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		size += size_putnbr(fd, n / 10);
	c = n % 10 + '0';
	return (size + write(fd, &c, 1));
}

static int	size_puthex(int fd, uint64_t n, char a, char c)
{
	int		size;
	char	b[16];
	int		res;
	int		i;

	size = 0;
	i = 0;
	if (n == 0 && c == 'p')
		return (size_putstr(fd, "(nil)"));
	if (n == 0)
		return (write(fd, "0", 1));
	if (c == 'p')
		size += size_putstr(fd, "0x");
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
		size += write(fd, &b[i], 1);
	return (size);
}

static int	size_put_param(int fd, va_list pm, char c)
{
	int	n;
	int	tmp;

	n = 0;
	if (c == 'c')
	{
		tmp = va_arg(pm, int);
		n += write(fd, &tmp, 1);
	}
	else if (c == 's')
		n += size_putstr(fd, va_arg(pm, const char *));
	else if (c == 'p')
		n += size_puthex(fd, (uint64_t)va_arg(pm, void *), 'a', c);
	else if (c == 'd' || c == 'i')
		n += size_putnbr(fd, (int)va_arg(pm, int));
	else if (c == 'u')
		n += size_putnbr(fd, (unsigned int)va_arg(pm, unsigned int));
	else if (c == 'x')
		n += size_puthex(fd, (uint64_t)va_arg(pm, unsigned int), 'a', c);
	else if (c == 'X')
		n += size_puthex(fd, (uint64_t)va_arg(pm, unsigned int), 'A', c);
	else if (c == '%')
		n += write(fd, "%", 1);
	return (n);
}

extern int	ft_dprintf(int fd, const char *s, ...)
{
	t_dprintf	dprintf;

	dprintf = (t_dprintf){0};
	va_start(dprintf.param, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			dprintf.current = size_put_param(fd, dprintf.param, *s);
		}
		else
			dprintf.current = write(fd, s, 1);
		if (*s)
			s++;
		if (dprintf.current > -1)
			dprintf.n += dprintf.current;
		else
		{
			dprintf.n = -1;
			break ;
		}
	}
	va_end(dprintf.param);
	return (dprintf.n);
}
