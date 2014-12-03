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

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

const int defaultHealth = 100;

//Base class
class Creature{
  public:
    Creature();
    Creature(int inputStrength, int inputHealth = defaultHealth);
    float getDamage();  //Gets the damage of for the creature
    virtual string getSpecies();
    void setStr(int str);  //Basic mutators and accessors
    int getStr();
    void setHealth(float health);
    int getHealth();
  protected:
    float health;  //Stores the health
    int strength;  //Stores the strength
};

/* DEMONIC CLASSES */

class Demon : public Creature{
  public:
    Demon();
    Demon(int inputStrength, int inputHealth = defaultHealth);
    virtual float getDamage(); //Demon's have a 5% change to do 50 more damage
    virtual string getSpecies();
};

class CyberDemon : public Demon {
  public:
    CyberDemon();
    CyberDemon(int strength, int health = defaultHealth);
    float getDamage();  //CyberDemon's aren't special
    string getSpecies();
};

class Balrog : public Demon {
  public:
    Balrog();
    Balrog(int strength, int health = defaultHealth);
    float getDamage();  //Balrogs attack twice
    string getSpecies();
};

/* END DEMONIC CLASSES */

class Elf : public Creature {
  public:
    Elf();
    Elf(int inputStrength, int inputHealth = defaultHealth);
    float getDamage();  //Elf's have a 10% to do a magical attack which doubles
	                    //their attack
    string getSpecies();
};

class Human : public Creature {
  public:
    Human();
    Human(int inputStrength, int inputHealth = defaultHealth);
    float getDamage();  //Human's do nothing special
    string getSpecies();
};
