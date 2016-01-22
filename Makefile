# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amineau <amineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 14:14:56 by amineau           #+#    #+#              #
#    Updated: 2016/01/22 14:15:05 by amineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc
LFTPATCH = ./libft/
LMLXPATCH = ./minilibx/
LIBS = -L$(LMLXPATCH) -lmlx -framework OpenGL -framework AppKit -L$(LFTPATCH) -lft 
FLAGS = -Wall -Werror -Wextra
SRC = main.c \
	  hook.c \
	  segment.c \
	  recup_coor.c \
	  error.c \
	  display.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C $(LFTPATCH)
	make -C $(LMLXPATCH)
	$(CC) $(FLAGS) -c $(SRC) 
	$(CC) $(OBJ) $(LIBS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
