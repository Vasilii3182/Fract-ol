# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofranco <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/21 14:38:17 by ofranco           #+#    #+#              #
#    Updated: 2017/10/01 16:26:43 by ofranco          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol 

SRCPATH = ./srcs/

HEADER = ./includes/

SRCS = tree.c julia.c mandelbrot.c fractol.c window.c image.c

LIB = Libft/Libft.a

OBJ = $(SRCS:.c=.o)

FLAGS += -Wall -Wextra -Werror -g

FSRCS = $(addprefix $(SRCPATH), $(SRCS))

all : $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I $(HEADER) minilibx_macos/libmlx.a -framework OpenGL -framework AppKit $(LIB) $(FSRCS) -o $(NAME) 

clean :
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
