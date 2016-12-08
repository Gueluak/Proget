/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 13:39:53 by hmarot            #+#    #+#             */
/*   Updated: 2016/12/05 04:33:30 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t		i;
	char		*str;

	i = ft_strlen(s1);
	str = ft_memalloc(i + n + 1);
	ft_memmove(str, s1, i);
	ft_memmove(str + i, s2, n);
	return (str);
}
