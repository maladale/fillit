NAME 	=	fillit

SRC		=	fill.c print.c main.c valide_form.c valide_one.c validate.c

OBJ		= 	fill.o main.o valide_form.o print.o valide_one.o validate.o

CFALGS	=	-Wall -Wextra -Werror

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc $(CFLAGS) -c $(SRC)
	gcc -L./libft -lft $(OBJ) -o fillit
	
clean:
	/bin/rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re:	fclean all
