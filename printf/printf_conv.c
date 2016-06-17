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

int		prf_conv(char *format, int i, t_env	*env, va_list ap)
{
	int		j;	
	void	(*tab_conv[6])(t_env *env, va_list ap);
//	write(1, "d", 1);

	tab_conv[0] = prf_conv_mod;
	tab_conv[1] = prf_con_id;
	tab_conv[2] = prf_con_id;
	tab_conv[3] = prf_con_ld;
	tab_conv[4] = prf_con_u;

	j = char_chr(format[i], "%idDu");
	if (j != -1)
	{
		tab_conv[j](env, ap);
		return (i);
	}
	else
	return (-1);
}

void	prf_conv_mod(t_env *env, va_list ap)
{
//	write(1, "e", 1);
	push_buff('%', env);
}

void	prf_con_s(t_env *env, va_list ap)
{
	return;
}

void	prf_con_ls(t_env *env, va_list ap)
{
	return;
}

void	prf_con_p(t_env *env, va_list ap)
{
	return;
}

void	prf_con_ld(t_env *env, va_list ap)
{
	env->modif = 3;
	prf_con_id(env, ap);
}

void	prf_con_id(t_env *env, va_list ap)
{
	long	arg;
	int		len;
	int		i;

	arg = prf_arg(ap, *env);
	len = nb_len(arg);
	i = len < env->pressi ? env->pressi : len;
	env->flag & ZERO ? aply_signe(arg, env) : 0;
	env->flag & LESS ? 0 : prf_pos_field(env, i + (arg < 0 || env->flag & MORE || env->flag & SPACE));
	env->flag & ZERO ? 0 : aply_signe(arg, env);
	prf_pos_pressi(env, len);
	prf_itoa(arg, env);
	env->flag & LESS ? prf_pos_field(env, i + (arg < 0 || env->flag & MORE || env->flag & SPACE)) : 0;
}

void	prf_con_o(t_env *env, va_list ap)
{
	return;
}

void	prf_con_lo(t_env *env, va_list ap)
{
	return;
}

void	prf_con_u(t_env *env, va_list ap)
{
	unsigned long	arg;
	int				len;
	int				i;

	arg = prf_u_arg(ap, *env);
	len = nb_len_b(arg, 10);
	i = len < env->pressi ? env->pressi : len;
	env->flag & LESS ? 0 : prf_pos_field(env, i);
	prf_pos_pressi(env, len);
	prf_itoa_b(arg, env, 10, 0);
	env->flag & LESS ? prf_pos_field(env, i) : 0;
}

void	prf_con_lu(t_env *env, va_list ap)
{
	return;
}

void	prf_con_x(t_env *env, va_list ap)
{
	return;
}

void	prf_con_lx(t_env *env, va_list ap)
{
	return;
}

void	prf_con_c(t_env *env, va_list ap)
{
	return;
}

void	prf_con_lc(t_env *env, va_list ap)
{
	return;
}

