/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/11/16 23:43:31 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			main_loop(void *vgenv)
{
	t_genv		*genv;

	genv = (t_genv *)vgenv;
	genv->time = (double)clock() / 5000000.0;
	check_button(genv);
	genv->fractal == 2 ? mandel(genv) : 0;
	genv->fractal == 1 ? julia(genv) : 0;
	genv->fractal == 3 ? jubis(genv) : 0;
	genv->fractal == 4 ? burning(genv) : 0;
	genv->graf->color ? (genv->graf->start += 15) : 0;
	mlx_put_image_to_window(genv->graf->mlx_p, genv->graf->mlx_w,
	genv->graf->mlx_i, 0, 0);
	return (0);
}

void		check_button(t_genv *genv)
{
	genv->push[ADD] ? (genv->graf->zoom *= 1.04) : 0;
	genv->push[SUB] ? (genv->graf->zoom /= 1.04) : 0;
	genv->push[I] ? (genv->iter++) : 0;
	genv->push[U] ? (genv->iter--) : 0;
	genv->push[UP] ? (genv->posy -= 20 / genv->graf->zoom) : 0;
	genv->push[DN] ? (genv->posy += 20 / genv->graf->zoom) : 0;
	genv->push[LT] ? (genv->posx -= 20 / genv->graf->zoom) : 0;
	genv->push[RT] ? (genv->posx += 20 / genv->graf->zoom) : 0;
	genv->push[C] ? (genv->graf->pad *= 1.04) : 0;
	genv->push[V] ? (genv->graf->pad /= 1.04) : 0;
	genv->push[X] ? (genv->graf->start += 20) : 0;
	genv->push[Z] ? (genv->graf->start -= 20) : 0;
}
