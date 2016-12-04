/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 21:02:30 by hmarot            #+#    #+#             */
/*   Updated: 2016/11/16 23:40:13 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main(void)
{
	int		i; 
	int		j;
	char	c;
	t_map	map;

	i = 0;
	free(read_line(0));
	write(1, "a\n", 2);
	 while ((1))
	 {
	 	ft_pars(&map);
	 	i = 0;
	 	write(2 ,"\n\n\nfff\n\n\n", 9);
	 	while (map.plateau[i])
	 	{
	 		j = 0;
	 		while (map.plateau[i][j] != -1)
	 		{
	 			c = map.plateau[i][j] + '0';
	 			write(2, &c, 1);
	 			j++;
	 		}
	 		write(2, "\n", 1);
	 		i++;
	 	}

	 write(2, "lapin\n", 6);
	 }
}