/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 22:05:58 by hmarot            #+#    #+#             */
/*   Updated: 2016/02/07 14:07:32 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *type;

	if (size > 130048)
		return (0);
	type = (unsigned char *)malloc(size * sizeof(*type));
	if (type == 0)
		return (0);
	while (size > 0)
	{
		size--;
		*((unsigned char *)type + size) = 0;
	}
	return (type);
}
