
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
INCLUDES  		= -Iincludes/
SRC 			= src/
DEPENDENCIES 	= ft.h
OBJ				= src/ft_putchar.o src/ft_putstr.o main.o
PROGRAM			= ft_display_file

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
