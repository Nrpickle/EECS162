#include "Dice.hpp"
#include <iostream>
using namespace std;

int rollTwoDice(const Dice& d1, const Dice& d2) {
  return d1.roll() + d2.roll();
}

int main(int argc, char** argv) {
  
  Dice d1(8);
  loadedDice1 d2(5);
  loadedDice2 d3(6);

  cout << endl << "Dice 1 - Not loaded:" << endl;

  int i;
  for(i = 0; i < 10; ++i)
    cout << d1.roll() << endl;

  cout << endl << "Dice 2 - Loaded 50%:" << endl;

  for(i = 0; i < 10; ++i)
    cout << d2.roll() << endl;

  cout << endl << "Dice 3 - Loaded 90%:" << endl;

  for(i = 0; i < 10; ++i)
    cout << d3.roll() << endl;
}
