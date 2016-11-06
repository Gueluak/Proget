/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 17:57:37 by hmarot            #+#    #+#             */
/*   Updated: 2016/03/20 22:38:23 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

short	**ft_read_doc(char *file, t_graf *graf)
{
	short	**grid;
	int		*t;
	char	*buff;

	t = (int *)ft_memalloc(24);
	grid = ft_grid_y(&grid, 0, 0);
	t[0] = open(file, O_RDONLY);
	graf->x = 0;
	buff = (char *)ft_memalloc(1);
	while ((t[1] = read(t[0], buff, 1)))
	{
		buff[0] == 0 ? ft_error(1) : 0;
		buff[0] == '\n' ? if_1(t, &grid, graf) : 0;
		if (buff[0] == '-')
			t[3] = -1;
		if (buff[0] == ' ' && t[2] == 0)
		{
			t[3] = 1;
			t[2] = 1;
		}
		if (buff[0] >= '0' && buff[0] <= '9')
			if_2(t, &grid, buff, graf);
	}
	graf->y = t[5];
	return (grid);
}

void	if_2(int *t, short ***grid, char *buff, t_graf *graf)
{
	if (t[2] == 1)
	{
		++t[4];
		(*grid)[t[5]] = ft_grid_x(&((*grid)[t[5]]), \
(t[4] > graf->x ? t[4] : graf->x));
	}
	t[2] = 0;
	(*grid)[t[5]][t[4]] = ((*grid)[t[5]][t[4]] * 10) + \
(short)(t[3] * (buff[0] - '0'));
}

void	if_1(int *t, short ***grid, t_graf *graf)
{
	t[2] = 0;
	++t[5];
	*grid = ft_grid_y(grid, t[5], t[4]);
	if (graf->x != 0 && graf->x != t[4])
		ft_error(1);
	graf->x = t[4];
	t[4] = 0;
}

short	**ft_grid_y(short ***grid, int y, int x)
{
	short	**tmp;
	int		i;

	i = -1;
	tmp = (short **)ft_memalloc(sizeof(short *) * (y + 2));
	if (*grid)
		while (++i <= y)
			tmp[i] = ft_grid_x(&((*grid)[i]), x);
	if (i >= 0)
		tmp[i] = ft_grid_x(NULL, x);
	else
		tmp[0] = ft_grid_x(NULL, x);
	free(*grid);
	return (tmp);
}

short	*ft_grid_x(short **grid, int x)
{
	short	*tmp;
	int		i;

	i = -1;
	tmp = (short *)ft_memalloc(sizeof(short) * (x + 2));
	if (grid)
		if (*grid)
		{
			while (++i <= x)
			{
				tmp[i] = (*grid)[i];
			}
		}
	if (grid)
		free(*grid);
	return (tmp);
}
