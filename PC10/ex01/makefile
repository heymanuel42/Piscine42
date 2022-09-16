
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
INCLUDES  		= -Iincludes/
SRC 			= src/
DEPENDENCIES 	= ft.h
OBJ				= src/ft_putchar.o src/ft_putstr.o main.o src/ft_strcmp.o src/ft_strlen.o src/ft_strncmp.o src/ft_contains.o
PROGRAM			= ft_cat

%.o : %.c $(DEPENDENCIES)
	$(CC) -c $@ $< $(CFLAGS)


all: $(PROGRAM)


$(PROGRAM): $(OBJ)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ) $(PROGRAM)

fclean: clean
	rm -f *.a

re : fclean all
