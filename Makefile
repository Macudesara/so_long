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
FLAGS = -Wall -Wextra -Werror -fsanitize="address,undefined" -g
RM = rm -rf

SOURCES = main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_check_errors.c ft_error.c ft_read_map.c ft_flood_fill.c game.c printf/ft_printf_char.c printf/ft_printf_hexalow.c printf/ft_printf_hexaptr.c printf/ft_printf_hexaup.c printf/ft_printf_i_d.c printf/ft_printf_str.c printf/ft_printf_unsig.c printf/protoprintf.c hook.c

MLX = -framework OpenGL -framework AppKit

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

##INCLUDE = -I includes -I libft
##LIBFT_PATH = ./libft
##LIBFT = libft/libft.a

all: makemlx $(NAME)



$(NAME): $(OBJS) Makefile
	$(CC) $(FLAGS) mlx/libmlx.a $(MLX) -lz $(OBJS) -o $(NAME)

%.o: %.c Makefile
	@mkdir -p $(dir $@)
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

