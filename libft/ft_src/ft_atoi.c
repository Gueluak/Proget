/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:59:34 by hmarot            #+#    #+#             */
/*   Updated: 2015/12/09 23:37:18 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int i;
	int k;
	int result;

	i = 0;
	k = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '	' || str[i] == '\n' || str[i] ==\
		'\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		k = 0;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	if (k == 0)
		result = -result;
	return (result);
}
