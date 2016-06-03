# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 13:19:25 by hmarot            #+#    #+#              #
#    Updated: 2016/04/07 17:29:16 by hmarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_abs.c\
		ft_atoi.c\
		ft_isascii.c\
		ft_itoa.c\
		ft_itoa_octal.c\
		ft_itoa_hexa.c\
		ft_memalloc.c\
		ft_memcmp.c\
		ft_memmove.c\
		ft_memnchr.c\
		ft_memndup.c\
		ft_memset.c\
		ft_putendl_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		ft_toupper.c\
		writef.c

OBJ =	ft_abs.o\
		ft_atoi.o\
		ft_isascii.o\
		ft_itoa.o\
		ft_itoa_octal.o\
		ft_itoa_hexa.o\
		ft_memalloc.o\
		ft_memcmp.o\
		ft_memmove.o\
		ft_memnchr.o\
		ft_memndup.o\
		ft_memset.o\
		ft_putendl_fd.o\
		ft_putstr_fd.o\
		ft_strlen.o\
		ft_toupper.o\
		writef.o

NAME = libft.a

only_lib: 
	@make fclean && make all && make clean

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
