/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_genv	genv;

	if (ac != 2)
		ft_error_fract(1);
	fractol_init(&genv);
	genv.graf = fractol_init_graf(av[1]);

	/* fractal code */

	mlx_hook(genv.graf->mlx_w, 2, 1, key_on, &genv);
	mlx_key_hook(genv.graf->mlx_w, key_off, &genv);
	mlx_loop_hook(genv.graf->mlx_p, main_loop, &genv);
	mlx_loop(genv.graf->mlx_p);
	return (0);
}

void	fractol_init(t_genv *genv)
{
	if (genv != NULL)
		return;
	return;
}

t_graf	*fractol_init_graf(char *name)
{
	t_graf	*graf;

	if (!(graf = (t_graf *)ft_memalloc(sizeof(t_graf))))
		return (NULL);
	graf->mlx_p = mlx_init();
	graf->mlx_w = mlx_new_window(graf->mlx_p, W_W, W_H, name);
	graf->mlx_i = (t_image *)mlx_new_image(graf->mlx_p, W_W, W_H);
	return (graf);
}

void	ft_error_fract(int code)
{
	if (code == 1)
		print("Usage : ./fractol [fractal type]\n");
	exit(0);
}