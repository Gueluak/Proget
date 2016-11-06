/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "libft.h"
# include "printf.h"
# include <pthread.h>
# include <time.h>
# include <fcntl.h>
# include <math.h>

# define W_W 1200
# define W_H 900

typedef struct	s_image
{
	int				widht;
	int				height;
	char			*buffer;
	float			vertexes[8];
	struct s_image	*next;
}				t_image;

typedef	struct		s_graf
{
	void			*mlx_p;
	void			*mlx_w;
	t_image			*mlx_i;
}					t_graf;

typedef struct		s_push
{

}					t_push;

typedef struct		s_genv
{
	t_graf			*graf;
	t_push			*push;
}					t_genv;

/* 
 --- main.c
*/

void		fractol_init(t_genv *genv);
t_graf		*fractol_init_graf(char *name);
void		ft_error_fract(int code);

/*
 --- fractol_loop.c
*/

int			main_loop(void *vgenv);

/*
 --- key.c
*/

int			key_on(int key, void *vgenv);
int			key_off(int key, void *vgenv);

#endif