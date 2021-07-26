CC=cc
CFLAGS=-O0 -ggdb -std=c99 -Wall -Wpedantic

build:
	${CC} ${CFLAGS} test.c -o test
