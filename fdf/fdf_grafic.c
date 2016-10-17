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

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <math.h>

void	ft_cross_to_image(t_image *image)
{
	ft_pixel_to_image(image, -1, 0, 0x00FFFFFF);
	ft_pixel_to_image(image, -2, 0, 0x00FFFFFF);
	ft_pixel_to_image(image, 1, 0, 0x00FFFFFF);
	ft_pixel_to_image(image, 2, 0, 0x00FFFFFF);
	ft_pixel_to_image(image, 0, -1, 0x00FFFFFF);
	ft_pixel_to_image(image, 0, -2, 0x00FFFFFF);
	ft_pixel_to_image(image, 0, 1, 0x00FFFFFF);
	ft_pixel_to_image(image, 0, 2, 0x00FFFFFF);
}

void	*thr_uno(void *v_thr)
{
	t_thr	*thr;
	t_graf	*graf;
	int		x;
	int		y;
	short	**grid;
	t_image	*image;

	thr = (t_thr *)v_thr;
	graf = thr->graf;
	x = graf->x;
	y = thr->y;
	grid = graf->grid;
	image = graf->mlx_i;
	while (x >= 0)
	{
		if (graf->face == 1)
		{
			if (x != 0 && y != 0)
				ft_tri_to_image(image, ft_rot(-x, (y - 1), grid[y - 1][x], *graf), \
								ft_rot(-(x - 1), y, grid[y][x - 1], *graf),	\
								ft_rot(-(x - 1), (y - 1), grid[y - 1][x - 1], *graf));
			if (x != 0 && y != 0)
				ft_tri_to_image(image, ft_rot(-x, (y - 1), grid[y - 1][x], *graf), \
								ft_rot(-(x - 1), y, grid[y][x - 1], *graf),	\
								ft_rot(-(x), (y), grid[y][x], *graf));
		}
		else
		{
			if (y != 0)
				ft_line_to_image(image, ft_rot(-x, y, grid[y][x], *graf), \
								 ft_rot(-x, y - 1, grid[y - 1][x], *graf) , 0);
			if (x != 0)
				ft_line_to_image(image, ft_rot(-x, y, grid[y][x], *graf), \
								 ft_rot(-(x - 1), y, grid[y][x-1], *graf),0);
		}
		--x;
	}
	pthread_exit(NULL);
}

void	ft_push_to_image(t_graf *graf, short **grid, t_image *image)
{
	pthread_t	thruno[16];
	t_thr		thr[16];
	int			i;

	grid = graf->grid;
	graf->by = graf->y - 1;
	i = 0;
	while (graf->by >= 0)
	{
		if (i < 16)
		{
			thr[i].graf = graf;
			thr[i].y = graf->by;
			pthread_create(&(thruno[i]), NULL, thr_uno, &thr[i]);
			graf->by--;
			i++;
		}
		else
			while (i-- > 0)
				pthread_join(thruno[i], NULL);
	}
	i++;
	while (i-- > 0)
		pthread_join(thruno[i], NULL);
	graf->by = graf->y - 1;
	ft_cross_to_image(image);
}

void	ft_pixel_to_image(t_image *image, int x, int y, int color)
{
	if (x < 599 && x > -600 && y < 449 && y > -450)
	{
		if (*((int *)(image->buffer + (4 * (x + 600)) +	\
									 (image->widht * 4 * (y + 450)))) < color)
			*((int *)(image->buffer + (4 * (x + 600)) +	\
									 (image->widht * 4 * (y + 450)))) = color;
	}
}

void	ft_prtri_to_image(t_image *image, t_point p1, t_point p2, t_point p3)
{
	t_point ink;

	if (((p1.x > 600 || p1.x < -600 || p1.y > 450 || p1.y < -450) &&	\
	(p3.x > 600 || p3.x < -600 || p3.y > 450 || p3.y < -450) &&	\
	(p2.x > 600 || p2.x < -600 || p2.y > 450 || p2.y < -450) &&	\
	(p3.x > 600 || p3.x < -600 || p3.y > 450 || p3.y < -450)) ||	\
	(p1.z < 0 || p2.z < 0 || p3.z < 0))
		return;
	if (p1.x >= p2.x && p1.x <= p3.x)
	{
		ink.x = p3.x + (p1.y - p3.y) / (p2.y - p3.y) * (p2.x - p3.x);
		ink.y = 
		ink.c = ;
	}
	else if (p3.x >= p2.x && p3.x <= p1.x)
	{

	}
	else if (p2.x >= p1.x && p2.x <= p3.x)
	{

	}
}

void	ft_tri_to_image(t_image *image, t_point p1, t_point p2, t_point p3)
{
	t_point	uno;
	t_point	c;
	t_point	dos;
	float	k;
	float	pas;

	if (((p1.x > 600 || p1.x < -600 || p1.y > 450 || p1.y < -450) &&	\
		(p3.x > 600 || p3.x < -600 || p3.y > 450 || p3.y < -450) &&	\
		(p2.x > 600 || p2.x < -600 || p2.y > 450 || p2.y < -450) &&	\
		(p3.x > 600 || p3.x < -600 || p3.y > 450 || p3.y < -450)) ||	\
		(p1.z < 0 || p2.z < 0 || p3.z < 0))
		return;
	uno.x = p1.x - p3.x;
	uno.y = p1.y - p3.y;
	dos.x = p2.x - p3.x;
	dos.y = p2.y - p3.y;
	k = ft_abs(uno.x) > ft_abs(uno.y) ? ft_abs(uno.x) : ft_abs(uno.y);
	if(k < (ft_abs(dos.x) > ft_abs(dos.y) ? ft_abs(dos.x) : ft_abs(dos.y)))
		k = ft_abs(dos.x) > ft_abs(dos.y) ? ft_abs(dos.x) : ft_abs(dos.y);
	pas = 0.0;
	c.x = (float)(p1.c) - (float)(p3.c);
	c.y = (float)(p2.c) - (float)(p3.c);
	uno.x = (float)uno.x / (float)k;
	uno.y = (float)uno.y / (float)k;
	dos.x = (float)dos.x / (float)k;
	dos.y = (float)dos.y / (float)k;
	c.y = (float)c.y / (float)k;
	c.x = (float)c.x / (float)k;
	while (pas <= k)
	{
		if (p3.z > 0 && p1.z && p2.z)
		{
			p1.x = p3.x + (pas * uno.x);
			p1.y = p3.y + (pas * uno.y);
			p1.c = p3.c + ((int)((float)pas * c.x));
			p2.x = p3.x + (pas * dos.x);
			p2.y = p3.y + (pas * dos.y);
			p2.c = p3.c + ((int)((float)pas * c.y));
			ft_line_to_image(image, p1, p2, 1);
		}
		++pas;
	}
}


void	ft_line_to_image(t_image *image, t_point p1, t_point p2, int face)
{
	t_point	tmp;
	t_point	c;
	t_point	ini;
	float	k;
	float	pas;

	if (face == 0)
	{
		if (((p1.x > 600 || p1.x < -600 || p1.y > 450 || p1.y < -450) && \
			 (p2.x > 600 || p2.x < -600 || p2.y > 450 || p2.y < -450)) || \
			   (p1.z < 0 || p2.z < 0))
			return;
	}
	ini.x = p1.x - p2.x;
	ini.y = p1.y - p2.y;
	k = ft_abs(ini.x) > ft_abs(ini.y) ? ft_abs(ini.x) : ft_abs(ini.y);
	pas = 0.0;
	c.y = (float)(p1.c % 256) - (float)(p2.c % 256);
	c.x = (float)(p1.c / 256) - (float)(p2.c / 256);
	tmp.x = (float)ini.x / (float)k;
	tmp.y = (float)ini.y / (float)k;
	c.y = (float)c.y / (float)k;
	c.x = (float)c.x / (float)k;
	while (pas <= k)
	{
		if (p2.z > 0 && p1.z)
		{
			ft_pixel_to_image(image, p2.x + (int)(pas * tmp.x), p2.y + \
			(int)(pas * tmp.y),											\
			p2.c + ((int)((float)pas * c.y) + (256 * (unsigned int)((float)pas * c.x))));
		}
		++pas;
	}
}
