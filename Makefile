NAME = fdf

CC = gcc
LFTPATCH = ./libft/
LMLXPATCH = ./minilibx/
LIBS = -L $(LFTPATCH) -lft -L $(LMLXPATCH) -lmlx -framework OpenGL -framework AppKit
FLAGS = -Wall -Werror -Wextra
SRC = main.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make re -C $(LFTPATCH)
	make re -C $(LMLXPATCH)
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(OBJ) $(LIBS) -o $(NAME)
	make fclean -C $(LFTPATCH)
	make clean -C $(LMLXPATCH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
