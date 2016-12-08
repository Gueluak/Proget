# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmarot <hmarot@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/04 13:19:25 by hmarot            #+#    #+#              #
#    Updated: 2016/12/08 02:43:07 by hmarot           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC_PATH = -I includes/

FLAG_GCC = -Werror -Wall -Wextra

OBJ_NAME_FT =	ft_abs.o\
			ft_d_abs.o\
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
			ft_strncat.o\
			ft_strndup.o\
			gnl.o

OBJ_NAME_PRINTF =	mini_lib.o\
				mini_lib_b.o\
				mini_lib_c.o\
				printf_arg.o\
				printf_conv.o\
				printf_conv_b.o\
				printf_conv_bonus.o\
				printf_conv_c.o\
				printf_conv_d.o\
				printf_flag.o\
				printf_flag_a.o\
				printf_init.o\
				printf_main.o\
				printf_modif.o\
				printf_pre_field.o

NAME_FT = libft.a
NAME_PRINTF = printf.a
NAME = libftprintf.a

PATH_FT = ft_src/
PATH_PRINTF = printf_src/

PATH_OBJ_FT = ft_obj/
PATH_OBJ_PRINTF = printf_obj/

OBJ_FT = $(addprefix $(PATH_OBJ_FT),$(OBJ_NAME_FT))
OBJ_PRINTF = $(addprefix $(PATH_OBJ_PRINTF),$(OBJ_NAME_PRINTF))

only_lib: 
	@make fclean && make all && make clean

all: $(OBJ_PRINTF) $(OBJ_FT)
	@ar rc $(NAME) $(OBJ_PRINTF) $(OBJ_FT)
	@echo "$(NAME) compiler"

printf: $(OBJ_PRINTF)
	@ar rc $(NAME_PRINTF) $(OBJ_PRINTF)
	@echo "$(NAME_PRINTF) compiler"

libft: $(OBJ_FT)
	@ar rc $(NAME_FT) $(OBJ_FT)
	@echo "$(NAME_FT) compiler"

ft_obj/%.o : $(PATH_FT)%.c
	@gcc $(FLAG_GCC) -c $< -o $@ $(INC_PATH)

$(PATH_OBJ_PRINTF)%.o : $(PATH_PRINTF)%.c
	@gcc $(FLAG_GCC) -c $< -o $@ $(INC_PATH)

clean:
	@rm -f $(OBJ_FT) $(OBJ_PRINTF)

fclean: clean
	@rm -f $(NAME_FT) $(NAME_PRINTF) $(NAME)

re: fclean all
