/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandel(t_genv *genv)
{
	t_fract	f;
	int		i;
	int		x;
	int		y;

	i = 0;
	x = -1;
	while (++x < W_W)
	{
		y = -1;
		while (++y < W_H)
		{
			man_init(&f, genv, x, y);
			i = 0;
			while (i++ < genv->iter && f.z_r * f.z_r + f.z_i * f.z_i < 4)
			{
				f.tmp = f.z_r;
				f.z_r = f.z_r * f.z_r - f.z_i * f.z_i + f.c_r;
				f.z_i = 2 * f.tmp * f.z_i + f.c_i;
			}
			put_pixel_to_img(genv->graf, (i < genv->iter ? get_color(i *
				genv->graf->pad + genv->graf->start) : 0), x, y);
		}
	}
}

void		man_init(t_fract *f, t_genv *genv, int x, int y)
{
	f->c_r = (x - W_W / 2) / genv->graf->zoom + genv->posx;
	f->c_i = (y - W_H / 2) / genv->graf->zoom + genv->posy;
	f->z_r = genv->is_time ? sin(genv->time / 3.0) : 0;
	f->z_i = genv->is_time ? cos(genv->time) : 0;
}
