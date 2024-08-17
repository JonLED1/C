all: prog.exe

prog.exe: main.o menu.o field.o drone.o
	gcc -g -o prog main.o menu.o field.o drone.o

main.o: main.c menu.h field.h
	gcc -g -c -o main.o main.c

menu.o: menu.c menu.h
	gcc -g -c -o menu.o menu.c

field.o: field.c field.h
	gcc -g -c -o field.o field.c

drone.o: drone.c drone.h
	gcc -g -c -o drone.o drone.c

clean:
	del *.o
	del prog.exe