# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-sara <mde-sara@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 17:37:54 by mde-sara          #+#    #+#              #
#    Updated: 2024/02/05 11:52:23 by mde-sara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
FLAGS = -Wall -Wextra -Werror -MMD -g
##-MMD -g necessary to make touch .h y se crean las dependencias
##-fsanitize="address,undefined" -g
RM = rm -rf

SOURCES = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	ft_check_errors.c ft_error.c ft_read_map.c ft_flood_fill.c game.c hook.c movements.c images.c\
	printf/ft_printf_char.c printf/ft_printf_hexalow.c printf/ft_printf_hexaptr.c printf/ft_printf_hexaup.c \
	printf/ft_printf_i_d.c printf/ft_printf_str.c printf/ft_printf_unsig.c printf/protoprintf.c

MLX = -framework OpenGL -framework AppKit

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

##INCLUDE = so_long.h

all: makemlx $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) mlx/libmlx.a $(MLX) $(OBJS) -o $(NAME)

%.o: %.c Makefile
	$(CC) $(FLAGS) -I ./ -c $< -o $@

makemlx: 
	$(MAKE) -C mlx/

-include $(DEPS)

clean:
	RM $(OBJS) $(DEPS) $(NAME)
	$(MAKE) clean -C mlx

fclean: clean
	RM $(NAME)

re: fclean all

.PHONY: all clean fclean re makemlx