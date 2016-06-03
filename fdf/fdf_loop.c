/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 23:55:14 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/28 14:05:22 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>

void	loop_in(t_push *push, t_point *c, t_graf *graf)
{
	if (push->a == 1)
	{
//		printf("%f , %f , %f\n",graf->Z.x, graf->Z.y, graf->Z.z);
		c->x += (graf->X.x / 4);
		c->y += (graf->Y.x / 4);
		c->z += (graf->Z.x / 4);
//		c->z -= 0.3;
	}
//		c->x += 0.3;
	if (push->d == 1)
	{
//		printf("%f , %f , %f\n",graf->Z.x, graf->Z.y, graf->Z.z);
		c->x -= (graf->X.x / 4);
		c->y -= (graf->Y.x / 4);
		c->z -= (graf->Z.x / 4);
//		c->z -= 0.3;
	}
//		c->x -= 0.3;
//	if (push->w == 1)
//s		c->y += 0.3;
//	if (push->s == 1)
//		c->y -= 0.3;
	if (push->w == 1)
	{
//	if (push->d == 1)
	//		printf("%f , %f , %f\n",graf->Z.x, graf->Z.y, graf->Z.z);
		c->x -= (graf->X.z / 4);
		c->y -= (graf->Y.z / 4);
		c->z -= (graf->Z.z / 4);
//		c->z -= 0.3;
	}
	if (push->s == 1)
	{
		c->x += (graf->X.z / 4);
		c->y += (graf->Y.z / 4);
		c->z += (graf->Z.z / 4);
//		c->z += 0.3;
	}
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
//	if (push->six == 1)
//		graf->rot_x += 0.03;
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
}

int		key_on(int k, void *v_graf)
{
	t_graf	*graf;
	t_push	*push;

	graf = (t_graf *)v_graf;
	push = graf->push;
	if (k == 83)
		push->un = 1;
	if (k == 85)
		push->trois = 1;
	if (k == 86)
		push->quatre = 1;
	if (k == 87)
		push->cinq = 1;
	if (k == 88)
		push->six = 1;
	if (k == 89)
		push->sept = 1;
	if (k == 91)
		push->huit = 1;
	if (k == 92)
		push->neuf = 1;
	key_on_2(k, push);
	return (0);
}

void	key_on_2(int k, t_push *push)
{
	if (k == 13)
		push->w = 1;
	if (k == 0)
		push->a = 1;
	if (k == 1)
		push->s = 1;
	if (k == 2)
		push->d = 1;
	if (k == 53)
		ft_error(0);
	if (k == 69)
		push->plus = 1;
	if (k == 78)
		push->moins = 1;
	if (k == 3)
		push->face = (push->face == 1 ? 0 : 1);
	if (k == 67)
		push->etoil = 1;
	if (k == 75)
		push->slash = 1;
//	writef("k = %d\n    ",k);
}

int		key_off(int k, void *v_graf)
{
	t_graf	*graf;
	t_push	*push;

	graf = (t_graf *)v_graf;
	push = graf->push;
	if (k == 83)
		push->un = 0;
	if (k == 85)
		push->trois = 0;
	if (k == 86)
		push->quatre = 0;
	if (k == 87)
		push->cinq = 0;
	if (k == 88)
		push->six = 0;
	if (k == 89)
		push->sept = 0;
	if (k == 91)
		push->huit = 0;
	if (k == 92)
		push->neuf = 0;
	key_off_2(k, push);
	return (0);
}

void	key_off_2(int k, t_push *push)
{
	if (k == 13)
		push->w = 0;
	if (k == 0)
		push->a = 0;
	if (k == 1)
		push->s = 0;
	if (k == 2)
		push->d = 0;
	if (k == 69)
		push->plus = 0;
	if (k == 78)
		push->moins = 0;
	if (k == 67)
		push->etoil = 0;
	if (k == 75)
		push->slash = 0;
}
