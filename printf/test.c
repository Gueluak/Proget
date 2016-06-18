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
	char *str = "lapin123";
	printf("'null'\n");
	ft_printf("lapin : |%s|\n", str);
	printf(   "malin : |%s|\n", str);
	ft_printf("lapin : |%s|\n",  str);
	printf(   "malin : |%s|\n\n",  str);

	ft_printf("lapin : |%.5s|\n", str);
	printf(   "malin : |%.5s|\n", str);
	ft_printf("lapin : |%.5s|\n",  str);
	printf(   "malin : |%.5s|\n\n",  str);

	ft_printf("lapin : |%10s|\n", str);
	printf(   "malin : |%10s|\n", str);
	ft_printf("lapin : |%10s|\n",  str);
	printf(   "malin : |%10s|\n\n",  str);

	ft_printf("lapin : |%10.5s|\n", str);
	printf(   "malin : |%10.5s|\n", str);
	ft_printf("lapin : |%10.5s|\n",  str);
	printf(   "malin : |%10.5s|\n\n",  str);

	printf("'-'\n")	;
	ft_printf("lapin : |%-s|\n", str);
	printf(   "malin : |%-s|\n", str);
	ft_printf("lapin : |%-s|\n",  str);
	printf(   "malin : |%-s|\n\n",  str);

	ft_printf("lapin : |%-.5s|\n", str);
	printf(   "malin : |%-.5s|\n", str);
	ft_printf("lapin : |%-.5s|\n",  str);
	printf(   "malin : |%-.5s|\n\n",  str);

	ft_printf("lapin : |%-10s|\n", str);
	printf(   "malin : |%-10s|\n", str);
	ft_printf("lapin : |%-10s|\n",  str);
	printf(   "malin : |%-10s|\n\n",  str);

	ft_printf("lapin : |%-10.5s|\n", str);
	printf(   "malin : |%-10.5s|\n", str);
	ft_printf("lapin : |%-10.5s|\n",  str);
	printf(   "malin : |%-10.5s|\n\n",  str);

	printf("'+'\n")	;
	ft_printf("lapin : |%+s|\n", str);
	printf(   "malin : |%+s|\n", str);
	ft_printf("lapin : |%+s|\n",  str);
	printf(   "malin : |%+s|\n\n",  str);

	ft_printf("lapin : |%+.5s|\n", str);
	printf(   "malin : |%+.5s|\n", str);
	ft_printf("lapin : |%+.5s|\n",  str);
	printf(   "malin : |%+.5s|\n\n",  str);

	ft_printf("lapin : |%+10s|\n", str);
	printf(   "malin : |%+10s|\n", str);
	ft_printf("lapin : |%+10s|\n",  str);
	printf(   "malin : |%+10s|\n\n",  str);

	ft_printf("lapin : |%+10.5s|\n", str);
	printf(   "malin : |%+10.5s|\n", str);
	ft_printf("lapin : |%+10.5s|\n",  str);
	printf(   "malin : |%+10.5s|\n\n",  str);

	printf("' '\n")	;
	ft_printf("lapin : |% s|\n", str);
	printf(   "malin : |% s|\n", str);
	ft_printf("lapin : |% s|\n",  str);
	printf(   "malin : |% s|\n\n",  str);

	ft_printf("lapin : |% .5s|\n", str);
	printf(   "malin : |% .5s|\n", str);
	ft_printf("lapin : |% .5s|\n",  str);
	printf(   "malin : |% .5s|\n\n",  str);

	ft_printf("lapin : |% 10s|\n", str);
	printf(   "malin : |% 10s|\n", str);
	ft_printf("lapin : |% 10s|\n",  str);
	printf(   "malin : |% 10s|\n\n",  str);

	ft_printf("lapin : |% 10.5s|\n", str);
	printf(   "malin : |% 10.5s|\n", str);
	ft_printf("lapin : |% 10.5s|\n",  str);
	printf(   "malin : |% 10.5s|\n\n",  str);

	printf("'0'\n")	;
	ft_printf("lapin : |%0s|\n", str);
	printf(   "malin : |%0s|\n", str);
	ft_printf("lapin : |%0s|\n",  str);
	printf(   "malin : |%0s|\n\n",  str);

	ft_printf("lapin : |%0.5s|\n", str);
	printf(   "malin : |%0.5s|\n", str);
	ft_printf("lapin : |%0.5s|\n",  str);
	printf(   "malin : |%0.5s|\n\n",  str);

	ft_printf("lapin : |%010s|\n", str);
	printf(   "malin : |%010s|\n", str);
	ft_printf("lapin : |%010s|\n",  str);
	printf(   "malin : |%010s|\n\n",  str);

	ft_printf("lapin : |%010.5s|\n", str);
	printf(   "malin : |%010.5s|\n", str);
	ft_printf("lapin : |%010.5s|\n",  str);
	printf(   "malin : |%010.5s|\n\n",  str);

	printf("'#'\n")	;
	ft_printf("lapin : |%#s|\n", str);
	printf(   "malin : |%#s|\n", str);
	ft_printf("lapin : |%#s|\n",  str);
	printf(   "malin : |%#s|\n\n",  str);

	ft_printf("lapin : |%#.5s|\n", str);
	printf(   "malin : |%#.5s|\n", str);
	ft_printf("lapin : |%#.5s|\n",  str);
	printf(   "malin : |%#.5s|\n\n",  str);

	ft_printf("lapin : |%#10s|\n", str);
	printf(   "malin : |%#10s|\n", str);
	ft_printf("lapin : |%#10s|\n",  str);
	printf(   "malin : |%#10s|\n\n",  str);

	ft_printf("lapin : |%#10.5s|\n", str);
	printf(   "malin : |%#10.5s|\n", str);
	ft_printf("lapin : |%#10.5s|\n",  str);
	printf(   "malin : |%#10.5s|\n\n",  str);

	return (0);
}
