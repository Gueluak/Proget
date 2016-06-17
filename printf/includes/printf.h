/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 12:04:11 by hmarot            #+#    #+#             */
/*   Updated: 2016/04/05 10:18:20 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define		BUFF_SIZE 100
#define		SHARP (1)
#define		ZERO (1 << 1)
#define		LESS (1 << 2)
#define		MORE (1 << 3)
#define		SPACE (1 << 4)

typedef	struct	s_env
{
	char	flag;
	char	pressi;
	char	field;
	char	modif;
	char	buffer[BUFF_SIZE];
	int		pos;
}				t_env;



void			push_buff(char c, t_env *env);
int				prf_conv(char *format, int i, t_env *env, va_list ap);
int				char_chr(char c, char *chr);
void			prf_conv_mod(t_env *env, va_list ap);
int				ft_printf(const char *restrict format, ...);
int				prf_flag(char *form, int i, t_env *env);
void			prf_flag_sharp(t_env *env);
void			prf_flag_zero(t_env *env);
void			prf_flag_less(t_env *env);
void			prf_flag_more(t_env *env);
void			prf_flag_space(t_env *env);
int				prf_pressi(char *form, int i, t_env *env);
int				prf_field(char *form, int i, t_env *env);
int				prf_modif(char *form, int i, t_env *env);
void			prf_init(t_env *env);
unsigned long	prf_u_arg(va_list ap, t_env env);
long			prf_arg(va_list ap, t_env env);
void			prf_con_s(t_env *env, va_list ap);
void			prf_con_ls(t_env *env, va_list ap);
void			prf_con_p(t_env *env, va_list ap);
void			prf_con_ld(t_env *env, va_list ap);
void			prf_con_id(t_env *env, va_list ap);
void			prf_con_o(t_env *env, va_list ap);
void			prf_con_lo(t_env *env, va_list ap);
void			prf_con_u(t_env *env, va_list ap);
void			prf_con_lu(t_env *env, va_list ap);
void			prf_con_x(t_env *env, va_list ap);
void			prf_con_lx(t_env *env, va_list ap);
void			prf_con_c(t_env *env, va_list ap);
void			prf_con_lc(t_env *env, va_list ap);
void			prf_itoa(long nb, t_env *env);
int				nb_len(long nb);
void			prf_pos_pressi(t_env *env, int len);
void			aply_signe(long nb, t_env *env);
void			prf_pos_field(t_env *env, int len);