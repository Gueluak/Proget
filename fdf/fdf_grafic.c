/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_grafic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:07:23 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/28 16:12:01 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			*thr_uno(void *v_thr)
{
	t_thr	*thr;
	t_graf	*graf;
	int		x;
	int		y;
	short	**grid;

	thr = (t_thr *)v_thr;
	graf = thr->graf;
	x = graf->x;
	y = thr->y;
	grid = graf->grid;
	while (x >= 0)
	{
		if (y != 0)
			ft_line_to_image(graf->mlx_i, \
			ft_rot(-x, y, grid[y][x], *graf), \
			ft_rot(-x, y - 1, grid[y - 1][x], *graf));
		if (x != 0)
			ft_line_to_image(graf->mlx_i, \
			ft_rot(-x, y, grid[y][x], *graf), \
			ft_rot(-(x - 1), y, grid[y][x - 1], *graf));
		--x;
	}
	pthread_exit(NULL);
}

void			ft_push_to_image(t_graf *graf, short **grid)
{
	pthread_t	thruno[8];
	int			i;
	t_thr		thr[8];

	grid = graf->grid;
	graf->by = graf->y - 1;
	i = ft_push_to_image_in(graf, thruno, thr) + 1;
	while (i > 0)
	{
		--i;
		pthread_join(thruno[i], NULL);
	}
	graf->by = graf->y - 1;
}

inline int		ft_push_to_image_in(t_graf *graf, pthread_t thruno[8]\
	, t_thr thr[8])
{
	int			i;

	i = 0;
	while (graf->by >= 0)
		if (i < 8)
		{
			thr[i].graf = graf;
			thr[i].y = graf->by;
			pthread_create(&(thruno[i]), NULL, thr_uno, &thr[i]);
			graf->by--;
			i++;
		}
		else
			while (i > 0)
			{
				--i;
				pthread_join(thruno[i], NULL);
			}
	return (i);
}

void			ft_pixel_to_image(t_image *image, int x, int y, int color)
{
	if (x < 599 && x > -600 && y < 449 && y > -450)
	{
		if (*((int *)(image->buffer + (4 * (x + 600)) + \
			(image->widht * 4 * (y + 450)))) < color)
			*((int *)(image->buffer + (4 * (x + 600)) + \
			(image->widht * 4 * (y + 450)))) = color;
	}
}

void			ft_line_to_image(t_image *image, t_point p1, t_point p2)
{
	t_point	tmp;
	t_point	ini;
	float	pas;

	if (((p1.x > 600 || p1.x < -600 || p1.y > 450 || p1.y < -450) && \
		(p2.x > 600 || p2.x < -600 || p2.y > 450 || p2.y < -450)) || \
		(p1.z < 0 || p2.z < 0))
		return ;
	ini.x = p1.x - p2.x;
	ini.y = p1.y - p2.y;
	ini.z = ft_abs(ini.x) > ft_abs(ini.y) ? ft_abs(ini.x) : ft_abs(ini.y);
	pas = -1.0;
	tmp.z = (float)(p1.c % 256) - (float)(p2.c % 256);
	tmp.x = (float)ini.x / (float)ini.z;
	tmp.y = (float)ini.y / (float)ini.z;
	tmp.z = (float)tmp.z / (float)ini.z;
	while (++pas <= ini.z)
		if (p2.z > 0 && p1.z)
		{
			ft_pixel_to_image(image, p2.x + (int)(pas * tmp.x), p2.y + \
			(int)(pas * tmp.y)\
			, p2.c + ((int)((float)pas * tmp.z)));
		}
}
