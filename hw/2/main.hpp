/* 
This is the header file for an implementation of Conway's Game of Life.

This program consists of one main class that does most of the processing, and helper functions that help it work.

Nick McComb
EECS 162
Feb 2014
*/
#include <iostream>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;



//They constants were made to be modular and can be changed freely
const int windowHeight = 22;  //Specifies the number of rows
const int windowWidth = 80;   //Specifies the number of columns
const char alive = '+';       //The symbol to signify an alive cell
const char dead = '0';        //The symbol to signift a dead cell
const int delayTime = 50000;  //delay time in microseconds between generation processes 

//Class that handles Conways Game of Life
class life {
  public:
    life();         //Default constructor that makes the entire world 'dead'
    void disp();    //Outputs the world to the screen
    void input();   //Inputs a file into the current world
    void output();  //Outputs the current world into a file
    void runSim(int n);  //Runs a simulation 
    void invokeLife(int row, int col);     //Invokes life at the specified location (index 0)
    void destroyLife(int row, int col);    //Destroys life at the specified location (index 0)
    void randomLife(int seed, int number); //Fills the world with random life
    void clear();   //Clears the world
  private:
    void evolve();  //Processes one generation
    int getNumSurrounding(int row, int col);   //Returns the number of surrounding cells (incl. wrapped around ones)
    void modCell(int row, int col, int surr);  //Changes a cell based upon getNumSurrounding()
    char world[windowHeight][windowWidth];     //Holds the current world
    char newWorld[windowHeight][windowWidth];  //Holds a temporary version of the world for use during processing
};

bool manager(life & game);    //Manages the overall functions of the program. File I/O, output, and running simManager()
bool simManager(life & game); //Manages the simulation aspect of the program
void printMenu(int id);       //Manages printing the menu for both managers
