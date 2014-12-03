#include "main.hpp"

/*  Nick McComb
 *  EECS162 HW #2
 *  Feb 2014
 *
 *  This program preforms the function of a _basic_ role playing game.
 *
 *  This is the implementation file for the basic role playing game that I began
 *  to create.
 *
 *  INPUT: None.
 *  OUTPUT: The program outputs some basic testing of the classes that were implemented
 * */

int main(){

  srand(time(NULL));
  //Create four creatures that will be used for the demo
  CyberDemon Jenkins(20);
  Balrog Charlie(20);
  Elf Finle(20);
  Human Jaek(20);

  cout << "Created CyberDemon Jenkins, STR 20, HEALTH 100" << endl;
  cout << "Created Balrog Charlie, STR 20, HEALTH 100" << endl;
  cout << "Created Elf Finle, STR 20, HEALTH 100" << endl;
  cout << "Created Human Jaek, STR 20, HEALTH 100" << endl << endl;

  //Outputs the tests for the user
  cout << "Jenkins' Species: " << Jenkins.getSpecies() << endl;
  for(int i = 0; i < 2; ++i)
    cout << "Jenkins attacks: " << Jenkins.getDamage() << endl;
  cout << endl << "Charlie's species: " << Charlie.getSpecies() << endl;
  for(int i = 0; i < 2; ++i)
    cout << "Charlie attacks: " << Charlie.getDamage() << endl;
  cout << endl << "Finle's species: " << Finle.getSpecies() << endl;
  for(int i = 0; i < 2; ++i)
    cout << "Finle attacks: " << Finle.getDamage() << endl;
  cout << endl << "Jaek's species: " << Jaek.getSpecies() << endl;
  for(int i = 0; i < 2; ++i)
    cout << "Jaek attacks: " << Jaek.getDamage() << endl;



  return 0;
}

//Basic constructor, sets the default health and str
Creature::Creature(){
  health = 100;
  strength = 0;
}

//Takes the input in from the user
//The input health has a default value of 100
Creature::Creature(int inputStrength, int inputHealth){
  strength = inputStrength;
  health = inputHealth;
}

//Gets the basic damage functions
float Creature::getDamage(){
  return (rand() % (strength-1));
}

//This function will never be called b/c the creature class will 
//never be instantiated 
string Creature::getSpecies(){
  return "Creature!";
}

// The following 4 functions are basic mutators and accessors for the creature class 
// and its derivatives 
void Creature::setStr(int str){
  strength = str;
}

int Creature::getStr(){
  return strength;
}

void Creature::setHealth(float inputHealth){
  health = inputHealth;
}

int Creature::getHealth(){
  return health;
}

/* DEMONIC FUNCTIONS */

//Basic constuctor
Demon::Demon() : Creature() { 
}

//Slightly more advanced constructor
Demon::Demon(int inputStrength, int inputHealth) : Creature(inputStrength, inputHealth){
}

//Gets damage
//Demons have a 5% change to do 50 more damage points
float Demon::getDamage(){
  int dmg = Creature::getDamage();
  if((rand() % 20) == 2){ //Random demonic attack
    cout << "Demonic Attack!" << endl;
    dmg += 50;
  }
  return dmg;
}

//Returns Demon
string Demon::getSpecies(){
  return "Demon";
}

/* CYBERDEMON */

//Basic constructor
CyberDemon::CyberDemon() : Demon::Demon() {
}

//More advanced constructor
CyberDemon::CyberDemon(int inputStrength, int inputHealth) : Demon(inputStrength, inputHealth){
}

//Returns the basic damage funciton, CyberDemon's aren't special
float CyberDemon::getDamage(){
  return Demon::getDamage();
}

//Returns CyberDemon
string CyberDemon::getSpecies(){
  return "CyberDemon";
}

/* END CYBERDEMON */

/* BALROG */

//Basic constructor
Balrog::Balrog() : Demon(){
}

//More advanced constructor
Balrog::Balrog(int inputStrength, int inputHealth) : Demon(inputStrength, inputHealth){
}

//Damage function is called twice to simulate two attacks
float Balrog::getDamage(){
  cout << "This Balrog was so fast it attacked twice!" << endl;
  return Demon::getDamage() + Demon::getDamage();
}

//Returns Balrog
string Balrog::getSpecies(){
  return "Balrog";
}

/* END BALROG */


/* ELFEN FUNCTIONS */

//Basic constructor
Elf::Elf() : Creature(){
}

//More advanced constructor
Elf::Elf(int inputStrength, int inputHealth) : Creature(inputStrength, inputHealth){
}

//Elfs have a 10% chance to use a magical attack which doubles the damage of the attack
float Elf::getDamage(){  
  if((rand() % 10) == 2){ //Random elfen attack
    cout << "Magical Attack!" << endl;
    return Creature::getDamage() * 2;
  }
  return Creature::getDamage();
}

//Returns Elf
string Elf::getSpecies(){
  return "Elf";
}

/* END ELFEN FUNCTIONS */

/* BEGIN HUMAN FUNCTIONS */

//Basic constructor
Human::Human() : Creature(){
}

//More advanced constructor
Human::Human(int inputStrength, int inputHealth) : Creature(inputStrength, inputHealth){
}

//Returns the basic damage. Human's aren't special
float Human::getDamage(){
  return Creature::getDamage();
}

//Returns "Human"
string Human::getSpecies(){
  return "Human";
}

/* END HUMAN FUNCTIONS */
