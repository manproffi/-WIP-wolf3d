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

SDL_HEADER_DIR = -I ./framework/SDL2.framework/Headers
SDL_HEADER_DIR += -I ./framework/SDL2_image.framework/Headers
SDL_HEADER_DIR += -F ./framework

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

SRC = main.c delete.c read_from_file.c input_information.c start_work_with_map.c \
 		start_loop.c \
 		delete_window.c \
 		create_window.c \
 		loop.c \
 		add_color.c
 
OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

FLG = -framework OpenGL -framework AppKit -framework SDL2 -framework SDL2_image

all:	$(NAME)

$(NAME): lib $(OBJ) head_wolf.h
	gcc $(FLAG) $(OBJ) -o $(NAME) $(LIB_ALL) $(SDL_HEADER_DIR) $(FLG)

%.o: %.c head_wolf.h
	gcc $(FLAG) $(SDL_HEADER_DIR) -c -o $@ $<

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