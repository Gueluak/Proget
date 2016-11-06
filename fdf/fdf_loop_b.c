/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 23:55:14 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/28 14:05:22 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	loop_in(t_push *push, t_point *c, t_graf *graf)
{
	if (push->a == 1)
	{
		c->x += (graf->X.x / 2);
		c->y += (graf->Y.x / 2);
		c->z += (graf->Z.x / 2);
	}
	if (push->d == 1)
	{
		c->x -= (graf->X.x / 2);
		c->y -= (graf->Y.x / 2);
		c->z -= (graf->Z.x / 2);
	}
	if (push->w == 1)
	{
		c->x -= (graf->X.z / 2);
		c->y -= (graf->Y.z / 2);
		c->z -= (graf->Z.z / 2);
	}
	if (push->s == 1)
	{
		c->x += (graf->X.z / 2);
		c->y += (graf->Y.z / 2);
		c->z += (graf->Z.z / 2);
	}
	loop_in_b(push, graf);
}

void	loop_in_b(t_push *push, t_graf *graf)
{
	if (push->cinq == 1)
	{
		graf->Y = rot_mx(graf->Y, 0.03);
		graf->Z = rot_mx(graf->Z, 0.03);
		graf->X = rot_mx(graf->X, 0.03);
	}
	if (push->neuf == 1)
		graf->rot_x -= 0.03;
	if (push->quatre == 1)
	{
		graf->X = rot_my(graf->X, 0.03);
		graf->Z = rot_my(graf->Z, 0.03);
		graf->Y = rot_my(graf->Y, 0.03);
	}
	if (push->huit == 1)
	{
		graf->Y = rot_mx(graf->Y, -0.03);
		graf->Z = rot_mx(graf->Z, -0.03);
		graf->X = rot_mx(graf->X, -0.03);
	}
	loop_in_c(push, graf);
}

void	loop_in_c(t_push *push, t_graf *graf)
{
	if (push->six == 1)
	{
		graf->X = rot_my(graf->X, -0.03);
		graf->Z = rot_my(graf->Z, -0.03);
		graf->Y = rot_my(graf->Y, -0.03);
	}
	graf->face = push->face;
	if (push->etoil == 1)
		graf->shadow *= 1.1;
	if (push->slash == 1)
		graf->shadow /= 1.1;
	graf->X = rot_mz(graf->X, -graf->Z.x / 20);
	graf->Y = rot_mz(graf->Y, -graf->Z.x / 20);
	graf->Z = rot_mz(graf->Z, -graf->Z.x / 20);
}
