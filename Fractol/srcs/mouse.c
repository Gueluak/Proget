/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse(int x, int y, t_genv *genv)
{
	genv->mx = genv->lock ? genv->mx : (x - W_W / 2);
	genv->my = genv->lock ? genv->my : (y - W_H / 2);
	return (0);
}

int			mouse_m(int button, int x, int y, t_genv *genv)
{
	if (button == 5)
	{
		genv->graf->zoom *= 1.04;
		genv->posx += (x - W_W / 2) / (10 * genv->graf->zoom);
		genv->posy += (y - W_H / 2) / (10 * genv->graf->zoom);
	}
	if (button == 4)
	{
		genv->graf->zoom /= 1.04;
		genv->posx += (x - W_W / 2) / (10 * genv->graf->zoom);
		genv->posy += (y - W_H / 2) / (10 * genv->graf->zoom);
	}
	return (0);
}
