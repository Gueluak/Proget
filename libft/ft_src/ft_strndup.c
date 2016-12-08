/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:39:53 by hmarot            #+#    #+#             */
/*   Updated: 2016/12/05 04:51:13 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(char *src, size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = ft_memalloc(size + 1);
	while (i < size)
	{
		(dst)[i] = (src)[i];
		i++;
	}
	return (dst);
}
