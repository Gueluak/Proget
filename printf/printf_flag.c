/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:40:36 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/22 12:55:27 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_flag(char *format, int index, t_print_op *p_op)
{
	int		i;
	void	(*tab_flag[5])(t_print_op *p_op);

	tab_flag[0] = ft_flag_space;
	tab_flag[1] = ft_flag_moins;
	tab_flag[2] = ft_flag_plus;
	tab_flag[3] = ft_flag_diez;
	tab_flag[4] = ft_flag_zerro;

	index++;
	while ((i = ft_memnchr(format[index], " -+#0", 5)))
	{
		tab_flag[i - 1](p_op);
		index++;
	}
	return (index);
}

void	ft_flag_space(t_print_op *p_op)
{
//	printf("1\n");
	if (p_op->plus == 0)
		p_op->space = 1;
}

void	ft_flag_moins(t_print_op *p_op)
{
//	printf("2\n");
	p_op->zerro = 0;
	p_op->moins = 1;
}

void	ft_flag_plus(t_print_op *p_op)
{
	p_op->plus = 1;
	p_op->space = 0;
}

void	ft_flag_diez(t_print_op *p_op)
{
	p_op->diez = 1;
}

void	ft_flag_zerro(t_print_op *p_op)
{
	if (p_op->moins == 0)
		p_op->zerro = 1;
}

