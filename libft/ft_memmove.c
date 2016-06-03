/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:13:33 by hmarot            #+#    #+#             */
/*   Updated: 2015/12/22 14:44:27 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	if (dst == src)
		return ((void *)src);
	if (dst > src)
	{
		i = len - 1;
		while (i >= 0)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)len)
		{
			*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
			i++;
		}
	}
	return (dst);
}
