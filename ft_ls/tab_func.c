/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:28:54 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/06 15:36:45 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ft_arg_l(t_opt *opt)
{
	opt->l = 1;
	return (2);
}

int		ft_arg_R(t_opt *opt)
{
	opt->R = 1;
	return (2);
}

int		ft_arg_a(t_opt *opt)
{
	opt->a = 1;
	return (2);
}

int		ft_arg_r(t_opt *opt)
{
	opt->r = 1;
	return (2);
}

int		ft_arg_t(t_opt *opt)
{
	opt->t = 1;
	return (2);
}
