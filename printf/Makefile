#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/29 17:18:27 by hmarot            #+#    #+#              #
#    Updated: 2016/03/24 19:07:56 by hmarot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC =	printf_conv.c 		\
		mini_lib.c 			\
		printf_main.c 		\
		test.c				\
		printf_flag.c		\
		printf_pre_field.c	\
		printf_modif.c		\
		printf_init.c		\
		printf_arg.c

LIB_PATH = libft/

INC_PATH = includes/

OBJ =	

LIB =	

NAME =	test

all : $(NAME)

$(NAME) :
	@gcc -o $(NAME) -I includes $(SRC)
	@echo "$(NAME) compiler\n"

clean :

fclean :clean
	@rm -f $(NAME) 
	@echo "$(NAME) clear\n"

re : fclean all