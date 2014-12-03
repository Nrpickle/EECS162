/* PROGRAM: getMult3or5
 * DESC: This program outputs the sum of of all multiples of 3 or 5 up to 1000 (exclusive)
 * DATE: JAN 2014
 * INPUT: None
 * OUTPUT: Outputs the result to the terminal
 */
#include<iostream>
using namespace std;

int getMult3or5(void); //Preforms the math in the function

int main(){
  cout << "Sum of all multiples of 3 or 5 below 1000: ";
  cout << getMult3or5() << endl;
  return 0;
}

//Principle function of the program, this function 
//sums the multiples of 3 or 5 up by looping through
//all of the numbers between 0 and 999
//Input: None
//Output: Returns result
int getMult3or5(void){
  int total = 0;
  for(int i = 0; i < 1000; ++i){
     if((i%5 == 0) or (i%3 == 0))
       total += i; 
  }
  return total;
}
