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

SRC =	printf_cast.c\
		printf_champ.c\
		printf_conv.c\
		printf_flag.c\
		printf_main.c\
		printf_modif.c\
		printf_press.c\
		printf_print.c

LIB_PATH = libft/

OBJ =	printf_cast.o\
		printf_champ.o\
		printf_conv.o\
		printf_flag.o\
		printf_main.o\
		printf_modif.o\
		printf_press.o\
		printf_print.o

LIB =	libft/libft.a

NAME =	libftprintf.a

all : $(NAME)

$(NAME) :
	@make -C libft/ all
	@gcc -c -I includes $(SRC)
	@ar rc $(NAME) $(OBJ) $(LIB_PATH)*.o 
	@echo "$(NAME) compiler\n"

clean :
	@rm -f $(OBJ)
	@echo "$(OBJ) clear\n"

fclean :clean
	@rm -f $(NAME) 
	@rm -f libft/libft.a
	@echo "$(NAME) clear\n"

re : fclean all