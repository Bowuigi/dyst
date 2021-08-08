CC=cc
CFLAGS=-Og -ggdb -std=c99 -Wall

build:
	${CC} ${CFLAGS} test.c -o test
