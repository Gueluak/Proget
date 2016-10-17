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

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>

t_point		ft_rot(int x, int y, int z, t_graf graf)
{
	t_point	pt;
	t_point	o;
	t_point	Z;
	t_point	tmp;
	t_point	a;
	float	coef;

	o = graf.c;
	tmp.x = ((x) + (graf.x / 2));
	tmp.y = ((y) - (graf.y / 2));
	tmp.z = ((float)z) * graf.coef;
	Z = graf.Z;
	tmp = translate(o, tmp);
	pt.x = (tmp.x * graf.X.x) + (tmp.y * graf.Y.x) + (tmp.z * graf.Z.x);
	pt.y = (tmp.x * graf.X.y) + (tmp.y * graf.Y.y) + (tmp.z * graf.Z.y);
	pt.z = (tmp.x * graf.X.z) + (tmp.y * graf.Y.z) + (tmp.z * graf.Z.z);
	coef = ((pt.z != 0) ? (pt.z / 60) : (2));
	pt.x = graf.zoom * pt.x / coef;
	pt.y = graf.zoom * pt.y / coef;
	a.x = (20 * z) / ((float)ft_abs(pt.z) / 20.0);
	a.y = (0xFF / ((float)ft_abs(pt.z) / graf.shadow));
	if (a.y > 0xFF)
		a.y = 0xFF;
	if (a.y < 0)
		a.y = 0;
	if (a.x > 0xFF)
		a.x = 0xFF;
	if (a.x < 0)
		a.x = 0;
	pt.c =((int)a.y);
	pt.z -= 1;
	return (pt);
}

void		ft_error(int e)
{
	if (e == 1)
		write(1, "Invalid Map\n", 12);
	exit(0);
}
