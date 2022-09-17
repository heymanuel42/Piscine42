CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRC 			= $(wildcard srcs/*.c) $(wildcard *.c) $(wildcard srcs/ft/*.c)
DEPENDENCIES 	= $(wildcard includes/*.h) $(wildcard includes/ft/*.h)
OBJECTS			= $(SRC:.c=.o)
PROGRAM				= Rush-02

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	gcc -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROGRAM)

re : fclean all
