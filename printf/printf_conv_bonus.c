/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conv_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 12:58:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/09/17 12:58:32 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	prf_con_m(t_env *env, va_list ap)
{
	unsigned char	*mem;
	int				i;
	int				len;

	i = 0;
	env->modif = 3;
	mem = (unsigned char *)prf_u_arg(ap, *env);
	if (mem == NULL)
	{
		return_null(env);
		return;
	}
	len = env->pressi == -1 ? 1 : env->pressi;
	prf_print_mem(env, mem, len);
}

void	prf_print_mem(t_env *env, unsigned char *mem, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		prf_itoa_b(mem[i] / 16, env, 16, 1);
		push_buff('.', env);
		prf_itoa_b(mem[i] % 16, env, 16, 1);
		++i;
		i < len || env->flag & SHARP ? push_buff(' ', env) : 0;
		i % 4 && i != len ? 0 : prf_mod_int(env, mem, i, len);
	}
}

void	prf_mod_int(t_env *env, unsigned char *mem, int i, int len)
{
	int		nb;
	int		j;

	j = -1;
	nb = (i % 4 ? i % 4 : 4);
	if (env->flag & SHARP)
	{
		while (++j < 5 - nb)
			push_buff('	', env);
		push_buff('-', env);
		push_buff('-', env);
		push_buff('>', env);
		push_buff(' ', env);
		while (nb)
		{
			mem[i - nb] > 31 && mem[i - nb] < 127 ? \
			push_buff(mem[i - nb], env) : push_buff('.', env);
			--nb;
		}
	}
	i < len ? push_buff('\n', env) : 0;
}

void	prf_con_b(t_env *env, va_list ap)
{
	unsigned long	arg;
	int				len;

	arg = prf_u_arg(ap, *env);
	env->flag &= ~ ZERO;
	len = nb_len_b(arg, 2);
	len = env->flag & SHARP ? len + (len - 1) / 4 : len;
	env->flag & LESS ? 0 : prf_pos_field(env, len);
	env->pressi == 0 && arg == 0 ? 0 : prf_itoa_bin(arg, env, 1);
	env->flag & LESS ? prf_pos_field(env, len) : 0;
}

int		prf_itoa_bin(unsigned long nb, t_env *env, int index)
{
	if (nb >= 2)
		prf_itoa_bin(nb >> 1, env, index + 1);
	index % 4 == 0 && env->flag & SHARP && nb > 1 ? push_buff(' ', env) : 0; 
	push_buff((nb & 1) + '0', env);
	return (index + 1);
}