#!/bin/bash

gcc -c *.c
ar rsc  libft.a *.o
rm *.o
