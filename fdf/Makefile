#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 01:40:50 by hmarot            #+#    #+#              #
#    Updated: 2016/09/26 20:17:40 by hmarot           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAG_MLX = -framework OpenGL -framework AppKit

FLAG_GCC = -Werror -Wall -Wextra

MLX_PATH = minilibx_macos/

MLX = -lmlx

LIBFT = libft/libft.a

PTHREAD = -lpthread

NAME = FDF2

INC_PATH = includes/

SRC =	fdf_main.c\
		fdf_pars.c\
		fdf_grafic.c\
		fdf_conv.c\
		fdf_loop.c\
		fdf_loop_only.c\
		fdf_rot.c

all : $(NAME)

$(NAME) :
	@gcc $(FLAG_GCC) -o $(NAME) -L $(MLX_PATH) -I $(INC_PATH) $(PTHREAD) $(MLX) $(FLAG_MLX) $(SRC) libft/libft.a
	@echo "$(NAME) create.\n"

re :
	@rm -f $(NAME)
	@echo "$(NAME) deleted.\n"
	@make $(NAME)