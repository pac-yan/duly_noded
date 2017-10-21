all: my_tunez.o definitions.o playlist_test.o
	gcc -o playlist_test my_tunez.o definitions.o playlist_test.o

my_tunez.o: my_tunez.c my_tunez.h
	gcc -c my_tunez.c

definitions.o: definitions.c definitions.h
	gcc -c definitions.c

playlist_test.o: playlist_test.c definitions.h my_tunez.h
	gcc -c playlist_test.c

clean:
	rm *.o
	rm *~

run: all
	./playlist_test