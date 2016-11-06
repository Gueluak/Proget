/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:00:47 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/28 13:43:20 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		ft_rot(int x, int y, int z, t_graf graf)
{
	t_point			pt;
	t_point			tmp;
	unsigned int	a;
	float			coef;

	tmp.x = ((x) + (graf.x / 2));
	tmp.y = ((y) - (graf.y / 2));
	tmp.z = ((float)z) * graf.coef;
	tmp = translate(graf.c, tmp);
	pt.x = (tmp.x * graf.X.x) + (tmp.y * graf.Y.x) + (tmp.z * graf.Z.x);
	pt.y = (tmp.x * graf.X.y) + (tmp.y * graf.Y.y) + (tmp.z * graf.Z.y);
	pt.z = (tmp.x * graf.X.z) + (tmp.y * graf.Y.z) + (tmp.z * graf.Z.z);
	coef = ((pt.z != 0) ? (pt.z / graf.fov) : (2));
	pt.x = graf.zoom * pt.x / coef;
	pt.y = graf.zoom * pt.y / coef;
	a = (0xFF / ((float)ft_abs(pt.z) / graf.shadow));
	a > 0xFF ? a = 0xFF : 0;
	pt.c = ((int)a);
	pt.z -= 1;
	return (pt);
}

void		ft_error(int e)
{
	if (e == 1)
		write(1, "Invalid Map\n", 12);
	exit(0);
}
