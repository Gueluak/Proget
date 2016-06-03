/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 22:30:34 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/08 17:23:41 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		ls_pars(char **av, t_opt *opt)
{
	int		i;

	i = 1;
	while(av[i])
	{
		ft_pars(opt, av[i]);
		i++;
	}
//	printf("l = %d\nR = %d\na = %d\nr = %d\nt = %d\npath = %s\n",opt->l,opt->R,opt->a,opt->r,opt->t,opt->path);
	return (1);
}

void	ft_init(t_opt *opt)
{
	opt->l = 0;
	opt->R = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->path = "./";
}
