/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:01:06 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/22 13:08:00 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int n)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n = n / 8;
		i++;
	}
	return (i);
}

char		*ft_itoa_octal(long n)
{
	char	*str;
	int		i;

	i = ft_power(n);
	if (!(str = (char *)ft_memalloc(i + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		i--;
		str[i] = (n % 8) + '0';
		n = n / 8;
	}
	return (str);
}
