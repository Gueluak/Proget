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

void	push_buff(char c, t_env *env)
{
//	write(1, "b", 1);
	if (env->pos < BUFF_SIZE)
	{
		env->buffer[env->pos] = c;
		++(env->pos);
	}
	else
	{
		write(1, env->buffer, BUFF_SIZE);
		env->ret += env->pos; 
		env->pos = 0;
		push_buff(c, env);
	}
}

int		push_uni(wchar_t c, t_env *env, int nbbi)
{
	if (nbbi >= 1 && nbbi <= 7)
		push_buff(c, env);
	else if (nbbi >= 8 && nbbi <= 11)
	{
		push_buff(((3 << 6) | (c >> 6)), env);
		push_buff(((1 << 7) | (63 & c)), env);
		return (2);
	}
	else if (nbbi >= 12 && nbbi <= 16)
	{
		push_buff((7 << 5) | (c >> 12), env);
		push_buff((1 << 7) | (63 & (c >> 6)), env);
		push_buff((1 << 7) | (63 & c), env);
		return (3);
	}
	else if (nbbi >= 17 && nbbi <= 21)
	{
		push_buff((15 << 4) | (c >> 18), env);
		push_buff((1 << 7) | (63 & (c >> 12)), env);
		push_buff((1 << 7) | (63 & (c >> 6)), env);
		push_buff((1 << 7) | (63 & c), env);
		return (4);
	}
		return (1);
}

int		prf_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int		prf_strlen_uni(wchar_t *str)
{
	int		i;
	int		ret;
	int		nbbi;

	i = 0;
	ret = 0;
	while (str[i])
	{
		nbbi = nb_len_b(str[i], 2);
		if (nbbi >= 1 && nbbi <= 7)
			++ret;
		else if (nbbi >= 8 && nbbi <= 11)
			ret+=2;
		else if (nbbi >= 12 && nbbi <= 16)
			ret+=3;
		else if (nbbi >= 17 && nbbi <= 21)
			ret+=4;
		++i;
	}
	return (ret);
}

int		char_chr(char c, char *chr)
{
//	write(1, "c", 1);
	int		i;

	i = 0;
	while (chr[i])
	{
		if (c == chr[i])
			return (i);
		++i;
	}
	return (-1);
}

void	aply_signe(long nb, t_env *env)
{
	if (nb < 0)
		push_buff('-', env);
	else if (env->flag & MORE)
		push_buff('+', env);
	else if (env->flag & SPACE)
		push_buff(' ', env);
}

int		nb_len(long nb)
{
	long	tmp;
	int		i;

	tmp = nb < 0 ? -nb : nb;
	i = 1;
	while(tmp >= 10)
	{
		(tmp = tmp / 10);
		++i;
	}
	return (i);
}

void	aply_sharp(t_env *env, int conv)
{
	if (conv == 1)
	{
		push_buff('0', env);
		push_buff('x', env);
	}
	else if (conv == 2)
	{
		push_buff('0', env);
		push_buff('X', env);
	}
	else if (conv == 3)
		push_buff('0', env);
}

int		nb_len_b(unsigned long nb, int b)
{
	double	tmp;
	int		i;

	tmp = nb;
	i = 1;
	while(tmp >= b)
	{
		(tmp = tmp / b);
		++i;
	}
	return (i);	
}

void	prf_itoa(long nb, t_env *env)
{
	long	tmp;

	tmp = nb < 0 ? -nb : nb;
	if (tmp >= 10)
		prf_itoa(tmp / 10, env);
	push_buff((tmp % 10 + '0'), env);
}

void	prf_itoa_b(unsigned long nb, t_env *env, int b, int maj)
{
	char	*base;

	base = maj == 0 ? "0123456789abcdef" : "0123456789ABCDEF";
	if (nb >= b)
		prf_itoa_b(nb / b, env, b, maj);
	push_buff((base[nb % b]), env);
}