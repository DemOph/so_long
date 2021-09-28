# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:16:38 by chael-ha          #+#    #+#              #
#    Updated: 2021/09/28 18:24:28 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MINILIBX = -lmlx -framework OpenGL -framework AppKit
SRC		= ft_readmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \

OBJ = $(SRC:.c=.o)
		
DEPS = structs.h \
	get_next_line/get_next_line.h \
	ft_printf/ft_printf.h \
	
CFLAGS = -Wall -Werror -Wextra
CC = gcc
FT_PRINTF = ft_printf/libftprintf.a
RM = rm -rf

all : $(FT_PRINTF) $(NAME)

$(FT_PRINTF):
	make -C ft_printf

$(NAME) : $(OBJ) $(DEPS)	
	$(CC) $(CFLAGS) $(MINILIBX) $(OBJ) $(FT_PRINTF) -o $(NAME)

#$(OBJ) : %.o: %.c
#	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	$(RM) $(OBJ)
	make fclean -C ft_printf	

fclean: clean
	$(RM) $(NAME) $(OBJ)
	make fclean -C ft_printf	

re: fclean all
