all: main

main: Main.o Dice.o
	g++ Main.o Dice.o -o run

Main.o: Main.cpp
	g++ -c Main.cpp

Dice.o: Dice.cpp
	g++ -c Dice.cpp
