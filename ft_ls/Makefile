#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 01:40:50 by hmarot            #+#    #+#              #
#    Updated: 2016/05/08 17:11:16 by hmarot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG_GCC = -Werror -Wall -Wextra

LIB_PATH = libft/

LIBFT = -lftprintf

NAME = ft_ls

INC_PATH = includes/

SRC =	test.c \
		main.c \
		ls_pars.c \
		lst_ls.c\
		tab_func.c

all : $(NAME)

$(NAME) :
	@make -C libft/ all
	@gcc $(FLAG_GCC) -o $(NAME) -L $(LIB_PATH) $(LIBFT) -I $(INC_PATH) $(SRC)
	@echo "$(NAME) create.\n"

re :
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(NAME) deleted.\n"
	@make $(NAME)