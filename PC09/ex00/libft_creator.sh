#!/bin/bash

gcc -c *.c -Wall -Werror -Wextra
ar r  libft.a *.o
