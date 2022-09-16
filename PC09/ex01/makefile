
CC 				= gcc
CFLAGS 			= -Wall -Werror -Wextra
INCLUDES  		= -Iincludes/
SRC 			= $(wildcard srcs/*.c)
DEPENDENCIES 	= ft.h
OBJ				= $(SRC:.c=.o)


all: libft.a

%.o : %.c  $(CFLAGS) $(DEPENDENCIES) $(INCLUDES)
	$(CC) -c $@ $<


libft.a: $(OBJ)
	ar r libft.a $^

clean:
	rm -f srcs/*.o

fclean: clean
	rm -f *.a

re : fclean all
