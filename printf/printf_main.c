/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:07:34 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/22 13:49:04 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_printf(const char *restrict format, ...)
{
	int			i;
	int			j;
	va_list		arg;
	t_print_op	p_op;
	t_max		*l;
//	char		*str;

	i = 0;
	j = 0;
	l = &(p_op.conv);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
//			write(1, "1\n",2);
			ft_init(&p_op);
//			write(1, "2\n",2);
			i = ft_flag((char *)format, i, &p_op);
//			write(1, "3\n",2);
			i = ft_champ((char *)format, i, &p_op);
//			write(1, "4\n",2);
			i = ft_press((char *)format, i, &p_op);
//			write(1, "5\n",2);
			i = ft_modif((char *)format, i, &p_op);
//			write(1, "6\n",2);
			i = ft_conv((char *)format, i, &p_op, arg);
//			write(1, "7\n",2);
			j = ft_print(p_op, format[i]);
//			write(1, "8\n",2);
		}
		else
			write(1, &(format[i]), 1);
		i++;
		j++;
	}
	return (j);
}

void	ft_init(t_print_op *p_op)
{
	p_op->plus = 0;
	p_op->moins = 0;
	p_op->zerro = 0;
	p_op->space = 0;
	p_op->diez = 0;
	p_op->champ = 0;
	p_op->press = -1;
	p_op->modif = 0;
}
