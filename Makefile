CC = gcc
OBJECTS_MAIN = main.o
FLAGS = -Wall -g

all: stringProg


stringProg: $(OBJECTS_MAIN) 
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN)


main.o: main.c 
	$(CC) $(FLAGS) -c main.c


.PHONY = clean all


clean: 
	rm -f *.o stringProg