SHELL = /bin/sh

OBJS = main.o tgaimage.o
CFLAGS = -Wall -g
CC = g++
EXECUTABLE = program

${EXECUTABLE}:${OBJS}
	${CC} ${OBJS} -o $@ ${CFLAGS}

clean:
	rm -rf ${OBJS}
