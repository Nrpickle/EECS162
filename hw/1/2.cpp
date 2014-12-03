/* PROGRAM: 2
 * DESCRIPTION: This program solves the second part of assignment 1
 *              Program can be scaled by changing the ARRAY_SIZE constant
 *              Multiplies two generated matricies
 * DATE: JAN 2014
 * INPUT: This program recieves no input
 * OUTPUT: This program outputs to the terminal
 */
#include <iostream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 10;  //Specifies the dimensions of the array (ex. 10x10)

void populateArray(int array[][ARRAY_SIZE]);  //Populates the array with numbers 0-ARRAY_SIZE-1
void dispArray(int array[][ARRAY_SIZE]); //Outputs the array
void matrixMath(int arrayOne[][ARRAY_SIZE], int arrayTwo[][ARRAY_SIZE], int finalArray[][ARRAY_SIZE]); //Does the mathmatical functions of multiplying matricies

int main(){ 
  int arrayOne [ARRAY_SIZE][ARRAY_SIZE]; 
  int arrayTwo [ARRAY_SIZE][ARRAY_SIZE];  
  int finalArray [ARRAY_SIZE][ARRAY_SIZE];
  populateArray(arrayOne);  //Populates both arrays
  populateArray(arrayTwo);

  //The following lines were added to test the program
  arrayOne[1][2] = 80;
  arrayOne[0][1] = 40;
  arrayOne[0][0] = 70;
  arrayOne[1][0] = 90;
  arrayTwo[2][1] = 144;

  //Outputs the arrays
  cout << "Array One: " << endl;
  dispArray(arrayOne);
  cout << endl; 
  cout << "Array Two: " << endl;
  dispArray(arrayTwo);
  cout << endl;

  populateArray(finalArray); //Debugging purposes only

  matrixMath(arrayOne, arrayTwo, finalArray); //Do the math

  dispArray(finalArray);
  return 0;
}

/* FUNCTION: populateArray
 * DESC:     Populates an matrix of ARRAY_SIZE size
 * INPUT:    Inputs an empty matrix
 * OUTPUT:   Outputs a full matrix
 */
void populateArray(int array[][ARRAY_SIZE]){
  for(int i = 0; i < ARRAY_SIZE; ++i)
    for(int j = 0; j < ARRAY_SIZE; ++j)
      array[i][j] = i;
}

/* FUNCTION: dispArray
 * DESC:     Outputs an array of ARRAY_SIZE to the terminal
 * INPUT:    Array to output
 * OUTPUT:   Outputs an matrix to the terminal
 */
void dispArray(int array[][ARRAY_SIZE]){
  for(int i = 0; i < ARRAY_SIZE; ++i){
    for(int j = 0; j < ARRAY_SIZE; ++j)
      cout << setw(4) << array[i][j] << " ";
    cout << endl;
  }
}

/* FUNCTION: matrixMath
 * DESC:     Preforms a matrix multiplication
 * INPUT:    Two matricies to be multiplied
 * OUTPUT:   The resultant final array
 */
void matrixMath(int arrayOne[][ARRAY_SIZE], int arrayTwo[][ARRAY_SIZE], int finalArray[][ARRAY_SIZE]){
  int sum = 0;
  for(int fHoriz = 0; fHoriz < ARRAY_SIZE; ++fHoriz){
    for (int fVert = 0; fVert < ARRAY_SIZE; ++fVert){
      for(int i = 0; i < ARRAY_SIZE; ++i){
        sum += arrayOne[fVert][i] * arrayTwo[i][fHoriz];
      }
     finalArray[fVert][fHoriz] = sum;
     sum = 0;
    }
  }
}
