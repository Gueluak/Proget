/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 22:17:23 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/08 20:04:32 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

int		main(int ac, char **av)
{
	DIR				*dir;
	struct dirent	*dir_s;
	t_opt			opt;
	t_lst			*lst;
	t_lst			*tmp;
	int				size;

	size = 0;
	ft_init(&opt);
	if (ac != 1)
		if (!ls_pars(av, &opt))
			return (0);
	lst = NULL;
	dir = opendir(opt.path);
	printf("malin\n");
	lst_new(&lst);
	printf("alpin\n");
	tmp = lst;
	lst = (t_lst *)ft_memalloc(sizeof(t_lst));
	while ((dir_s = readdir(dir)))
	{
		if (dir_s->d_name[0] != '.' || opt.a == 1)
		{
			tmp = (t_lst *)ft_memalloc(sizeof(t_lst));
//			lst_new(&lst);
			lst->name = dir_s->d_name;
			printf("lst->name = %s\n",lst->name);
			tmp->prev = lst;
			lst->next = tmp;
			lst = lst->next;
			++size;
		}
	}
	printf("\n\n\n");
	while (lst->prev)
		lst = lst->prev;
	lst_name_short(&lst, size);
	printf("rien\n");
	while (lst->prev)
		lst = lst->prev;
	printf("\n\n\n");
	while (lst)
	{
		printf("%s\n",lst->name);
		lst = lst->next;
	}
}
