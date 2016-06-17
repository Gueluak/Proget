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

int		prf_pressi(char *form, int i, t_env *env)
{
	int		j;

	if (form[i] == '.')
	{
		++i;
		while ((j = char_chr(form[i], "0123456789")) != -1)
		{
			env->pressi += j;
			++i;
		}
	}
	return (i);
}

int		prf_field(char *form, int i, t_env *env)
{
	int		j;

	while ((j = char_chr(form[i], "0123456789")) != -1)
	{
		env->field += j;
		++i;
	}	
	return (i);
}