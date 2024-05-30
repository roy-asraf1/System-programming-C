CC = gcc
FLAGS = -Wall -g -fPIC


all: graph

graph:  graph.o main.o
	$(CC) $(FLAGS) $^ -o $@


%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm  *.o graph
