ifeq ($(shell uname -s),Darwin)
CC=gcc-11
else ifeq ($(shell uname -s),Linux)
CC=gcc
endif

CFLAGS=-O2 -Wall -Werror

all: main

main: main.c nt.c nt.h tab.h
	$(CC) $(CFLAGS) -o $@ main.c nt.c

clean:
	rm main
