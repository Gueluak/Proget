/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "printf.h"
# include <pthread.h>
# include <time.h>
# include <fcntl.h>
# include <math.h>

# define Z lz
# define Y ly
# define X lx

typedef struct	s_point
{
	float		x;
	float		y;
	float		z;
	int			c;
}				t_point;

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_push
{
	unsigned int			a:1;
	unsigned int			w:1;
	unsigned int			s:1;
	unsigned int			d:1;
	unsigned int			un:1;
	unsigned int			trois:1;
	unsigned int			quatre:1;
	unsigned int			cinq:1;
	unsigned int			six:1;
	unsigned int			sept:1;
	unsigned int			huit:1;
	unsigned int			neuf:1;
	unsigned int			moins:1;
	unsigned int			plus:1;
	unsigned int			face:1;
	unsigned int			slash:1;
	unsigned int			etoil:1;
}				t_push;

typedef struct	s_image
{
	int				widht;
	int				height;
	char			*buffer;
	float			vertexes[8];
	struct s_image	*next;
}				t_image;

typedef struct	s_graf
{
	t_point		c;
	t_point		lx;
	t_point		ly;
	t_point		lz;
	int			l;
	int			h;
	int			a;
	float		rot_x;
	float		rot_y;
	float		rot_z;
	float		zoom;
	float		coef;
	float		shadow;
	int			x;
	int			y;
	int			by;
	void		*mlx_p;
	void		*mlx_w;
	t_image		*mlx_i;
	t_push		*push;
	short		**grid;
	int			face;
	int			fov;
}				t_graf;

typedef struct	s_thr
{
	t_graf		*graf;
	int			y;
}				t_thr;

int				key_on(int k, void *v_graf);
int				key_off(int k, void *v_graf);
int				loop_only(void *v_graf);
short			**ft_read_doc(char *file, t_graf *graf);
short			**ft_grid_y(short ***grid, int y, int x);
short			*ft_grid_x(short **grid, int x);
t_point			ft_rot(int x, int y, int z, t_graf graf);
t_point			rot_x(t_point p, t_graf graf);
t_point			rot_mx(t_point p, float rot);
t_point			rot_y(t_point p, t_graf graf);
t_point			rot_my(t_point p, float rot);
t_point			rot_z(t_point p, t_graf graf);
t_point			rot_mz(t_point p, float rot);
t_point			amp(t_point p, t_point t, float rot);
t_point			translate(t_point p, t_point t);
void			if_1(int *t, short ***grid, t_graf *graf);
void			if_2(int *t, short ***grid, char *buff, t_graf *graf);
void			init_fdf(t_graf *graf, t_push *push, t_point *c, int fov);
void			init_fdf_2(t_push *push);
void			loop_in(t_push *push, t_point *c, t_graf *graf);
void			loop_in_b(t_push *push, t_graf *graf);
void			loop_in_c(t_push *push, t_graf *graf);
void			key_on_2(int k, t_push *push);
void			key_off_2(int k, t_push *push);
void			ft_push_to_image(t_graf *graf, short **grid);
void			ft_pixel_to_image(t_image *image, int x, int y, int color);
void			ft_line_to_image\
					(t_image *image, t_point p1, t_point p2);
void			ft_error(int e);
int				ft_push_to_image_in(t_graf *graf, pthread_t thruno[8]\
	, t_thr thr[8]);

#endif
