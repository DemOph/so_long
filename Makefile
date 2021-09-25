# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/17 14:16:38 by chael-ha          #+#    #+#              #
#    Updated: 2021/09/23 19:02:43 by chael-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long

MINILIBX = -lmlx -framework OpenGL -framework AppKit
SRC		= ft_readmap.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		ft_atoi.c \
		#test.c \

OBJ = $(SRC:.c=.o)
		
DEPS = structs.h \
	get_next_line/get_next_line.h \

# CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -rf

all : $(NAME)
	
$(NAME) : $(OBJ) $(DEPS)	
	$(CC) -g $(CFLAGS) $(MINILIBX) ft_readmap.c -o $(NAME)
#ft_readmap.c

#$(OBJ) : %.o: %.c
#	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME) $(OBJ)

re: fclean all