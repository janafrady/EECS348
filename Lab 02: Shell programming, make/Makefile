CC = gcc

main: main.o isEven.o isOdd.o
	$(CC) -o main main.o isEven.o isOdd.o

main.o: main.c
	$(CC) -c main.c

isEven.o: isEven.c isEven.h
	$(CC) -c isEven.c

isOdd.o: isOdd.c isOdd.h
	$(CC) -c isOdd.c

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o