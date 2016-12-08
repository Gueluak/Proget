/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/12/08 03:40:29 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

# define BUFF 1

typedef struct	s_map
{
	int			x_grid;
	int			y_grid;
	int			**grid;
	int			x_pce;
	int			y_pce;
	int			**pce;
	int			player;
}				t_map;

void		pars_grid(t_map *map);