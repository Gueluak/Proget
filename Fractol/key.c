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
	key = 1;
	return (0);
}


int		key_off(int key, void *vgenv)
{
	t_genv		*genv;

	genv = (t_genv *)vgenv;
	key = 1;
	return (0);
}