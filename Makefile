#CC = gcc
CFLAGS = -std=c99 -fopenmp -Wall -O0 -g
LDLIBS = -lm
SRC = mandelbrot.c algorithm.c
OBJ = $(SRC:.c=.o)
TARGETS = mandelbrot

.PHONY : all
all : $(TARGETS)

mandelbrot : mandelbrot.o algorithm.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

mandelbrot.o : mandelbrot.c algorithm.h
	$(CC) $(CFLAGS) -o $@ -c $<

algorithm.o : algorithm.c algorithm.h
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : clean
clean :
	rm -fv $(TARGETS) $(OBJ)
