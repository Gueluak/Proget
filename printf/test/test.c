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
#include <locale.h>

int			main(int ac, char **av)
{
	setlocale(LC_CTYPE, "");
	wchar_t *str = L"lapén123";
	printf("'null'\n");
	ft_printf("lapin : |%S|\n", str);
	printf(   "malin : |%S|\n", str);
	ft_printf("lapin : |%S|\n",  str);
	printf(   "malin : |%S|\n\n",  str);

	ft_printf("lapin : |%.5S|\n", str);
	printf(   "malin : |%.5S|\n", str);
	ft_printf("lapin : |%.5S|\n",  str);
	printf(   "malin : |%.5S|\n\n",  str);

	ft_printf("lapin : |%10S|\n", str);
	printf(   "malin : |%10S|\n", str);
	ft_printf("lapin : |%10S|\n",  str);
	printf(   "malin : |%10S|\n\n",  str);

	ft_printf("lapin : |%10.5S|\n", str);
	printf(   "malin : |%10.5S|\n", str);
	ft_printf("lapin : |%10.5S|\n",  str);
	printf(   "malin : |%10.5S|\n\n",  str);

	printf("'-'\n")	;
	ft_printf("lapin : |%-S|\n", str);
	printf(   "malin : |%-S|\n", str);
	ft_printf("lapin : |%-S|\n",  str);
	printf(   "malin : |%-S|\n\n",  str);

	ft_printf("lapin : |%-.5S|\n", str);
	printf(   "malin : |%-.5S|\n", str);
	ft_printf("lapin : |%-.5S|\n",  str);
	printf(   "malin : |%-.5S|\n\n",  str);

	ft_printf("lapin : |%-10S|\n", str);
	printf(   "malin : |%-10S|\n", str);
	ft_printf("lapin : |%-10S|\n",  str);
	printf(   "malin : |%-10S|\n\n",  str);

	ft_printf("lapin : |%-10.5S|\n", str);
	printf(   "malin : |%-10.5S|\n", str);
	ft_printf("lapin : |%-10.5S|\n",  str);
	printf(   "malin : |%-10.5S|\n\n",  str);

	printf("'+'\n")	;
	ft_printf("lapin : |%+S|\n", str);
	printf(   "malin : |%+S|\n", str);
	ft_printf("lapin : |%+S|\n",  str);
	printf(   "malin : |%+S|\n\n",  str);

	ft_printf("lapin : |%+.5S|\n", str);
	printf(   "malin : |%+.5S|\n", str);
	ft_printf("lapin : |%+.5S|\n",  str);
	printf(   "malin : |%+.5S|\n\n",  str);

	ft_printf("lapin : |%+10S|\n", str);
	printf(   "malin : |%+10S|\n", str);
	ft_printf("lapin : |%+10S|\n",  str);
	printf(   "malin : |%+10S|\n\n",  str);

	ft_printf("lapin : |%+10.5S|\n", str);
	printf(   "malin : |%+10.5S|\n", str);
	ft_printf("lapin : |%+10.5S|\n",  str);
	printf(   "malin : |%+10.5S|\n\n",  str);

	printf("' '\n")	;
	ft_printf("lapin : |% S|\n", str);
	printf(   "malin : |% S|\n", str);
	ft_printf("lapin : |% S|\n",  str);
	printf(   "malin : |% S|\n\n",  str);

	ft_printf("lapin : |% .5S|\n", str);
	printf(   "malin : |% .5S|\n", str);
	ft_printf("lapin : |% .5S|\n",  str);
	printf(   "malin : |% .5S|\n\n",  str);

	ft_printf("lapin : |% 10S|\n", str);
	printf(   "malin : |% 10S|\n", str);
	ft_printf("lapin : |% 10S|\n",  str);
	printf(   "malin : |% 10S|\n\n",  str);

	ft_printf("lapin : |% 10.5S|\n", str);
	printf(   "malin : |% 10.5S|\n", str);
	ft_printf("lapin : |% 10.5S|\n",  str);
	printf(   "malin : |% 10.5S|\n\n",  str);

	printf("'0'\n")	;
	ft_printf("lapin : |%0S|\n", str);
	printf(   "malin : |%0S|\n", str);
	ft_printf("lapin : |%0S|\n",  str);
	printf(   "malin : |%0S|\n\n",  str);

	ft_printf("lapin : |%0.5S|\n", str);
	printf(   "malin : |%0.5S|\n", str);
	ft_printf("lapin : |%0.5S|\n",  str);
	printf(   "malin : |%0.5S|\n\n",  str);

	ft_printf("lapin : |%010S|\n", str);
	printf(   "malin : |%010S|\n", str);
	ft_printf("lapin : |%010S|\n",  str);
	printf(   "malin : |%010S|\n\n",  str);

	ft_printf("lapin : |%010.5S|\n", str);
	printf(   "malin : |%010.5S|\n", str);
	ft_printf("lapin : |%010.5S|\n",  str);
	printf(   "malin : |%010.5S|\n\n",  str);

	printf("'#'\n")	;
	ft_printf("lapin : |%#S|\n", str);
	printf(   "malin : |%#S|\n", str);
	ft_printf("lapin : |%#S|\n",  str);
	printf(   "malin : |%#S|\n\n",  str);

	ft_printf("lapin : |%#.5S|\n", str);
	printf(   "malin : |%#.5S|\n", str);
	ft_printf("lapin : |%#.5S|\n",  str);
	printf(   "malin : |%#.5S|\n\n",  str);

	ft_printf("lapin : |%#10S|\n", str);
	printf(   "malin : |%#10S|\n", str);
	ft_printf("lapin : |%#10S|\n",  str);
	printf(   "malin : |%#10S|\n\n",  str);

	ft_printf("lapin : |%#10.5S|\n", str);
	printf(   "malin : |%#10.5S|\n", str);
	ft_printf("lapin : |%#10.5S|\n",  str);
	printf(   "malin : |%#10.5S|\n\n",  str);

	return (0);
}
