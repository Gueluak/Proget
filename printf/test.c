/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:10:37 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/25 02:12:29 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			main(int ac, char **av)
{

	printf("null\n");
	ft_printf("lapin : |%d|\n", 123);
	printf(   "malin : |%d|\n", 123);
	ft_printf("lapin : |%d|\n", -123);
	printf(   "malin : |%d|\n\n", -123);

	ft_printf("lapin : |%.5d|\n", 123);
	printf(   "malin : |%.5d|\n", 123);
	ft_printf("lapin : |%.5d|\n", -123);
	printf(   "malin : |%.5d|\n\n", -123);

	ft_printf("lapin : |%10d|\n", 123);
	printf(   "malin : |%10d|\n", 123);
	ft_printf("lapin : |%10d|\n", -123);
	printf(   "malin : |%10d|\n\n", -123);

	ft_printf("lapin : |%10.5d|\n", 123);
	printf(   "malin : |%10.5d|\n", 123);
	ft_printf("lapin : |%10.5d|\n", -123);
	printf(   "malin : |%10.5d|\n\n", -123);

	printf("'-'\n")	;
	ft_printf("lapin : |%-d|\n", 123);
	printf(   "malin : |%-d|\n", 123);
	ft_printf("lapin : |%-d|\n", -123);
	printf(   "malin : |%-d|\n\n", -123);

	ft_printf("lapin : |%-.5d|\n", 123);
	printf(   "malin : |%-.5d|\n", 123);
	ft_printf("lapin : |%-.5d|\n", -123);
	printf(   "malin : |%-.5d|\n\n", -123);

	ft_printf("lapin : |%-10d|\n", 123);
	printf(   "malin : |%-10d|\n", 123);
	ft_printf("lapin : |%-10d|\n", -123);
	printf(   "malin : |%-10d|\n\n", -123);

	ft_printf("lapin : |%-10.5d|\n", 123);
	printf(   "malin : |%-10.5d|\n", 123);
	ft_printf("lapin : |%-10.5d|\n", -123);
	printf(   "malin : |%-10.5d|\n\n", -123);

	printf("'+'\n")	;
	ft_printf("lapin : |%+d|\n", 123);
	printf(   "malin : |%+d|\n", 123);
	ft_printf("lapin : |%+d|\n", -123);
	printf(   "malin : |%+d|\n\n", -123);

	ft_printf("lapin : |%+.5d|\n", 123);
	printf(   "malin : |%+.5d|\n", 123);
	ft_printf("lapin : |%+.5d|\n", -123);
	printf(   "malin : |%+.5d|\n\n", -123);

	ft_printf("lapin : |%+10d|\n", 123);
	printf(   "malin : |%+10d|\n", 123);
	ft_printf("lapin : |%+10d|\n", -123);
	printf(   "malin : |%+10d|\n\n", -123);

	ft_printf("lapin : |%+10.5d|\n", 123);
	printf(   "malin : |%+10.5d|\n", 123);
	ft_printf("lapin : |%+10.5d|\n", -123);
	printf(   "malin : |%+10.5d|\n\n", -123);

	printf("' '\n")	;
	ft_printf("lapin : |% d|\n", 123);
	printf(   "malin : |% d|\n", 123);
	ft_printf("lapin : |% d|\n", -123);
	printf(   "malin : |% d|\n\n", -123);

	ft_printf("lapin : |% .5d|\n", 123);
	printf(   "malin : |% .5d|\n", 123);
	ft_printf("lapin : |% .5d|\n", -123);
	printf(   "malin : |% .5d|\n\n", -123);

	ft_printf("lapin : |% 10d|\n", 123);
	printf(   "malin : |% 10d|\n", 123);
	ft_printf("lapin : |% 10d|\n", -123);
	printf(   "malin : |% 10d|\n\n", -123);

	ft_printf("lapin : |% 10.5d|\n", 123);
	printf(   "malin : |% 10.5d|\n", 123);
	ft_printf("lapin : |% 10.5d|\n", -123);
	printf(   "malin : |% 10.5d|\n\n", -123);

	printf("'0\n")	;
	ft_printf("lapin : |%0d|\n", 123);
	printf(   "malin : |%0d|\n", 123);
	ft_printf("lapin : |%0d|\n", -123);
	printf(   "malin : |%0d|\n\n", -123);

	ft_printf("lapin : |%0.5d|\n", 123);
	printf(   "malin : |%0.5d|\n", 123);
	ft_printf("lapin : |%0.5d|\n", -123);
	printf(   "malin : |%0.5d|\n\n", -123);

	ft_printf("lapin : |%010d|\n", 123);
	printf(   "malin : |%010d|\n", 123);
	ft_printf("lapin : |%010d|\n", -123);
	printf(   "malin : |%010d|\n\n", -123);

	ft_printf("lapin : |%010.5d|\n", 123);
	printf(   "malin : |%010.5d|\n", 123);
	ft_printf("lapin : |%010.5d|\n", -123);
	printf(   "malin : |%010.5d|\n\n", -123);

	printf("'#\n")	;
	ft_printf("lapin : |%#d|\n", 123);
	printf(   "malin : |%#d|\n", 123);
	ft_printf("lapin : |%#d|\n", -123);
	printf(   "malin : |%#d|\n\n", -123);

	ft_printf("lapin : |%#.5d|\n", 123);
	printf(   "malin : |%#.5d|\n", 123);
	ft_printf("lapin : |%#.5d|\n", -123);
	printf(   "malin : |%#.5d|\n\n", -123);

	ft_printf("lapin : |%#10d|\n", 123);
	printf(   "malin : |%#10d|\n", 123);
	ft_printf("lapin : |%#10d|\n", -123);
	printf(   "malin : |%#10d|\n\n", -123);

	ft_printf("lapin : |%#10.5d|\n", 123);
	printf(   "malin : |%#10.5d|\n", 123);
	ft_printf("lapin : |%#10.5d|\n", -123);
	printf(   "malin : |%#10.5d|\n\n", -123);

	return (0);
}
