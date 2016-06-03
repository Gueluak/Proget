/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 13:09:38 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/22 13:14:43 by hmarot           ###   ########.fr       */
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
		n = n / 16;
		i++;
	}
	return (i);
}

char		*ft_itoa_hexa(long n)
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
		str[i] = (n < 10) ? ((n % 16) + '0') : ((n % 16) - 10 + 'a');
		n = n / 16;
	}
	return (str);
}
