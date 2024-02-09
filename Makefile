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
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SOURCES = main.c get_next_line.c get_next_line_utils.c

##MLX = -framework OpenGL -framework AppKit

OBJECTS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)

##INCLUDE = -I includes -I libft
##LIBFT_PATH = ./libft
##LIBFT = libft/libft.a

all: $(NAME) 
##makemlx $(NAME)

$(NAME): $(OBJECTS) Makefile
	$(CC) $(FLAGS) 
##mlx/libmlx.a $(MLX) -lz $(OBJECTS) -o $(NAME)

%.o: %.c Makefile
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

makemlx: 
	$(MAKE) -C mlx/

-include $(DEPS)

clean:
	RM $(OBJECTS) $(DEPS) $(NAME)
##$(MAKE) clean -C mlx

fclean: clean
	RM $(NAME)

re: fclean all

.PHONY: all clean fclean re 
##makemlx

