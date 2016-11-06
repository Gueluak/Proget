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

LIBFT = libft/libftprintf.a

PTHREAD = -lpthread

NAME = fractol

INC_PATH = -I includes/ -I libft/includes/ -I minilibx_macos/

SRC =	main.c\
		fractol_loop.c\
		key.c

all : $(NAME)

$(NAME) :
	@make -C libft/ all
	@gcc $(FLAG_GCC) -o $(NAME) -L $(MLX_PATH) $(INC_PATH) $(PTHREAD) $(MLX) $(FLAG_MLX) $(SRC) $(LIBFT)
	@echo "$(NAME) create.\n"

re : fclean
	@echo "$(NAME) deleted.\n"
	@make $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean