/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 00:44:41 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/08 20:11:56 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		lst_new(t_lst **lst)
{
	t_lst	*tmp;
	t_lst	*ret;

	tmp = *lst;
	if (tmp)
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	if (!(ret = (t_lst *)ft_memalloc(sizeof(t_lst))))
		return (0);
	ret->prev = (*lst == NULL ? NULL : tmp);
	if (*lst == NULL)
		*lst = ret;
	else
		tmp = ret;
	return (1);
}

int		lst_del(t_lst **lst)
{
	t_lst	*next;

	next = *lst;
	while (next)
	{
		next = (*lst)->next;
		free(*lst);
		*lst = next;
	}
	return (1);
}

//int		lst_time_short()
//{

//}

int		lst_name_short(t_lst **lst, int size)
{
	int		i;
	short	not_end;
	t_lst	*tmp;

	i = 0;
	printf("malin\n");
	tmp = (*lst)->next;
	not_end = 1;
	size = size+1;
	while (not_end)
	{
		i = 0;
//		printf("lapin = %d\n",size);
		not_end = 0;
		while (tmp->next && (*lst)->next)
		{
			printf("%d\n",i);
			printf("%s\n",(*lst)->name);
			if (0 < ft_memcmp((*lst)->name, tmp->name, (ft_strlen((*lst)->name) > \
				ft_strlen(tmp->name) ? ft_strlen((*lst)->name) : ft_strlen(tmp->name))))
			{
				(*lst)->next = tmp->next;
				tmp->prev = (*lst)->prev;
				tmp->next = (*lst);
				(*lst)->prev = tmp;
				tmp = (*lst)->next;
				not_end = 1;
			}
			else if (tmp->next)
			{
//				printf("chien\n");
				tmp = tmp->next;
			}
			i++;
		}
	}
	return (0);
}
