pong: main.o draw.o
	gcc -o pong main.o draw.o

main.o: main.c draw.h components.h
	gcc -c main.c

draw.o: draw.c draw.h components.h
	gcc -c draw.c


clean:
	rm *.o
