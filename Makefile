# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 12:02:20 by sprotsen          #+#    #+#              #
#    Updated: 2017/05/21 12:02:22 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

SRC = main.c delete.c read_from_file.c input_information.c start_work_with_map.c \
 		start_loop.c create_window.c
 
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

FLG = -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME): lib $(OBJ) head_wolf.h
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIB_ALL) $(FLG)

%.o: %.c head_wolf.h
	gcc $(FLAG) -c -o $@ $<

lib:
	make -C libft
	make -C ft_printf

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean lib all	