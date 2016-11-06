/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 22:46:00 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/22 13:06:08 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(long nbr)
{
	int		i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(long n)
{
	char	*str;
	int		i;
	int		is_negatif;

	n < 0 ?	is_negatif = 1 : is_negatif = 0;
	i = ft_power(n) + is_negatif;
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (NULL);
	n == 0 ? str[0] = '0' : 0;
	while (n != 0)
	{
		i--;
		str[i] = (ft_abs(n % 10)) + '0';
		n = n / 10;
	}
	is_negatif == 1 ? str[0] = '-' : 0;
	return (str);
}
