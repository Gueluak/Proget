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
//	t_point	X;
//	t_point	Y;
	t_point	Z;
	t_point	tmp;
	t_point	a;
	float	coef;

//	Y.x = 0;
//	Y.y = 1;
//	Y.z = 0;
//	X.x = 0;
//	X.y = 1;
//	X.z = 0;
//	Y = rot_mx(Y, graf);
//	X = rot_mx(X, graf);
//	Y = rot_y(Y, graf);
	o = graf.c;
//	tmp = graf.c;
//	o.x = (tmp.x * graf.X.x) + (tmp.y * graf.Y.x) + (tmp.z * graf.Z.x);
//	o.y = (tmp.x * graf.X.y) + (tmp.y * graf.Y.y) + (tmp.z * graf.Z.y);
//	o.z = (tmp.x * graf.X.z) + (tmp.y * graf.Y.z) + (tmp.z * graf.Z.z);
	tmp.x = ((x) + (graf.x / 2));
	tmp.y = ((y) - (graf.y / 2));
	tmp.z = ((float)z) * graf.coef;
	Z = graf.Z;
	tmp = translate(o, tmp);
//	o.x = (graf.c.x * graf.X.x) + (graf.c.y * graf.Y.x) + (graf.c.z * graf.Z.x);
//	o.y = (graf.c.x * graf.X.y) + (graf.c.y * graf.Y.y) + (graf.c.z * graf.Z.y);
//	o.z = (graf.c.x * graf.X.z) + (graf.c.y * graf.Y.z) + (graf.c.z * graf.Z.z);
	pt.x = (tmp.x * graf.X.x) + (tmp.y * graf.Y.x) + (tmp.z * graf.Z.x);
	pt.y = (tmp.x * graf.X.y) + (tmp.y * graf.Y.y) + (tmp.z * graf.Z.y);
	pt.z = (tmp.x * graf.X.z) + (tmp.y * graf.Y.z) + (tmp.z * graf.Z.z);
//	pt = translate(pt, o);
//	tmp = rot_mx(pt, graf);
//	tmp = pt;
//	o = rot_y(o, graf);
//	o = rot_x(o, graf);
//	pt.x = X.x * Y.x * pt.x;
//	pt.y = X.y * Y.y * pt.y;
//	pt.z = X.z * Y.z * pt.z;
//	pt = rot_x(pt, graf);
//	pt = amp(pt, Y, graf.rot_y);
//	pt = amp(pt, X, -graf.rot_x);
//	tmp = rot_x(tmp, graf);
//	pt.x += tmp.x;
//	pt.y += tmp.y;
//	pt.z += tmp.z;
//	X = amp(X, Y, graf.rot_y);
//	pt = amp(pt, X, graf.rot_x);
//	pt = rot_y(pt, graf);
//	Z.x = 1;
//	Z.y = 0;
//	Z.z = 0;
//	o = rot_mx(Z, graf);
//	o = rot_my(o, graf);
//	o = amp(o, tmp, -graf.rot_y);
	
//	pt = rot_z(pt, graf);
//	Y = rot_mx(Y, graf);
//	pt = amp(pt, Y, graf.rot_y);

	 
//	coef = ((pt.z != 0) ? (pt.z / 60) : (2));
//	pt.x = graf.zoom * pt.x / coef;
//	pt.y = graf.zoom * pt.y / coef;
//	coef.x = pt.x / Z.x;
//	coef.y = pt.y / Z.y;
//	coef.z = pt.z / Z.z;
//	coef.c = coef.x > coef.y ? coef.y > coef.z ? coef.z : coef.y : coef.x > coef.z ? coef.z : coef.x;
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
//	pt.c = (0xFF / ((float)ft_abs(pt.z) / 20.0));
//	pt.c = 0xFF;
	pt.z -= 1;
	return (pt);
}

void		ft_error(int e)
{
	if (e == 1)
		write(1, "Invalid Map\n", 12);
	exit(0);
}
