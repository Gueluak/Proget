/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 23:08:49 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 21:35:37 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_graf	graf;
	t_push	push;
	t_point	*c;

	if (ac < 2)
		ft_error(1);
	graf.push = &push;
	c = &graf.c;
	init_fdf(&graf, &push, c);
	graf.mlx_p = mlx_init();
	graf.mlx_i = (t_image *)mlx_new_image(graf.mlx_p, 1200, 900);
	graf.grid = ft_read_doc(av[1], &graf);
	ft_push_to_image(&graf, graf.grid);
	graf.mlx_w = mlx_new_window(graf.mlx_p, 1200, 900, av[1]);
	mlx_put_image_to_window(graf.mlx_p, graf.mlx_w, graf.mlx_i, 0, 0);
	mlx_hook(graf.mlx_w, 2, 1, key_on, &graf);
	mlx_key_hook(graf.mlx_w, key_off, &graf);
	mlx_loop_hook(graf.mlx_p, loop_only, &graf);
	mlx_loop(graf.mlx_p);
	return (0);
}

void	init_fdf(t_graf *graf, t_push *push, t_point *c)
{
	graf->l = 0;
	graf->h = 0;
	graf->a = 0;
	graf->X.x = 1;
	graf->X.y = 0;
	graf->X.z = 0;
	graf->Y.x = 0;
	graf->Y.y = 1;
	graf->Y.z = 0;
	graf->Z.x = 0;
	graf->Z.y = 0;
	graf->Z.z = 1;
	graf->coef = 0.5;
	graf->rot_x = 0;
	graf->rot_y = 0;
	graf->rot_z = 0;
	graf->zoom = 10;
	graf->face = 0;
	graf->shadow = 30;
	c->x = 1.2;
	c->y = 2.5;
	c->z = 5.1;
	init_fdf_2(push);
}

void	init_fdf_2(t_push *push)
{
	push->un = 0;
	push->trois = 0;
	push->quatre = 0;
	push->cinq = 0;
	push->six = 0;
	push->sept = 0;
	push->huit = 0;
	push->neuf = 0;
	push->a = 0;
	push->s = 0;
	push->d = 0;
	push->w = 0;
	push->moins = 0;
	push->plus = 0;
	push->slash = 0;
	push->etoil = 0;
}
