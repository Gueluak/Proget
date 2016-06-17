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
		env->pos = 0;
		push_buff(c, env);
	}
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