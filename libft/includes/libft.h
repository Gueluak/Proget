/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmarot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 21:15:49 by hmarot            #+#    #+#             */
/*   Updated: 2016/05/06 22:26:36 by hmarot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <sys/stat.h>

long	ft_abs(long n);
int		ft_atoi(const char *str);
int		ft_isascii(int c);
char	*ft_itoa(long n);
char	*ft_itoa_octal(long n);
char	*ft_itoa_hexa(long n);
void	*ft_memalloc(size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_memnchr(char i, void *s, int n);
void	*ft_memndup(void *src, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
void	ft_toupper(char **str);
int		writef(const char *format, ...);
#endif
