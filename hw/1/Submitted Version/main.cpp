/* PROGRAM: main
 * DESCRIPTION: This program manages the rest of the programs for assignment #1.
 * DATE: JAN 2014
 * INPUT: Recieves input from the user
 * OUTPUT: Calls other executibles which then output to the terminal
 */
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <sstream>
#include <string.h>
using namespace std;

int prompt();  //Prompts the options to the user
int read_int(string prompt);  //Read in an int, and returns it
string concatenate(string const& name, int i); //Concatenates a string and a number
                                               //using the stringstream library

int main(){
  int response;    //Used to hold the user's response
  int num = 33;    //Used to input the number for case 4
  int strSize;     //Used for conversion in case 4
  int i;           //Used to create an array of characters from a string in case 4
  string four = "4 "; //Used to concatenate with a number in case 4
  int cont = true; //Do you want to continue?
  int contResponse = 1;  //The response read in from the user
  string numS; //The string that holds the number
  string sysString; //The string that is going to be sent to the sytem for case 4
  char sysStringChar[64];  //system() requires an array of characters, so this will 
                           //hold it.
  char space = ' ';
  //Main executing loop
  do {
    response = prompt();
    cout << endl;
    switch(response) {
      case 1: //Cyrpto Puzzle
        system("1");
        break;
      case 2:  //Matrix Math
        system("2"); 
        break;
      case 3:  //Sum of all multiples of 3 or 5 under 1000
        system("3");
        break;
      case 4:  //Eve's Suitors
        num = read_int("Please enter the number of suitors: ");
        sysString.clear();
	
	for(i = 0; i < 30; ++i)  //Clears the previous info out of the system call
	  sysStringChar[i]=' ';
        sysString = concatenate(four, num);  //Concatenates the string "4 " and the
	                                     //inputted number
        strSize = sysString.size();          //Gets the size of the final string
        for (i = 0; i < strSize; i++)        //Converts the string to array of chars
          sysStringChar[i] = sysString[i];
        system(sysStringChar);               //Calls the relevant system call
        break;
      case 5: //Quit case
	  cont = false;
	  break;
    default:  //Invalid option
        cout << "That is not a valid option." << endl;;
    }
  } while(cont);
}

/* FUNCTION:    prompt()
 * DESCRIPTION: Outputs the users' choices and reeads in their choice.
 * INPUT:       None.
 * OUTPUT:      Returns the choice number.
 */
int prompt(){
  int response;
  cout << endl;
  cout << "There are four programs to choose from." << endl;
  cout << "1: Crypto Puzzle" << endl;
  cout << "2: Matrix Math" << endl;
  cout << "3: Sum of all Multiples of 3 or 5 under 1000" << endl;
  cout << "4: Eve's Suitors" << endl;
  cout << "5: Quit" << endl;
  cout << "Please make a selection: ";
  cin >> response;
  return response;
}

/* FUNCTION:    read_int
 * DESCRIPTION: Basic function to read a number in from the user
 * INPUT:       A string as a prompt
 * OUTPUT:      Returns the inputted number
 */
int read_int(string prompt){
  int num;
  cout << prompt;
  cin >> num;
  return num;
}

/* FUNCTION:    concatenate
 * DESCRIPTION: Concatenates the string and the integer passed in
 * INPUT:       A string and an int
 * OUTPUT:      Returns the new string
 */
string concatenate(string const& name, int i){
  stringstream s;
  s << name << i;
  return s.str();
}
