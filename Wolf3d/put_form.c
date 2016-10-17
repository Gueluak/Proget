
#include "draw.h"

inline void	put_pixel(t_img *img, int x, int y, unsigned int color)
{
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
		*(img->buffer + (y * width) + x) = color;
}

void		put_sprite(t_img *img, t_img *sprite, t_quadra *zone, float leinght)
{
	int		x;
	int		y;


}

