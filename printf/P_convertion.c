/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_convertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:17:24 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/24 18:52:11 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/printf.h"

int			ft_modification(const char *restrict format, int i, t_modif *modif)
{
	int		j;
	int		k;
	int		t[3];
	char	*tmp;

	j = i;
	while (!(ft_memnchr(format[i], "sSpdDioOuUxXcC", 14)))
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		if (format[i] == ' ' || format[i] == '+')
		{
			modif->space = (format[i] == ' ' && !(modif->space)) ? 1 : 2;
			i++;
		}
		if (format[i] == '#')
		{
			modif->altern = 1;
			i++;
		}
		if (format[i] == '-')
		{
			modif->champ[1] = -1;
			i++;
		}
		if (format[i] == '0')
		{
			i++;
			modif->champ[0] = 1;
		}
		if (format[i] >= '0' && format[i] <= '9')
		{
			while (format[i + t[1]] >= '0' && format[i + t[1]] <= '9')
				(t[1])++;
			modif->champ[1] = modif->champ[1] * ft_atoi((char *)ft_memndup((void *)(format + i), t[1]));
			i = i + t[1];
		}
		if (format[i] == '.')
		{
			modif->press[0] = 1;
			i++;
			while (format[i + t[0]] >= '0' && format[i + t[0]] <= '9')
				(t[0])++;
			modif->press[1] = ft_atoi((char *)ft_memndup((void *)(format + i), t[0]));
			i = i + t[0];
		}
		if (format[i] == 'h' && format[i + 1] == 'h')
		{
			modif->cast = 0;
			return (i + 2);
		}
		if (format[i] == 'h')
		{
			modif->cast = 1;
			return (i + 1);
		}
		if (format[i] == 'l' && format[i + 1] == 'l')
		{
			modif->cast = 4;
			return (i + 2);
		}
		if (format[i] == 'l')
		{
			modif->cast = 3;
			return (i + 1);
		}
		if (format[i] == 'z')
		{
			modif->cast = 5;
			return (i + 1);
		}
		if (format[i] == 'j')
		{
			modif->cast = 6;
			return (i + 1);
		}
	}
	return (i);
}

int			ft_convertion(const char *restrict format, int i, va_list arg, t_modif modif)
{
	char	x;
	int		k;
	int		j;
	char	*tmp;
	char	c;
	t_type	l;
	int		u;

	k = 0;
	if (modif.champ[0] == 0 || modif.press[0] == 1)
		x = ' ';
	else
		x = '0';
	if (format[i] == 'd' || format[i] == 'i'/* || format[i] == 'u'*/)
	{
//		if (format[i] == 'u')
		//		u = ft_cast(arg, modif, 0);
//		else
		l = ft_cast(modif, arg, 1);
		tmp = ft_itoa(l.j);
		(l.i == -1) ? (u = 1) : (u = 0);
		j = ft_strlen(tmp);
		if (l.i == 1 && modif.space)
			write(1, ((modif.space == 1) ? " " : "+"), 1);
		while (k++ + ((modif.space) ? 1 : 0) + (modif.press[1] > (j + u) ?  modif.press[1] + u : (j + u) )< modif.champ[1])
			write(1, &x,1);
		k = 1;
		if (l.i == -1)
			write(1, "-", 1);
		while (k++ + j <= modif.press[1])
		{
			modif.champ[1]++;
			write(1, "0", 1);
		}
		write(1, tmp, j);
		k = 0;
		while (k-- - j > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == 'u')
	{
		l = ft_cast(modif, arg, 0);
		tmp = ft_itoa(l.j);
		j = ft_strlen(tmp);
		while (k++ + (modif.press[1] > j ?  modif.press[1] : j )< modif.champ[1])
			write(1, &x,1);
		k = 1;
		while (k++ + j <= modif.press[1])
		{
			modif.champ[1]++;
			write(1, "0", 1);
		}
		if (l.i == 1 && modif.space)
			write(1, " ", 1);
		write(1, tmp, j);
		k = 0;
		while (k-- - j > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == '%')
		write(1, "%", 1);
	else if (format[i] == 'o')
	{
		tmp = ft_itoa_octal(va_arg(arg, int));
		j = ft_strlen(tmp);
		if (((modif.champ[0])) && modif.altern)
			write(1, "0", 1);
		while (k++ + (modif.press[1] > j ?  modif.press[1] : j ) + modif.altern < modif.champ[1])
			write(1, &x,1);
		k = 1;
		if ((!(modif.champ[0])) && modif.altern)
			write(1, "0", 1);
		while (k++ + j <= modif.press[1])
		{
			modif.champ[1]++;
			write(1, "0", 1);
		}
		write(1, tmp, j);
		k = 0;
		while (k-- - j - modif.altern > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == 'x' || format[i] == 'X')
	{
		tmp = ft_itoa_hexa(va_arg(arg, int));
		j = ft_strlen(tmp);
		if (((modif.champ[0])) && modif.altern)
			write(1, "0x", 2);
		while (k++ + (modif.press[1] > j ?  modif.press[1] : j ) + (2 * modif.altern) < modif.champ[1])
			write(1, &x,1);
		k = 1;
		if ((!(modif.champ[0])) && modif.altern)
			write(1, "0x", 2);
		while (k++ + j <= modif.press[1])
		{
			modif.champ[1]++;
			write(1, "0", 1);
		}
		if (format[i] == 'X')
			ft_toupper(&tmp);
		write(1, tmp, j);
		k = 0;
		while (k-- - j - (2 * modif.altern) > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == 'c')
	{
		while (k++ + modif.press[1] < modif.champ[1])
			write(1, &x,1);
		k = 0;
		c = (char)va_arg(arg, int);
		write(1, &c, 1);
		while (k-- - 1 > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == 's')
	{
		tmp = (char *)va_arg(arg, long);
		j = ft_strlen(tmp);
		while (k++ + (modif.press[1] > j ? modif.press[1] : j)< modif.champ[1])
			write(1, &x,1);
		k = 0;
		if (modif.press[0])
			write(1, tmp, (modif.press[1] > j ? j : modif.press[1]));
		else
			write(1, tmp, j);
		while (k-- - j > modif.champ[1])
			write(1, &x, 1);
	}
	else if (format[i] == 'p')
	{
		modif.cast = 3;
		l = ft_cast(modif, arg, 0);
		tmp = ft_itoa_hexa((long)l.j);
		j = ft_strlen(tmp);
		while (k++ +(modif.press[1] > j ?  modif.press[1] : j )+ 2 < modif.champ[1])
			write(1, &x,1);
		write(1, "0x", 2);
		write(1, tmp, j);
		k = 0;
		while (k-- - (j + 2) > modif.champ[1])
			write(1, &x, 1);
	}
	return (1);
}
