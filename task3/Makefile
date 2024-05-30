CC= gcc
FLAGS= -Wall -g


.PHONY: all clean

# build

all : txtfind isort

rebuild: clean all

clean:
	rm  txtfind isort
# apps

isort:
	$(CC) $(FLAGS) -o isort isort.c

txtfind:
	$(CC) $(FLAGS) -o txtfind txtfind.c

