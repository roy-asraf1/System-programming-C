AR=ar
CC=gcc
FLAGS= -Wall -g

all: libmymat.a connections

connections: main.o libmymat.a
	$(CC) $(FLAGS) -o connections main.o libmymat.a

libmymat.a:my_mat.o
	$(AR) -rcs libmymat.a my_mat.o

my_mat.o:my_mat.c my_mat.h
	$(CC) $(FLAG) -c my_mat.c

main.o:main.c my_mat.h
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f *.o *.a connections