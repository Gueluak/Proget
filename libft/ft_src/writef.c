/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 13:58:36 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/10 19:30:06 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int		j_buff(char (*buff)[1024])
{
	write(1, buff, 1024);
	ft_memset(buff, 1024, 0);
	return (0);
}

static void		ft_itobuff_u_base(unsigned long n, \
int b, int *j, char (*buff)[1024])
{
	int		i;
	long	nn;

	nn = n;
	i = 1;
	while ((nn /= b) != 0)
		i++;
	if (n == 0)
		(*buff)[*j] = '0';
	*j = (*j + i >= 1022) ? j_buff(buff) : *j + i;
	i = 0;
	while (n != 0)
	{
		i++;
		(*buff)[*j - i] = (n % b < 10) ? ((n % b) + '0') : ((n % b) - 10 + 'a');
		n = n / b;
	}
}

static void		ft_itobuff_s(long n, int *j, char (*buff)[1024])
{
	int		i;
	int		nn;
	int		is;

	nn = n;
	i = 1;
	while ((nn /= 10) != 0)
		i++;
	is = n < 0 ? 1 : 0;
	i += is;
	if (n == 0)
		(*buff)[*j] = '0';
	*j = (*j + i >= 1022) ? j_buff(buff) : *j + i;
	i = 0;
	while (n != 0)
	{
		i++;
		(*buff)[*j - i] = (ft_abs(n % 10) + '0');
		n /= 10;
	}
	if (is)
		(*buff)[*j] = '-';
}

static int		ft_put(char c, int *j, char (*buff)[1024], va_list arg)
{
	if (c == 'u')
		ft_itobuff_u_base((unsigned long)va_arg\
(arg, unsigned int), 10, j, buff);
	if (c == 'D')
		ft_itobuff_s(va_arg(arg, long), j, buff);
	if (c == 'U')
		ft_itobuff_u_base(va_arg(arg, unsigned long), 10, j, buff);
	if (c == 'X')
		ft_itobuff_u_base(va_arg(arg, unsigned long), 16, j, buff);
	if (c == 'd')
		ft_itobuff_s((long)va_arg(arg, int), j, buff);
	if (c == '%')
		(*buff)[*j++] = '%';
	return (1);
}

int				writef(const char *format, ...)
{
	char	buff[1024];
	int		i;
	int		j;
	va_list	arg;

	ft_memset(buff, 1024, 0);
	i = 0;
	j = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			i += ft_put(format[i + 1], &j, &buff, arg);
		else
			buff[j] = format[i];
		++i;
		++j;
		j = (j == 1022) ? j_buff(&buff) : j;
	}
	if (j != 0)
		write(1, buff, j -1);
	va_end(arg);
	return (0);
}
