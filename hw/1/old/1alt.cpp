#include<iostream>
#include<math.h>
using namespace std;

//Assignment #1 
//Question #1 Workfile

const int lenWordOne = 3; //Maximum length of the first word in its array
const int lenWordTwo = 4;
const int maxLetterNum = 9; //This is not hard-coded in for debugging purposes
const int arrayLen = 6; //Arbritraty length; simply larger than necessary

//Function Prototypes
bool unique(int one, int two, int three, int four);
int sumNumbers(char word[], int lenWord, int T, int O, int G, int D);
  
//Main Function
int main(){
  char wordOne[arrayLen] = "TOO\0";
  char wordTwo[arrayLen] = "GOOD\0";  
  cout << "Solution to the following probem: TOO + TOO + TOO + TOO = GOOD" << endl;

//  cout << "Total for word one: " << sumNumbers(wordOne,3,1,2,0,0) << endl;
//  cout << "Total for word two: " << sumNumbers(wordTwo,4,0,1,2,2) << endl;

  int resultOne;
  int resultTwo;
  for(int i = 0; i < maxLetterNum; i++){
    for(int j = 0; j < maxLetterNum; j++){
      for(int k = 0; k < maxLetterNum; k++){
        for(int l = 0; l < maxLetterNum; l++){
          resultOne = sumNumbers(wordOne,lenWordOne,i,j,0,0) * 4;
	  resultTwo = sumNumbers(wordTwo,lenWordTwo,i,j,k,l);
	  if((resultTwo == resultOne) and unique(i,j,k ,l)){
            cout << "T: " << i << " O: " << j << " G: " << k << " D: " << l << endl;
	  }
        }
      }
    }
  }

  
 ///or(int i = 0; i < 3; i++){
/// cout << wordOne[i] << endl;
///

  return 0;
}


//Works with number equizalents
//
int sumNumbers(char word[], int lenWord, int T, int O, int G, int D){
  
  
int total = 0;
  
  for(int i = 0; i < lenWord; i++){
//    cout << word[i] << endl;
    switch(word[i]){
      case 'T':
//        cout << "T";
        total += T;
        break;
      case 'O':
//        cout << "O";
        total += O;
        break;
      case 'G':
//        cout << "G";
        total += G;
        break;
      case 'D':
//        cout << "D";
        total += D;
        break;
      default:
        cout << "Error!";
        break;
    }
//    cout << endl;
  }
  return total;
}


//Determines if passed numbers are unique
bool unique(int one, int two, int three, int four){
  if(one == two or one == three or one == four or two == three or two == four or three == four)
    return false;
  return true;
}
