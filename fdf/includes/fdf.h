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
	int			a:1;
	int			w:1;
	int			s:1;
	int			d:1;
	int			un:1;
	int			trois:1;
	int			quatre:1;
	int			cinq:1;
	int			six:1;
	int			sept:1;
	int			huit:1;
	int			neuf:1;
	int			moins:1;
	int			plus:1;
	int			face:1;
	int			slash:1;
	int			etoil:1;
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
	t_point		X;
	t_point		Y;
	t_point		Z;
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
void			init_fdf(t_graf *graf, t_push *push, t_point *c);
void			init_fdf_2(t_graf *graf, t_push *push, t_point *c);
void			loop_in(t_push *push, t_point *c, t_graf *graf);
void			key_on_2(int k, t_push *push);
void			key_off_2(int k, t_push *push);
void			ft_cross_to_image(t_image *image);
void			ft_push_to_image(t_graf *graf, short **grid, t_image *image);
void			ft_pixel_to_image(t_image *image, int x, int y, int color);
void			ft_line_to_image(t_image *image, t_point p1, t_point p2, int face);
void			ft_tri_to_image(t_image *image, t_point p1, t_point p2, t_point p3);
void			ft_error(int e);

#endif
