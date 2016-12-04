/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_on(int key, void *vgenv)
{
	t_genv		*genv;

	genv = (t_genv *)vgenv;
	if (key == ESC || key == Q)
		ft_error_fract(0, genv);
	if (key == L)
		genv->lock = genv->lock ? 0 : 1;
	if (key == LMAJ)
		genv->graf->color = genv->graf->color ? 0 : 1;
	if (key == T)
		genv->is_time = genv->is_time ? 0 : 1;
	genv->push[key] = 1;
	return (0);
}

int		key_off(int key, void *vgenv)
{
	t_genv		*genv;

	genv = (t_genv *)vgenv;
	genv->push[key] = 0;
	if (key == H)
	{
		print("%20s%5d\n%20s%5d\n\n","iteration :",genv->iter,"color amplitude :",(int)genv->graf->pad);
	}
	return (0);
}
