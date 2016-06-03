/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 15:00:08 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/08 19:50:40 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

typedef struct	s_opt
{
	short		l;
	short		R;
	short		a;
	short		r;
	short		t;
	char		*path;
}				t_opt;

typedef struct	s_lst
{
	char			*path_name;
	char			*name;
	time_t			time;
	struct s_lst	*top;
	struct s_lst	*prev;
	struct s_lst	*next;
}				t_lst;

void	ft_init(t_opt *opt);
int		ls_pars(char **av, t_opt *opt);
int		ft_pars(t_opt *opt, char *format);
int		ft_arg_l(t_opt *opt);
int		ft_arg_R(t_opt *opt);
int		ft_arg_a(t_opt *opt);
int		ft_arg_r(t_opt *opt);
int		ft_arg_t(t_opt *opt);
int		lst_new(t_lst **lst);
int		lst_del(t_lst **lst);
int		lst_name_short(t_lst **lst, int size);

#endif
