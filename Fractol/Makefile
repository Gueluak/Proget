#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/02 01:40:50 by hmarot            #+#    #+#              #
#    Updated: 2016/11/16 23:38:26 by hmarot           ###   ########.fr        #
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

OBJS =	main.o			\
		fractol_loop.o	\
		key.o			\
		graf.o			\
		julia.o			\
		jubis.o			\
		mandel.o		\
		burn.o			\
		mouse.o

OBJ = $(addprefix objs/, $(OBJS))

all : $(NAME)

libs:
	@make -C libft/

$(NAME) : libs $(OBJ)
	@gcc $(FLAG_GCC) -o $(NAME) $(INC_PATH) $(PTHREAD) $(MLX) $(FLAG_MLX) $(OBJ) $(LIBFT)
	@echo "$(NAME) create.\n"

objs/%.o : srcs/%.c
	@gcc $(FLAG_GCC) -c $< -o $@ $(INC_PATH)

re : fclean
	@echo "$(NAME) deleted.\n"
	@make $(NAME)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@make -C libft/ fclean