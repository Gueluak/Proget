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
# include "libft.h"
# include "printf.h"

typedef struct	s_opt
{
	int				l:1;
	int				R:1;
	int				a:1;
	int				r:1;
	int				t:1;
	char		*path;
}				t_opt;

typedef struct	s_l
{
	
}				t_l;

typedef struct	s_lst
{
	char			*name;
	t_l				*data;
	struct s_lst	*next;
	struct s_lst	*prev;
}				t_lst;

#endif
