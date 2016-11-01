/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_loop_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 21:26:49 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/22 19:45:15 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		loop_only(void *v_graf)
{
	t_graf	*graf;
	t_image	*image;
	t_push	*push;
	t_point	*c;

	graf = (t_graf *)v_graf;
	image = graf->mlx_i;
	push = graf->push;
	c = &graf->c;
	if (push->un == 1)
		graf->coef += 0.02;
	if (push->trois == 1)
		graf->coef -= 0.02;
	loop_in(push, c, graf);
	image->buffer = (char *)ft_memset(image->buffer, 0, \
image->widht * image->height * 4);
	ft_push_to_image(graf, graf->grid);
	mlx_put_image_to_window(graf->mlx_p, graf->mlx_w, graf->mlx_i, 0, 0);
	return (0);
}
