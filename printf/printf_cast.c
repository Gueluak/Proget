/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:04:11 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/05 10:18:20 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/printf.h"

t_max		ft_cast(va_list arg, int type, int modif)
{
	t_max			t;
	long long int	tmp;

	t.s = 1;
	t.i = 0;
	if (!(type == 1))
	{
		if (modif == 2)
			t.i = ((unsigned long int)((unsigned int)(va_arg(arg, int))));
		if (modif == 0)
			t.i = ((unsigned long int)((unsigned char)(va_arg(arg, int))));
		if (modif == 1)
			t.i = ((unsigned long int)((unsigned short)(va_arg(arg, int))));
		if (modif == 3)
			t.i = ((unsigned long int)((unsigned long int)(va_arg(arg, long int))));
		if (modif == 4)
			t.i = ((unsigned long int)((unsigned long int)(va_arg(arg, long int))));
		if (modif == 5)
			t.i = ((unsigned long int)((size_t)(va_arg(arg, int))));
		if (modif == 6)
			t.i = ((unsigned long int)((uintmax_t)(va_arg(arg, int))));
	}
	else
	{
		if (modif == 2)
			tmp = (((int)(va_arg(arg, int))));
		if (modif == 0)
			tmp = (((char)(va_arg(arg, int))));
		if (modif == 1)
			tmp = (((short)(va_arg(arg, int))));
		if (modif == 3)
			tmp = (((long int)(va_arg(arg, long int))));
		if (modif == 4)
			tmp = (((long long int)(va_arg(arg, long long int))));
		if (modif == 5)
			tmp = (((ssize_t)(va_arg(arg, int))));
		if (modif == 6)
			tmp = (((intmax_t)(va_arg(arg, int))));
		if (tmp < 0)
			t.s = -1;
		t.i = ft_abs(tmp);
	}
	return (t);
}
