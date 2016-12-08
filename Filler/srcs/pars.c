/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 02:26:04 by hmarot            #+#    #+#             */
/*   Updated: 2016/12/08 04:04:15 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		pars_grid(t_map *map)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	gnl(0, &str);
	map->y_grid = ft_atoi(str + 7);
	map->x_grid = ft_atoi(str + 11);
	gnl(0, &str);
	map->grid = (int **)ft_memalloc(map->y_grid * sizeof(int *));
	while (j < map->y_grid)
	{
		gnl(0, &str);
		i = 4;
		map->grid[j] = (int *)ft_memalloc(map->x_grid * sizeof(int));
		print("\n");
		while(i < map->x_grid + 4)
		{
			if (str[i] != '.')
				map->grid[j][i - 4] = (str[i] == 'O' || str[i] == 'o' ? 1 : 2);
			print("%d", map->grid[j][i - 4]);
			i++;
		}
		j++;
	}
	gnl(0, &str);
	map->y_pce = ft_atoi(str + 6);
	map->x_pce = ft_atoi(str + 8);
	j = 0;
	print("\n");
	map->pce = (int **)ft_memalloc(map->y_pce * sizeof(int *));
	while (j < map->y_pce)
	{
		i = 0;
		gnl(0, &str);
		while (i < map->x_pce)
		{
			map->pce[j] = (int *)ft_memalloc(map->x_pce * sizeof(int));
			if (str[i] == '*')
				map->pce[j][i] = 1;
			print("%d",map->pce[j][i]);
			i++;
		}
		print("\n");
		j++;
	}
}