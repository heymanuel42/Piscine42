CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRC 			= $(wildcard srcs/*.c) $(wildcard *.c) $(wildcard srcs/ft/*.c)
INCLUDES 	= -Iincludes
OBJECTS			= $(SRC:.c=.o)
PROGRAM				= bsq

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	gcc -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROGRAM)

re : fclean all
