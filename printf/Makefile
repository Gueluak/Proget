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
		printf_conv_b.c 	\
		printf_conv_c.c 	\
		printf_conv_d.c 	\
		mini_lib.c 			\
		mini_lib_b.c		\
		mini_lib_c.c		\
		printf_main.c 		\
		printf_flag.c		\
		printf_flag_a.c		\
		printf_pre_field.c	\
		printf_modif.c		\
		printf_init.c		\
		printf_arg.c

FLAGS = -Wall -Wextra -Werror

INC_PATH = includes/

OBJ =	printf_conv.o 		\
		printf_conv_b.o 	\
		printf_conv_c.o 	\
		printf_conv_d.o 	\
		mini_lib.o 			\
		mini_lib_b.o		\
		mini_lib_c.o		\
		printf_main.o 		\
		printf_flag.o		\
		printf_flag_a.o		\
		printf_pre_field.o	\
		printf_modif.o		\
		printf_init.o		\
		printf_arg.o

NAME =	libftprintf.a

only_lib: 
	@make fclean && make all && make clean

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c -I includes $(SRC)
	@echo "$(OBJ) compiler\n"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) compiler\n"

clean :
	@rm -f $(OBJ)
	@echo "$(OBJ) clear\n"

fclean :clean
	@rm -f $(NAME) 
	@echo "$(NAME) clear\n"

re : fclean $(NAME)