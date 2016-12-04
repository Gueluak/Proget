#include "filler.h"

void	ft_pars(t_map *map)
{
	int		x;
	int		y;
	int		i;
	int		j;
	int		k;
	char	*str;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	k = 0;
	map->plateau = ft_tableau(&x, &y);
	free(read_line(0));
	while (j < y)
	{
		i = 4;
		k = 0;
		str = read_line(0);
		while (k < x)
		{
			//write(2, "malin\n", 6);
			str[i] == '.' ? map->plateau[j][k] = 0 : 0;
			str[i] == 'o' || str[i] == 'O' ? map->plateau[j][k] = 1 : 0;
			str[i] == 'x' || str[i] == 'X' ? map->plateau[j][k] = 2 : 0;
			i++;
			k++;
		}
		free(str);
		map->plateau[j][k] = -1;
		j++;
	}
}

int		**ft_tableau(int *x, int *y)
{
	char	*str;
	int		**tab;
	int		i;

	i = 0;
	str = read_line(0);
	*y = ft_atoi(str + 8);
	print("str = %s\n", str);
	*x = ft_atoi(str + 11);
	free(str);
	tab = ft_memalloc(*y * sizeof(int *) + 1);
	while(i < *y)
	{
		tab[i] = ft_memalloc(*x * sizeof(int) + 1);
		i++;
	}
	return(tab);
}