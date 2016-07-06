
#include "libdraw.h"

inline void		put_pixel(int x, int y, t_img *img, unsigned int color)
{
	*((int *)(unsigned long)(img->buff + 4 * (x + y * img->width))) = color;
}

inline void		put_line(t_point p1, t_point p2, int color, t_img *img)
{
	int		dif_x;
	int		dif_y;
	int		max;

	dif_x = p1.x - p2.x;
	dif_y = p1.y - p2.y;
	max = d_abs(dif_x) > d_abs(dif_y) ? d_abs(dif_x) : d_abs(dif_y);
	while (max)
	{
		put_pixel(p1.x + (dif_x / max), p1.y + (dif_y / max), img, color);
		--max;
	}
}

inline int		d_abs(int nb)
{
	return (nb > 0 ? nb : -nb);
}