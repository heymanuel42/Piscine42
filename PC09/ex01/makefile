
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
INCLUDES  		= -Iincludes/
SRC 			= src/
DEPENDENCIES 	= ft.h
OBJ				= src/ft_putchar.o src/ft_putstr.o src/ft_strcmp.o src/ft_strlen.o src/ft_swap.o

%.o : %.c $(DEPENDENCIES)
	$(CC) -c $@ $< $(CFLAGS)


all: libft.a

libft.a: $(OBJ)
	ar rfc libft.a $^

clean:
	rm -f src/*.o

fclean: clean
	rm -f *.a

re : fclean all
