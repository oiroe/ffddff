# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pboonpro <pboonpro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 21:49:15 by pboonpro          #+#    #+#              #
#    Updated: 2023/07/09 15:56:45 by pboonpro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = src/meaw.c src/hextoi.c src/counting.c src/iso.c src/dda.c src/create_image.c \
src/close.c src/put_z.c src/put_xy.c src/check_file.c \

OBJ = $(SRC:%.c=%.o)

LIBFT = libft/libft.a

MINILIB = minilibx_macos/libmlx.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Iinclude

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	$(CC) $(CFLAGS) $^ $(LIBFT) $(MINILIB) -framework OpenGL -framework AppKit -o $@

clean :
	make clean -C libft
	make clean -C ./minilibx_macos
	rm -rf $(OBJ)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
