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

int		prf_conv(char *format, int i, t_env	*env)
{
	int		j;	
	void	(*tab_conv[1])(t_env *env);
//	write(1, "d", 1);

	tab_conv[0] = prf_conv_mod;

	j = char_chr(format[i], "%");
	if (j != -1)
	{
		tab_conv[j](env);
		return (i);
	}
	else
	return (-1);
}

void	prf_conv_mod(t_env *env)
{
//	write(1, "e", 1);
	push_buff('%', env);
}