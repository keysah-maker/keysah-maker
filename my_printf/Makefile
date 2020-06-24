CC	=	gcc -fPIC

NAME	=	my_printf

SRC	=	main.c		\
		printf.c	\
		src/my_put_nbr.c	\
		src/my_putchar.c	\
		src/my_putstr.c	\
		src/my_revstr.c	\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -g3 -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc	$(NAME)	$(OBJ)
		ranlib	$(NAME)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
