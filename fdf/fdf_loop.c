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

#include "fdf.h"

int		key_on(int k, void *v_graf)
{
	t_graf	*graf;
	t_push	*push;

	graf = (t_graf *)v_graf;
	push = graf->push;
	if (k == 83)
		push->un = 1;
	else if (k == 85)
		push->trois = 1;
	else if (k == 86)
		push->quatre = 1;
	else if (k == 87)
		push->cinq = 1;
	else if (k == 88)
		push->six = 1;
	else if (k == 89)
		push->sept = 1;
	else if (k == 91)
		push->huit = 1;
	else if (k == 92)
		push->neuf = 1;
	key_on_2(k, push);
	return (0);
}

void	key_on_2(int k, t_push *push)
{
	if (k == 13)
		push->w = 1;
	else if (k == 0)
		push->a = 1;
	else if (k == 1)
		push->s = 1;
	else if (k == 2)
		push->d = 1;
	else if (k == 53)
		ft_error(0);
	else if (k == 69)
		push->plus = 1;
	else if (k == 78)
		push->moins = 1;
	else if (k == 3)
		push->face = (push->face == 1 ? 0 : 1);
	else if (k == 67)
		push->etoil = 1;
	else if (k == 75)
		push->slash = 1;
}

int		key_off(int k, void *v_graf)
{
	t_graf	*graf;
	t_push	*push;

	graf = (t_graf *)v_graf;
	push = graf->push;
	if (k == 83)
		push->un = 0;
	else if (k == 85)
		push->trois = 0;
	else if (k == 86)
		push->quatre = 0;
	else if (k == 87)
		push->cinq = 0;
	else if (k == 88)
		push->six = 0;
	else if (k == 89)
		push->sept = 0;
	else if (k == 91)
		push->huit = 0;
	else if (k == 92)
		push->neuf = 0;
	key_off_2(k, push);
	return (0);
}

void	key_off_2(int k, t_push *push)
{
	if (k == 13)
		push->w = 0;
	else if (k == 0)
		push->a = 0;
	else if (k == 1)
		push->s = 0;
	else if (k == 2)
		push->d = 0;
	else if (k == 69)
		push->plus = 0;
	else if (k == 78)
		push->moins = 0;
	else if (k == 67)
		push->etoil = 0;
	else if (k == 75)
		push->slash = 0;
}
