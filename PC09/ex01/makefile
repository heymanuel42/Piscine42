CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
SRC 			= srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_swap.c srcs/ft_strcmp.c
DEPENDENCIES 	= includes/ft.h
OBJECTS			= $(SRC:.c=.o)
LIB				= libft.a

all: $(LIB)

$(LIB): $(OBJECTS)
	ar r $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(LIB)

re : fclean all
