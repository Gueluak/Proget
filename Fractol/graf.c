/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/26 22:04:21 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			put_pixel_to_img(t_graf *graf, unsigned int color, int x, int y)
{
	if (x < graf->mlx_i->width && y < graf->mlx_i->height)
		((unsigned int *)(graf->mlx_i->buffer))[x + y *
		graf->mlx_i->width] = color;
}

unsigned int	get_color(unsigned int i)
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	red = 0;
	green = 0;
	blue = 0;
	i = i % 0x600;
	if (i <= 0xff)
	{
		red = 0;
		green = i;
		blue = 0xff;
	}
	else if (i <= 0x1ff)
	{
		red = 0;
		green = 0xff;
		blue = 0xff - i % 0x100;
	}
	else
		get_color_bis(&red, &green, &blue, i);
	return (red * 0x10000 + green * 0x100 + blue);
}

void			get_color_bis(unsigned char *red, unsigned char *green,
	unsigned char *blue, unsigned int i)
{
	if (i <= 0x2ff)
	{
		*red = i % 0x100;
		*green = 0xff;
		*blue = 0;
	}
	else if (i <= 0x3ff)
	{
		*red = 0xff;
		*green = 0xff - i % 0x100;
		*blue = 0;
	}
	else if (i <= 0x4ff)
	{
		*red = 0xff;
		*green = 0;
		*blue = i % 0x100;
	}
	else
	{
		*red = 0xff - i % 0x100;
		*green = 0;
		*blue = 0xff;
	}
}
