# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 13:19:25 by hmarot            #+#    #+#              #
#    Updated: 2016/12/08 02:41:34 by hmarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libftprintf.a

INC_PATH = -I includes -I libft/includes

FLAG_GCC = -Werror -Wextra -Wall

SRC_PATH = srcs/

OBJ_NAME = test.o\
			pars.o

OBJ_PATH = objs/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME = hmarot.filler

all : $(NAME)

libs:
	make -C libft/ all

$(NAME) : libs $(OBJ)
	gcc $(FLAG_GCC) -o $(NAME) $(INC_PATH) $(OBJ) $(LIB)
	echo "$(NAME) create.\n"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	gcc $(FLAG_GCC) -c $< -o $@ $(INC_PATH)

re : fclean
	echo "$(NAME) delete.\n"
	make $(NAME)

clean : 
	rm -f $(OBJ)
	make -C libft/ clean 

fclean : clean
	rm -f $(NAME)
	rm -f $(LIB)