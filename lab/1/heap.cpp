#include <iostream>
#include <math.h>
using namespace std;

#define ARRAY_SIZE 4

int input(char array[]);
float average(int array[], int lenArray);
float variance(int array[], int lenArray, float mean);
float deviation(float var);

int main(){
  int * array = new int[ARRAY_SIZE];
  array[0] = 1;
  array[1] = 2;
  array[2] = 3;
  array[3] = 4;

  int lenArray = ARRAY_SIZE;

  float mean = average(array, lenArray);
  float var = variance(array, lenArray, mean);
  float dev = deviation(var);
  cout << "Avg: " << mean << endl << "Var: " << var << endl << "Dev: " << dev << endl;

  delete [] array;
}

float average(int array[], int lenArray){
  float avg = 0;
  float total = 0;

  for(int i = 0; i < lenArray; ++i){
    total = total + array[i];
  }

  avg = total / lenArray;
  return avg;
}

float variance(int array[], int lenArray, float mean){
  float var = 0;
  float total = 0;

  for(int i = 0; i < lenArray; ++i) {
    total +=  pow(array[i] - mean,2);
  }
  cout << "Total: " << total << endl;
  var = total / lenArray;
  return var;
}

float deviation(float var){
  float dev = sqrt(var); 
  return dev;
}
