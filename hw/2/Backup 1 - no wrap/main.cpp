#include <iostream>
#include <ctime>

#include <time.h>
#include <stdlib.h>
using namespace std;

const int windowHeight = 22;
const int windowWidth = 80;
const char alive = '+';
const char dead = ' ';

class life {
  public:
    life();
    void disp();
    void evolve();
  private:
    int getNumSurrounding(int row, int col);
    void modCell(int row, int col, int surr);
    char world[windowHeight][windowWidth];
    char newWorld[windowHeight][windowWidth];
};


int main(){

  srand(1238931);

  life game;

  game.disp();

  cout << endl;

  
  for(int i = 0; i < 200; ++i){

    game.evolve();

    cout << "Generation: " << i+1 << endl;
    game.disp();
  
    usleep(100000);
  }
  
  return 0;
}


life::life(){
  //Fills the board with blank spaces
  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = dead;

  //Fills the world with some alive cells
//  for(int i = 0; i < 400; ++i)
//    world[rand() % windowHeight][rand() % windowWidth] = alive;


  //Glider
  world[2][3+70] = alive;
  world[3][4+70] = alive;
  world[4][2+70] = alive; 
  world[4][3+70] = alive;
  world[4][4+70] = alive;

}




void life::disp(){
  for(int i = 0; i < windowHeight; ++i){
    for(int j = 0; j < windowWidth; ++j)
      cout << world[i][j];
    cout << endl;
  }
}


void life::evolve(){
  for(int i = 0; i < windowHeight; ++i){
    for(int j = 0; j < windowWidth; ++j){
     // cout << getNumSurrounding(i,j);
      modCell(i,j,getNumSurrounding(i,j));
    }
    cout << endl;
  }

  for(int i = 0; i < windowHeight; ++i)
    for(int j = 0; j < windowWidth; ++j)
      world[i][j] = newWorld[i][j];
}


//8 total
//Doesn't wrap around (maybe?)
int life::getNumSurrounding(int row, int col){
  int sum = 0;
  
//  if(row == 0)

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
//  else if (world[windowHeight][windowWidth] == alive)
//    ++sum;
  if(world[row][col-1] == alive && (col > 0))
    ++sum;
//  else if (world[row][windowWidth-1] == alive
  if(world[(row+1)][col-1] == alive && (row < windowHeight-1 && col>0) )
    ++sum;

  if(world[row-1][col] == alive && row > 0)
    ++sum;
  if(world[(row+1)][col] == alive && (row < windowHeight-1) )
    ++sum;

  if(world[row-1][col+1] == alive && (row > 0 && col < windowWidth-1))
    ++sum;
  if(world[row][col+1] == alive && (col < windowWidth-1))
    ++sum;
  if(world[row+1][col+1] == alive && (row < windowHeight-1 && col < windowWidth-1))
    ++sum;

  return sum;

}


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
