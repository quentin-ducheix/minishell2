##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## makes
##

SRC	=	main.c				\
		lib/neces.c			\
		lib/neces2.c			\
		lib/my_str_to_word_array.c	\
		lib/neces3.c			\
		lib/cut_in_array.c		\
		lib/the_realloc.c		\
		src/checker.c			\
		src/do_com.c			\
		src/convert.c			\
		src/look_com.c			\
		src/go_redi.c			\
		src/redir.c			\
		src/the_built.c			\
		src/setenv.c			\
		src/env.c			\
		src/env_make.c			\
		src/unsetenv.c			\
		src/cd.c			\
		src/env_show.c			\
		src/prep_make.c

NAME	=	mysh

CFLAGS	=	-I./inc -Werror -Wall -Wextra

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
