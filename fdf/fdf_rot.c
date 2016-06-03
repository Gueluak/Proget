/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:06:05 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:06:37 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>

t_point		rot_x(t_point p, t_graf graf)
{
	t_point t;

	t.x = p.x;
	t.y = (p.z * -sin(graf.rot_x)) + (p.y * cos(graf.rot_x));
	t.z = (p.y * sin(graf.rot_x)) + (p.z * cos(graf.rot_x));
	return (t);
}

t_point		rot_mx(t_point p, float rot)
{
	t_point t;

	t.x = p.x;
	t.y = (p.z * -sin(rot)) + (p.y * cos(rot));
	t.z = (p.y * sin(rot)) + (p.z * cos(rot));
	return (t);
}

t_point		rot_y(t_point p, t_graf graf)
{
	t_point t;

	t.x = (p.x * cos(graf.rot_y)) + (p.z * sin(graf.rot_y));
	t.y = p.y;
	t.z = (p.z * cos(graf.rot_y)) + (p.x * -sin(graf.rot_y));
	return (t);
}

t_point		rot_my(t_point p, float rot)
{
	t_point t;

	t.x = (p.x * cos(rot)) + (p.z * sin(rot));
	t.y = p.y;
	t.z = (p.z * cos(rot)) + (p.x * -sin(rot));
	return (t);
}

t_point		rot_z(t_point p, t_graf graf)
{
	t_point t;

	t.x = (p.x * cos(graf.rot_z)) + (p.y * -sin(graf.rot_z));
	t.y = (p.x * sin(graf.rot_z)) + (p.y * cos(graf.rot_z));
	t.z = p.z;
	return (t);
}

t_point		rot_mz(t_point p, float rot)
{
	t_point t;

	t.x = (p.x * cos(rot)) + (p.y * -sin(rot));
	t.y = (p.x * sin(rot)) + (p.y * cos(rot));
	t.z = p.z;
	return (t);
}

t_point		amp(t_point p, t_point t, float rot)
{
	t_point	tm;

	tm.x = (p.x * ((t.x * t.x * (1 - cos(rot))) + (001 * cos(rot)))) + (p.y * ((t.x * t.y * (1 - cos(rot))) - (t.z * sin(rot)))) + (p.z * ((t.x * t.z * (1 - cos(rot))) + (t.y * sin(rot))));
	tm.y = (p.x * ((t.y * t.x * (1 - cos(rot))) + (t.z * sin(rot)))) + (p.y * ((t.y * t.y * (1 - cos(rot))) + (001 * cos(rot)))) + (p.z * ((t.y * t.z * (1 - cos(rot))) - (t.x * sin(rot))));
	tm.z = (p.x * ((t.z * t.x * (1 - cos(rot))) - (t.y * sin(rot)))) + (p.y * ((t.z * t.y * (1 - cos(rot))) + (t.x * sin(rot)))) + (p.z * ((t.z * t.z * (1 - cos(rot))) + (001 * cos(rot))));
	return (tm);
}

t_point		translate(t_point p, t_point t)
{
	p.x += t.x;
	p.y += t.y;
	p.z += t.z;
	return (p);
}
