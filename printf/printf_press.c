/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:20:04 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/22 12:42:33 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_press(char *format, int index, t_print_op *p_op)
{
	if (format[index] == '.')
	{
		p_op->press = ((p_op->press < 0)?(0):(p_op->press));
		p_op->zerro = 0;
		index++;
		while (ft_memnchr(format[index], "0123456789", 10))
		{
			p_op->press = (p_op->press * 10) + (format[index] - '0');
			index++;
		}
	}
	return (index);
}
