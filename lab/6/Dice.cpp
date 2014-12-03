#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Dice.hpp"


/* Original Dice */ 

Dice::Dice() {
  numSides = 6;
  srand(time(NULL)); /* seeds random number generator */
}

Dice::Dice(int numSides) {
  this->numSides =  numSides;
  srand(time(NULL)); /* seeds random number generator */
}

int Dice::roll() const {
  return( rand() % numSides) + 1;
}


/* Loaded Dice 1 */

loadedDice1::loadedDice1(){
  numSides = 6;
  srand(time(NULL));
}

loadedDice1::loadedDice1(int numSides){
  this->numSides = numSides;
  srand(time(NULL));
}

int loadedDice1::roll() const{
  if(rand() % 2)
    return numSides;
  else
    return( rand() % numSides) + 1;
}


/* Loaded Dice 2 */

loadedDice2::loadedDice2(){
  numSides = 6;
  srand(time(NULL));
}

loadedDice2::loadedDice2(int numSides){
  this->numSides = numSides;
  srand(time(NULL));
}

int loadedDice2::roll() const{
  if(rand() % 10 != 9 )
    return numSides;
  else
    return( rand() % numSides) + 1;
}
