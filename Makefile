CFLAGS=-std=c17 -Wall -Wextra -Werror

all:build run

run:
	@./main

build:
	@gcc main.c -o main ${CFLAGS} `sdl2-config --cflags --libs`
