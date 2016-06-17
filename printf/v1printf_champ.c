/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_champ.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:16:08 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/21 19:19:54 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft.h"

int		ft_champ(char *format, int index, t_print_op *p_op)
{
	while (ft_memnchr(format[index], "1234567890", 10))
	{
		p_op->champ = (p_op->champ * 10) + (format[index] - '0');
		index++;
	}
	return (index);
}
