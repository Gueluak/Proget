/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 21:11:41 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/25 02:12:23 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_print(t_print_op p_op, char c)
{
	int		i;
	int		j;
	int		(*tab_print[6])(t_print_op p_op);

	tab_print[0] = ft_print_mod;
	tab_print[1] = ft_print_s;
	tab_print[2] = ft_print_s;
	tab_print[3] = ft_print_pointer;
	tab_print[4] = ft_print_d;
	tab_print[5] = ft_print_d;
	j = ft_memnchr(c, "%sSpdDioOuUxXcC", 15);
	i = tab_print[j - 1](p_op);
	return (i);
}

int		ft_print_d(t_print_op p_op)
{
	int		l;
	char	signe;

	signe = (p_op.space == 1 ? ' ' : '+');
	if (p_op.space == 1 || p_op.plus == 1)
		write(1, ((p_op.conv.s < 0) ? ("-") : (&signe)), 1);
	else
		write(1, "-", (p_op.conv.s == -1 ? 1 : 0));
	l = ft_strlen(p_op.str);
	write(1, p_op.str, l);
	return (l);
}

int		ft_print_pointer(t_print_op p_op)
{
	int		l;
	int		j;

	l = ft_strlen(p_op.str);
	j = 0;
	if (p_op.moins == 0)
		while (j++ < p_op.champ - l - 2)
			write(1, " ", 1);
	write(1, "0x", 2);
	write(1, p_op.str, l);
	if (p_op.moins == 1)
		while (j++ < p_op.champ - l - 2)
			write(1, " ", 1);
	return (2 + ((j > l) ? (j) : (l)));
}

int		ft_print_mod(t_print_op p_op)
{
	write(1, "%", 1);
	return (1);
}

int		ft_print_s(t_print_op p_op)
{
	int		i;
	int		j;
	char	c;

	c = ((p_op.zerro == 1)?('0'):(' '));
	if (p_op.press > 0)
		i = ((ft_strlen(p_op.str) > p_op.press) ? (p_op.press) : (ft_strlen(p_op.str)));
	else
		i = ft_strlen(p_op.str);
	j = 0;
	if (p_op.moins == 0)
		while (j++ < p_op.champ - i)
			write(1, &c, 1);
	write(1, p_op.str, i);
	if (p_op.moins == 1)
		while (j++ < p_op.champ - i)
			write(1, &c, 1);
	return (i);
}
