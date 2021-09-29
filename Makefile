# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:16:38 by chael-ha          #+#    #+#              #
#    Updated: 2021/09/29 18:55:44 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MINILIBX = -lmlx -framework OpenGL -framework AppKit
SRC		= ft_readmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_put_error.c \
		ft_load_texture.c \
		map_texture_array.c \
		ft_move_player.c \
		draw_map.c \
		ft_exit.c \
		key_press.c \
		screen_to_black.c \
		my_mlx_pixel_put.c \
		main.c \
		init_param.c \
		is_map_valid.c \
		countx.c \
		county.c \

OBJ = $(SRC:.c=.o)
		
DEPS = structs.h \
	get_next_line/get_next_line.h \
	
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ) $(DEPS)	
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)

re: fclean all
