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

int		prf_flag(char *form, int i, t_env *env)
{
	int		j;
	void	(*tab_conv[5])(t_env *env);

	tab_conv[0] = prf_flag_sharp;
	tab_conv[1] = prf_flag_zero;
	tab_conv[2] = prf_flag_less;
	tab_conv[3] = prf_flag_more;
	tab_conv[4] = prf_flag_space;
	while ((j = char_chr(form[i], "#0-+ ")) != -1)
	{
		tab_conv[j](env);
		++i;
	}
	return (i);
}

void	prf_flag_sharp(t_env *env)
{
	env->flag |= SHARP;
}

void	prf_flag_zero(t_env *env)
{
	if ((env->flag & LESS) == 0)
		env->flag |= ZERO;
}

void	prf_flag_less(t_env *env)
{
	env->flag &= ~ZERO;
	env->flag |= LESS;
}

void	prf_flag_more(t_env *env)
{
	env->flag &= ~SPACE;
	env->flag |= MORE;
}

void	prf_flag_space(t_env *env)
{
	if ((env->flag & MORE) == 0)
		env->flag |= SPACE;
}
