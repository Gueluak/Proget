/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 14:59:34 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/06 16:30:26 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_pars(t_opt *opt, char *format)
{
	int		i;
	int		arg;
	int		(*tab_func[5])(t_opt *opt);

	i = 0;
	tab_func[0] = ft_arg_l;
	tab_func[1] = ft_arg_R;
	tab_func[2] = ft_arg_a;
	tab_func[3] = ft_arg_r;
	tab_func[4] = ft_arg_t;
	if (format[0] == '-')
	{
		while (format[++i])
		{
			if (-1 != (arg = ft_memnchr(format[i], "lRart", 5) - 1))
			{
				tab_func[arg](opt);
			}
			else
				return (0);
		}
	}
	else
		opt->path = format;
	return (1);
}

