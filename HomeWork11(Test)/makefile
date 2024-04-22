all: main.exe

main.exe: main.o temp_functions.o
	gcc -g -o main main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -g -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -g -c -o temp_functions.o temp_functions.c

clean:
	del *.o
	del main.exe