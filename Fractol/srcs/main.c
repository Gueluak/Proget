/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/11/16 23:46:58 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_genv	genv;

	if (ac != 2)
		ft_error_fract(1, &genv);
	fractol_init(&genv, av[1]);
	genv.graf = fractol_init_graf(av[1]);
	mlx_hook(genv.graf->mlx_w, 6, 1, mouse, &genv);
	mlx_hook(genv.graf->mlx_w, 4, 1, mouse_m, &genv);
	mlx_hook(genv.graf->mlx_w, 2, 1, key_on, &genv);
	mlx_key_hook(genv.graf->mlx_w, key_off, &genv);
	mlx_loop_hook(genv.graf->mlx_p, main_loop, &genv);
	mlx_loop(genv.graf->mlx_p);
	return (0);
}

void	fractol_init(t_genv *genv, char *frac)
{
	genv->fractal = 0;
	ft_memcmp(frac, "julia", 6) == 0 ? genv->fractal = 1 : 0;
	ft_memcmp(frac, "mandel", 7) == 0 ? genv->fractal = 2 : 0;
	ft_memcmp(frac, "jubis", 6) == 0 ? genv->fractal = 3 : 0;
	ft_memcmp(frac, "burning", 8) == 0 ? genv->fractal = 4 : 0;
	genv->fractal == 0 ? ft_error_fract(1, genv) : 0;
	ft_memset(genv->push, 0, 270);
	genv->lock = 1;
	genv->iter = 20;
	genv->posx = 0;
	genv->posy = 0;
	genv->is_time = 0;
	return ;
}

t_graf	*fractol_init_graf(char *name)
{
	t_graf	*graf;

	if (!(graf = (t_graf *)ft_memalloc(sizeof(t_graf))))
		return (NULL);
	graf->mlx_p = mlx_init();
	graf->mlx_w = mlx_new_window(graf->mlx_p, W_W, W_H, name);
	graf->mlx_i = (t_image *)mlx_new_image(graf->mlx_p, W_W, W_H);
	graf->pad = 10;
	graf->start = 0;
	graf->color = 0;
	graf->zoom = 200;
	return (graf);
}

void	ft_error_fract(int code, t_genv *genv)
{
	if (code == 0)
		print("Fract'ol exit\n");
	if (code == 1)
	{
		print("Usage : ./fractol [fractal type]\nfractal type:\
			\n\t-\tjulia\n\t-\tmandel\n\t-\tjubis\n\t-\tburning\n");
		exit(0);
	}
	mlx_destroy_image(genv->graf->mlx_p, genv->graf->mlx_i);
	mlx_destroy_window(genv->graf->mlx_p, genv->graf->mlx_w);
	free(genv->graf);
	exit(0);
}
