/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 18:31:14 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/05 10:18:23 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct	s_max
{
	unsigned long int	i;
	char					s;
}				t_max;

typedef struct	s_print_op
{
	char		plus;
	char		moins;
	char		zerro;
	char		space;
	char		diez;
	char		champ;
	char		press;
	char		modif;
	t_max		conv;
	char		*str;
}				t_print_op;

int				ft_printf(const char *restrict format, ...);
int				ft_flag(char *format, int index, t_print_op *p_op);
int				ft_champ(char *format, int index, t_print_op *p_op);
int				ft_press(char *format, int index, t_print_op *p_op);
int				ft_modif(char *format, int index, t_print_op *p_op);
int				ft_conv(char *format, int index, t_print_op *p_op, va_list va);
void			ft_conv_type(char i, t_print_op *p_op);
t_max			ft_cast(va_list arg, int type, int modif);
int				ft_print(t_print_op p_op, char c);
int				ft_print_s(t_print_op p_op);
int				ft_print_mod(t_print_op p_op);
int				ft_print_pointer(t_print_op p_op);
int				ft_print_d(t_print_op p_op);
void			ft_init(t_print_op *p_op);
void			ft_flag_space(t_print_op *p_op);
void			ft_flag_moins(t_print_op *p_op);
void			ft_flag_plus(t_print_op *p_op);
void			ft_flag_diez(t_print_op *p_op);
void			ft_flag_zerro(t_print_op *p_op);
