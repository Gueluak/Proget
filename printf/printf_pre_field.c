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
		env->flag &= ~ZERO;
		env->pressi = 0;
		++i;
		while ((j = char_chr(form[i], "0123456789")) != -1)
		{
			env->pressi *= 10;
			env->pressi += j;
			++i;
		}
	}
	return (i);
}

void	prf_pos_pressi(t_env *env, int len)
{
	if (env->pressi != -1)
	{
		while (len < env->pressi)
		{
			push_buff('0', env);
			--env->pressi;
		}
	}
}

int		prf_field(char *form, int i, t_env *env)
{
	int		j;

	while ((j = char_chr(form[i], "0123456789")) != -1)
	{
		env->field *= 10;
		env->field += j;
		++i;
	}	
	return (i);
}

void	prf_pos_field(t_env *env, int len)
{
	while (len < env->field)
	{
		push_buff(env->flag & ZERO ? '0' : ' ', env);
		--env->field;
	}
}