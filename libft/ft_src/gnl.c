/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 03:12:52 by hmarot            #+#    #+#             */
/*   Updated: 2016/12/08 03:01:15 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#define	BUF_SIZE 1

int		gnl(int fd, char **line)
{
	char		buff[BUF_SIZE];
	char		*tmp;
	static char	*stat;
	int			i;

	i = 0;
	while (read(fd, buff, BUF_SIZE))
	{
		tmp = ft_strncat(stat, buff, BUF_SIZE);
		free(stat);
		while (tmp[i])
		{
			if (tmp[i] == '\n')
			{
				stat = ft_strndup(tmp + i + 1, ft_strlen(tmp) - i);
				*line = ft_strndup(tmp, i);
				free(tmp);
				return(i + 1);
			}
			i++;
		}
		stat = tmp;
	}
	while (stat[i])
	{
		if (stat[i] == '\n')
		{
			tmp = ft_strndup(stat + i + 1, ft_strlen(stat) - i);
			*line = ft_strndup(stat, i);
			stat != NULL ? free(stat) : 0;
			stat = tmp;
			return(i + 1);
		}
		i++;
	}
	*line = stat;
	return (0);
}
