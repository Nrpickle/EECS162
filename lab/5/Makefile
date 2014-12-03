all: main

main: main.o file.o document.o email.o
	g++ main.o file.o document.o email.o -o run
	
main.o: main.cpp
	g++ -c main.cpp

file.o: file.cpp
	g++ -c file.cpp

document.o: document.cpp
	g++ -c document.cpp

email.o: email.cpp
	g++ -c email.cpp

clean:
	rm -f *.o run
