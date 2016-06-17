/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:27:29 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/21 21:41:40 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_conv(char *format, int index, t_print_op *p_op, va_list va)
{
	if (ft_memnchr(format[index], "di", 2))
		p_op->conv = ft_cast(va, 1, 2 + p_op->modif);
	if (ft_memnchr(format[index], "oux", 3))
		p_op->conv = ft_cast(va, 0, 2 + p_op->modif);
	if (ft_memnchr(format[index], "OUX", 3))
		p_op->conv = ft_cast(va, 0, 3 + p_op->modif);
	if (ft_memnchr(format[index], "D", 1))
		p_op->conv = ft_cast(va, 1, 3 + p_op->modif);
	if (ft_memnchr(format[index], "sp", 2))
		p_op->conv = ft_cast(va, 0, 4);
	if (ft_memnchr(format[index], "c", 1))
		p_op->conv = ft_cast(va, 0, 0);
	ft_conv_type(format[index], p_op);
	return (index);
}

void	ft_conv_type(char i, t_print_op *p_op)
{
	t_max	n;

	n = p_op->conv;
	if (ft_memnchr(i, "dDiuU", 5))
		p_op->str = ft_itoa(n.i);
	if (ft_memnchr(i, "pxX", 3))
		p_op->str = ft_itoa_hexa(n.i);
	if (ft_memnchr(i, "oO", 2))
		p_op->str = ft_itoa_octal(n.i);
	if (ft_memnchr(i, "sS", 2))
		p_op->str = (char *)n.i;
	if (ft_memnchr(i, "cC", 2))
	{
		p_op->str = (char *)ft_memalloc(2);
		*(p_op->str) = (char)(n.i);
	}
}
