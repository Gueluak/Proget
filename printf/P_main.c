/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:04:11 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/24 18:28:45 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/printf.h"

int			ft_printf(const char *restrict format, ...)
{
	int		i;
	t_modif	modif;
	va_list	arg;

	va_start(arg, format);
	i = 0;
	while (format[i])
	{
		modif.press[0] = 0;
		modif.press[1] = 1;
		modif.champ[0] = 0;
		modif.champ[1] = 1;
		modif.altern = 0;
		modif.space = 0;
		modif.cast = 2;
		if (format[i] == '%')
		{
			i = ft_modification(format, i + 1, &modif);
			i = i + ft_convertion(format, i, arg, modif);
		}
		write(1,format + i, 1);
		i++;
	}
	va_end(arg);
	return (i);
}

t_type		ft_cast(t_modif modif, va_list arg, int type)
{
	t_type			t;
	long long int	tmp;

	t.i = 1;
	t.j = 0;
	if (!(type))
	{
		if (modif.cast == 2)
			t.j = ((max_t)((unsigned int)(va_arg(arg, int))));
		if (modif.cast == 0)
			t.j = ((max_t)((unsigned char)(va_arg(arg, int))));
		if (modif.cast == 1)
			t.j = ((max_t)((unsigned short)(va_arg(arg, int))));
		if (modif.cast == 3)
			t.j = ((max_t)((unsigned long int)(va_arg(arg, long int))));
		if (modif.cast == 4)
			t.j = ((max_t)((unsigned long long int)(va_arg(arg, long long int))));
		if (modif.cast == 5)
			t.j = ((max_t)((size_t)(va_arg(arg, int))));
		if (modif.cast == 6)
			t.j = ((max_t)((uintmax_t)(va_arg(arg, int))));
	}
	else
	{
		if (modif.cast == 2)
			tmp = (((int)(va_arg(arg, int))));
		if (modif.cast == 0)
			tmp = (((char)(va_arg(arg, int))));
		if (modif.cast == 1)
			tmp = (((short)(va_arg(arg, int))));
		if (modif.cast == 3)
			tmp = (((long int)(va_arg(arg, long int))));
		if (modif.cast == 4)
			tmp = (((long long int)(va_arg(arg, long long int))));
		if (modif.cast == 5)
			tmp = (((ssize_t)(va_arg(arg, int))));
		if (modif.cast == 6)
			tmp = (((intmax_t)(va_arg(arg, int))));
		if (tmp < 0)
			t.i = -1;
		t.j = ft_abs(tmp);
	}
	return (t);
}
