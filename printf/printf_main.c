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

int		ft_printf(const char * format, ...)
{
//	write(1, "a", 1);
	char	*form;
	t_env	env;
	int		i;
	va_list	ap;

	va_start(ap, format);
	form = (char *)format;
	prf_init(&env);
	i = 0;
	while (form[i])
	{

		if (form[i] != '%')
			push_buff(form[i], &env);
		else
		{
			i = prf_flag(form, i + 1, &env);
			i = prf_field(form, i, &env);
			i = prf_pressi(form, i, &env);
			i = prf_modif(form, i, &env);
			i = prf_conv(form, i, &env, ap);
		}
		++i;
	}
	write(1, env.buffer, env.pos);
	va_end(ap);
	return (i);
}