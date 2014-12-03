/* PROGRAM: 1
 * DESCRIPTION: This program solves the first part of assignment 1
 * DATE: JAN 2014
 * INPUT: Recieves no input.
 * OUTPUT: Outputs to the terminal
 */
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

//These first two values are hard-coded into the program, they can be changed with the wordOne and wordTwo variables, but they are in no way dynamic
const int lenWordOne = 3; //Maximum length of the first word in its array
const int lenWordTwo = 4; //Maximum length of the second word in ints array
const int maxLetterNumInit = 10; //This is not hard-coded in for debugging purposes
                                 //It is set at 10 because the check is if i is less 
				 //than the number, so we want to check 10
const int arrayLen = 6; //Arbritraty length; simply larger than necessary

//Function Prototypes
bool unique(int one, int two, int three, int four);     //This function determines if
							//the four numbers passed to it
						        //are unique
int sumNumbers(char word[], int lenWord, int T, int O, int G, int D);  //"Adds up"
							//the numbers in the word
							//passed to it
  
//Main Function
int main(int argc, char** argv){
  char wordOne[arrayLen] = "TOO\0";    //Used to store and manipulate the first word
  char wordTwo[arrayLen] = "GOOD\0";   //USed to store and manipulate the second word
  int maxLetterNum = maxLetterNumInit; //Used to store and possibly manipulate
  				       //the max number, because it can be chaged
				       //by command line arguments

  cout << "Solutions to the following problem: TOO + TOO + TOO + TOO = GOOD" << endl;  //Intro text!

  if(argc>1)  //Chceks if there are any additional command line arguments
    maxLetterNum = atoi(argv[1]); //If there are, then count up to that numbers

  int resultOne;  //Holds the result for the first result
  int resultTwo;  //"     "     "     "     " second result
  //The following code brute forces the answer. It calculates the results, then 
  //checks if the result for the left half of the problem is the same as the
  //right half, and if the variables are all unique, and if both of those conditions
  //are met, then it outputs the result to the screen
  //Out of complete habit I made the variables i,j,k,l
  for(int i = 0; i < maxLetterNum; i++){
    for(int j = 0; j < maxLetterNum; j++){
      for(int k = 0; k < maxLetterNum; k++){
        for(int l = 0; l < maxLetterNum; l++){
          resultOne = sumNumbers(wordOne,lenWordOne,i,j,0,0) * 4;
	  resultTwo = sumNumbers(wordTwo,lenWordTwo,i,j,k,l);
	  if((resultTwo == resultOne) and unique(i,j,k ,l)){
            cout << "T: " << i << " O: " << j << " G: " << k << " D: " << l << " TOO: " << i << j << j << " GOOD: " << k << j << j << l << endl;
	  }
        }
      }
    }
  }

  return 0;
}


//This function works with the inputted letters and determines the value
//of the word that is inputted, and returns that value
//
//Input ( original word, length of [word], number for T, " O, " G, " D)
//Output (outputs the final value of the word)
int sumNumbers(char word[], int lenWord, int T, int O, int G, int D){
  
  
int total = 0;
  
  for(int i = 0; i < lenWord; i++){
    switch(word[i]){
      case 'T':
        total += T*pow(10,lenWord-i-1);
        break;
      case 'O':
        total += O*pow(10,lenWord-i-1);
        break;
      case 'G':
        total += G*pow(10,lenWord-i-1);
        break;
      case 'D':
        total += D*pow(10,lenWord-i-1);
        break;
      default:
        cout << "Error!";
        break;
    }
  }
  return total;
}


//Description: Determines if passed numbers are unique
//Input: 4 different numbers
//Output: True if the numbers are unique, false if any two numbers are the same
bool unique(int one, int two, int three, int four){
  if(one == two or one == three or one == four or two == three or two == four or three == four)
    return false;
  return true;
}
