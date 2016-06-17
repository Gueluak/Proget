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

#include "printf.h"

unsigned long	prf_u_arg(va_list ap, t_env env)
{
	if (env.modif == 0)
		return (va_arg(ap, unsigned int));
	if (env.modif == 0)
		return (va_arg(ap, unsigned long));
	if (env.modif == 0)
		return ((unsigned long)(unsigned short)va_arg(ap, unsigned int));
	if (env.modif == 0)
		return ((unsigned long)(unsigned char)va_arg(ap, unsigned int));
	return (0);
}

long			prf_arg(va_list ap, t_env env)
{
	if (env.modif == 0)
		return (va_arg(ap, int));
	if (env.modif == 0)
		return (va_arg(ap, long));
	if (env.modif == 0)
		return ((long)(short)va_arg(ap, int));
	if (env.modif == 0)
		return ((long)(char)va_arg(ap, int));
	return (0);
}