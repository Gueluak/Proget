/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 19:31:00 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/21 19:37:27 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int		ft_modif(char *format, int index, t_print_op *p_op)
{
	int		i;

	while ((i = ft_memnchr(format[index], "hljz", 4)))
	{
		p_op->modif = p_op->modif + (i - 3);
		index++;
	}
	return (index);
}
