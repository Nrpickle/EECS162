/* 
This is the implementation file for an implementation of Conway's Game of Life.

This program consists of one main class that does most of the processing, and helper functions that help it work.

Nick McComb
EECS 162
Feb 2014
*/
#include "main.hpp"

//The only 2 things that the main function does is instantiate an object of the class life, and loop the managing function.
int main(){

  srand(1238932); //Arbitrary number

  life game;

  while(manager(game));

  return 0;
}

//Main executing function, returns true until the user tells the application to quit, then it returns a false to the controling while loop
bool manager(life & game){
  int choice = -1;  //Stores the user's choice
  bool cont = true;  //Passed back to the while loop
  char resp;  //Used to get the user's response

  printMenu(1);
  cout << "Please enter a choice: ";
  cin >> choice;
  cout << endl;

  switch (choice)
  {
    case 1: //Read in from a file
      game.input();
      break;
    case 2: //Save to a file
      game.output();
      break;
    case 3: //Run a simulation
      while(simManager(game));
      break;
    case 4: //Display current simulation
      game.disp();
      break;
    case 5: //Quit from the application
      cont = false;
      break;
    default:
      cout << "You did not enter a valid choice." << endl;
      break;
  }

  return cont;
}

//Manages the simulation aspect. Called from a while loop inside of manager()
bool simManager(life & game){
  int choice = -1;
  bool cont = true;
  int num1, num2;  //Multi-purpose numbers that can be used in the switch case

  printMenu(2);  //Prints the second menu
  cout << "Please enter a choice: ";
  cin >> choice;
  cout << endl;

  switch(choice)
  {
    case 1:  //Run a simulation for n generations
      cout << "Please enter the number of generations you want to sim: ";
      cin >> num1;
      game.runSim(num1);
      break;
    case 2:  //Manually invoke life
      cout << "Please enter the row and column that you want to invoke life. Index 0." << endl;
      cout << "Row: ";
      cin >> num1;
      cout << "Col: ";
      cin >> num2;
      game.invokeLife(num1,num2);
      break;
    case 3:  //Manually destroy life
      cout << "Please enter the row and column that you want to destroy life. Index 0." << endl;
      cout << "Row: ";
      cin >> num1;
      cout << "Col: ";
      cin >> num2;
      game.destroyLife(num1,num2);
      break;
    case 4:  //Display current simulation
      game.disp();
      break;
    case 5:  //Fill with random life
      cout << "Please enter the random seed you want, or -1 for time(NULL) random: ";
      cin >> num1;
      cout << "Please enter the number of life forms to be placed randomly: ";
      cin >> num2;
      game.randomLife(num1, num2);
      cout << "Successfully randomized board." << endl;
      break;
    case 6:  //Clear the board
      game.clear();
      cout << "Sim cleared." << endl;
      break;
    case 7:  //Return to previous menu
      cont = false;
      break;
    default:
      cout << "That is not a valid answer." << endl;

  }
  return cont;
}

//Manages printing the different menus for the program
void printMenu(int id){
  if(id == 1){ //Menu for the main program
    cout << endl;
    cout << "1: Load a file" << endl;
    cout << "2: Save to a file" << endl;
    cout << "3: Simulation Options (inc. run)" << endl;
    cout << "4: Display current simulation" << endl;
    cout << "5: Exit the application" << endl;
  }
  else if (id == 2){ //Simulation related options
    cout << endl;
    cout << "1: Run simulation for n generations" << endl;
    cout << "2: Manually invoke life" << endl;
    cout << "3: Manually destroy life" << endl;
    cout << "4: Display current simulation" << endl;
    cout << "5: Fill with random life" << endl;
    cout << "6: Clear the sim" << endl;
    cout << "7: Return to previous menu" << endl;
  }
}

//Default (only) constructor creates a blank board full of 'dead' cells. 
life::life(){
  //Fills the board with blank spaces
  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = dead;

  //Fills the world with some alive cells
  //  for(int i = 0; i < 1000; ++i)
  //    world[rand() % windowHeight][rand() % windowWidth] = alive;


  //Glider
  
     //world[2][3+30] = alive;
     //world[3][4+30] = alive;
     //world[4][2+30] = alive; 
     //world[4][3+30] = alive;
     //world[4][4+30] = alive;
     
}

//Outputs the world to the screen
//Doesn't output 0's so that they can be used as a dead character
void life::disp(){
  for(int i = 0; i < windowHeight; ++i){
    for(int j = 0; j < windowWidth; ++j){
      if(world[i][j] == '0')
	cout << " ";
      else
        cout << world[i][j];
    }
    cout << endl;
  }
}

//Preforms the task of creating a new generation
//Task if preformed by creating a new generation stored in a temp variable, then copying that world to the main world
void life::evolve(){
  for(int i = 0; i < windowHeight; ++i){
    for(int j = 0; j < windowWidth; ++j){
      //      cout << getNumSurrounding(i,j);
      modCell(i,j,getNumSurrounding(i,j));
    }
    cout << endl;
  }

  //Copying the array modified in modCell(int,int,int) into the main world
  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = newWorld[i][j];

}

//Runs the simulation for n generations
void life::runSim(int n){

  for(int i = 0; i < n; ++i){
    evolve();
    cout << "Generation: " << i+1 << endl;  //+1 so that the first generation is '1' and the last is 'n'
    disp();
    usleep(delayTime);  //Delay so the user can see what is happening
  }
}

//Determines if the passed row and col are valid, then invokes life in the designated cell if they are
void life::invokeLife(int row, int col){
  if(row < windowHeight -1 && col < windowWidth-1){ //Check for valid input
    world[row][col] = alive;
  }
  else {  //Invalid input
    cout << "Those are not valid coordinates." << endl;
  }  
}

//Determines if the passed row and col are valid, then destroys life in the designated cell if they are
void life::destroyLife(int row, int col){
  if(row < windowHeight -1 && col < windowWidth-1){ //Check for valid input
    world[row][col] = dead;
  }
  else {  //Invalid input
    cout << "Those are not valid coordinates." << endl;
  }
}

//Fills the world with random life, based on a seed #, filling it with 'number' cells.
//SPECIAL CONDITION: if seed is negative, then time(NULL) is used instead of a seed value
void life::randomLife(int seed, int number){
  if(seed >= 0)
    srand(seed);
  else
    srand(time(NULL));

  //Fills the board with blank spaces
  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = dead;

  //Fills the world with some alive cells
  for(int i = 0; i < number+1; ++i)
    world[rand() % windowHeight][rand() % windowWidth] = alive;

}

//Fills the board with blank spaces
void life::clear(){ 
  //Fills the board with blank spaces
  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = dead;
}

//Returns the number of living cells surrounding the passed row and col
//The function handles wrapping by modding the values if they go over the maximum values, 
//and if the values are below 0, then it wraps around to the top to check.
int life::getNumSurrounding(int row, int col){
  int sum = 0;

  if(world[row-1][col-1] == alive && (row > 0 && col > 0))
    ++sum;
  else if (row == 0){
    if (world[windowHeight-1][col-1] == alive)
      ++sum;
  }
  else if (col == 0){
    if (world[row-1][windowWidth-1] == alive)
      ++sum;
  }
  else {  //In this case, both col and row are 0
    if (world[windowHeight-1][windowWidth-1] == alive)
      ++sum;
  }
  if(world[row][col-1] == alive && (col > 0))
    ++sum;
  else if(col == 0 && world[row][windowWidth-1] == alive)
    ++sum;
  if(world[(row+1)%(windowHeight)][col-1] == alive && col>0 )
    ++sum;
  else if(col == 0 && world[(row+1)%windowHeight][windowWidth-1] == alive)
    ++sum;
  //  else if(row == windowHeight-1 && world[0][col-1]i

  if(world[row-1][col] == alive && row > 0)
    ++sum;
  else if(row == 0 && world[windowHeight-1][col] == alive)
    ++sum;
  if(world[(row+1)%windowHeight][col] == alive )
    ++sum;

  if(world[row-1][(col+1)%windowWidth] == alive && (row > 0)) 
    ++sum;
  else if(row == 0 && world[windowHeight-1][(col+1)%windowWidth] == alive)
    ++sum;
  if(world[row][(col+1)%windowWidth] == alive)
    ++sum;
  if(world[(row+1)%windowHeight][(col+1)%windowWidth] == alive)
    ++sum;

  return sum;

}

//Modifies the cell based on the rules of the Game of Life
void life::modCell(int row, int col, int surr){
  if(surr <=1)         //Lonliness
    newWorld[row][col] = dead;
  else if(surr == 3)    //Birth
    newWorld[row][col] = alive;
  else if (surr > 3){  //Overcrowding
    newWorld[row][col] = dead;
  }
  else if (surr == 2)
    newWorld[row][col] = world[row][col];

}

//Outputs the current world to a file
//This file is specified by the user
void life::output(){
  string filename;

  cout << "Please enter the save name: ";
  cin >> filename;

  ofstream output(filename.c_str());


  for(int i = 0; i < windowHeight-1; ++i){
    for(int j = 0; j < windowWidth-1; ++j)
      output << world[i][j];
  }

  cout << "File outputted." << endl;
  output.close();
}

//Inputs a file into the current world
//This file is specified by the user
void life::input(){
  string filename;

  cout << "Please enter the save name: ";
  cin >> filename;
  ifstream input(filename.c_str());
  if(!input){
    cout << "That file does not exist. Please try again." << endl;
    return;
  }

  for(int i = 0; i < windowHeight-1; ++i){
    for(int j = 0; j < windowWidth-1; ++j)
      input >> world[i][j];
  }

  cout << "File inputted." << endl;

  input.close();
}
