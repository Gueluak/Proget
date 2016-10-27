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

#include "fdf.h"

t_point		rot_mx(t_point p, float rot)
{
	t_point t;

	t.x = p.x;
	t.y = (p.z * -sin(rot)) + (p.y * cos(rot));
	t.z = (p.y * sin(rot)) + (p.z * cos(rot));
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

t_point		translate(t_point p, t_point t)
{
	p.x += t.x;
	p.y += t.y;
	p.z += t.z;
	return (p);
}
