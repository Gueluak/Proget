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

	printf("'null'\n");
	ft_printf("lapin : |%u|\n", 123);
	printf(   "malin : |%u|\n", 123);
	ft_printf("lapin : |%u|\n", -123);
	printf(   "malin : |%u|\n\n", -123);

	ft_printf("lapin : |%.5u|\n", 123);
	printf(   "malin : |%.5u|\n", 123);
	ft_printf("lapin : |%.5u|\n", -123);
	printf(   "malin : |%.5u|\n\n", -123);

	ft_printf("lapin : |%10u|\n", 123);
	printf(   "malin : |%10u|\n", 123);
	ft_printf("lapin : |%10u|\n", -123);
	printf(   "malin : |%10u|\n\n", -123);

	ft_printf("lapin : |%10.5u|\n", 123);
	printf(   "malin : |%10.5u|\n", 123);
	ft_printf("lapin : |%10.5u|\n", -123);
	printf(   "malin : |%10.5u|\n\n", -123);

	printf("'-'\n")	;
	ft_printf("lapin : |%-u|\n", 123);
	printf(   "malin : |%-u|\n", 123);
	ft_printf("lapin : |%-u|\n", -123);
	printf(   "malin : |%-u|\n\n", -123);

	ft_printf("lapin : |%-.5u|\n", 123);
	printf(   "malin : |%-.5u|\n", 123);
	ft_printf("lapin : |%-.5u|\n", -123);
	printf(   "malin : |%-.5u|\n\n", -123);

	ft_printf("lapin : |%-10u|\n", 123);
	printf(   "malin : |%-10u|\n", 123);
	ft_printf("lapin : |%-10u|\n", -123);
	printf(   "malin : |%-10u|\n\n", -123);

	ft_printf("lapin : |%-10.5u|\n", 123);
	printf(   "malin : |%-10.5u|\n", 123);
	ft_printf("lapin : |%-10.5u|\n", -123);
	printf(   "malin : |%-10.5u|\n\n", -123);

	printf("'+'\n")	;
	ft_printf("lapin : |%+u|\n", 123);
	printf(   "malin : |%+u|\n", 123);
	ft_printf("lapin : |%+u|\n", -123);
	printf(   "malin : |%+u|\n\n", -123);

	ft_printf("lapin : |%+.5u|\n", 123);
	printf(   "malin : |%+.5u|\n", 123);
	ft_printf("lapin : |%+.5u|\n", -123);
	printf(   "malin : |%+.5u|\n\n", -123);

	ft_printf("lapin : |%+10u|\n", 123);
	printf(   "malin : |%+10u|\n", 123);
	ft_printf("lapin : |%+10u|\n", -123);
	printf(   "malin : |%+10u|\n\n", -123);

	ft_printf("lapin : |%+10.5u|\n", 123);
	printf(   "malin : |%+10.5u|\n", 123);
	ft_printf("lapin : |%+10.5u|\n", -123);
	printf(   "malin : |%+10.5u|\n\n", -123);

	printf("' '\n")	;
	ft_printf("lapin : |% u|\n", 123);
	printf(   "malin : |% u|\n", 123);
	ft_printf("lapin : |% u|\n", -123);
	printf(   "malin : |% u|\n\n", -123);

	ft_printf("lapin : |% .5u|\n", 123);
	printf(   "malin : |% .5u|\n", 123);
	ft_printf("lapin : |% .5u|\n", -123);
	printf(   "malin : |% .5u|\n\n", -123);

	ft_printf("lapin : |% 10u|\n", 123);
	printf(   "malin : |% 10u|\n", 123);
	ft_printf("lapin : |% 10u|\n", -123);
	printf(   "malin : |% 10u|\n\n", -123);

	ft_printf("lapin : |% 10.5u|\n", 123);
	printf(   "malin : |% 10.5u|\n", 123);
	ft_printf("lapin : |% 10.5u|\n", -123);
	printf(   "malin : |% 10.5u|\n\n", -123);

	printf("'0'\n")	;
	ft_printf("lapin : |%0u|\n", 123);
	printf(   "malin : |%0u|\n", 123);
	ft_printf("lapin : |%0u|\n", -123);
	printf(   "malin : |%0u|\n\n", -123);

	ft_printf("lapin : |%0.5u|\n", 123);
	printf(   "malin : |%0.5u|\n", 123);
	ft_printf("lapin : |%0.5u|\n", -123);
	printf(   "malin : |%0.5u|\n\n", -123);

	ft_printf("lapin : |%010u|\n", 123);
	printf(   "malin : |%010u|\n", 123);
	ft_printf("lapin : |%010u|\n", -123);
	printf(   "malin : |%010u|\n\n", -123);

	ft_printf("lapin : |%010.5u|\n", 123);
	printf(   "malin : |%010.5u|\n", 123);
	ft_printf("lapin : |%010.5u|\n", -123);
	printf(   "malin : |%010.5u|\n\n", -123);

	printf("'#'\n")	;
	ft_printf("lapin : |%#u|\n", 123);
	printf(   "malin : |%#u|\n", 123);
	ft_printf("lapin : |%#u|\n", -123);
	printf(   "malin : |%#u|\n\n", -123);

	ft_printf("lapin : |%#.5u|\n", 123);
	printf(   "malin : |%#.5u|\n", 123);
	ft_printf("lapin : |%#.5u|\n", -123);
	printf(   "malin : |%#.5u|\n\n", -123);

	ft_printf("lapin : |%#10u|\n", 123);
	printf(   "malin : |%#10u|\n", 123);
	ft_printf("lapin : |%#10u|\n", -123);
	printf(   "malin : |%#10u|\n\n", -123);

	ft_printf("lapin : |%#10.5u|\n", 123);
	printf(   "malin : |%#10.5u|\n", 123);
	ft_printf("lapin : |%#10.5u|\n", -123);
	printf(   "malin : |%#10.5u|\n\n", -123);

	return (0);
}
