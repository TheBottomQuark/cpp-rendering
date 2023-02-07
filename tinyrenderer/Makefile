SHELL = /bin/sh

OBJS = $(patsubst %.cpp,%.o,$(wildcard *.cpp))
CFLAGS = -Wall -g
LDFLAGS =
LIBS = -lm
CC = g++
EXECUTABLE = program

${EXECUTABLE}:${OBJS}
	${CC} ${OBJS} -o $@ ${CFLAGS} ${LDFLAGS} ${LIBS}

clean:
	rm -f ${OBJS}
	rm -f ${EXECUTABLE}
	rm -f *.tga
