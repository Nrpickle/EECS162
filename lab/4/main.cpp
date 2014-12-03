#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const int numTriangleNumbers = 200;

void generateTriangleNumbers(int *triangleNum);
int wordValue(string word);
bool checkTriangleNum(int * triangleNum, int num);

int main(int argc, char** argv) {
   ifstream inStream;
   vector<string> triangleWords;
   int *triangleNum;
   triangleNum = new int [numTriangleNumbers+1];

   generateTriangleNumbers(triangleNum);

   inStream.open("words.txt");
   if( inStream.fail()) 
   {
      std::cout << "Input file opening failed.\n";
      exit(1);
   }

   string next;
   while( inStream >> next ){
      if(checkTriangleNum(triangleNum, wordValue(next))){
	     cout << next << " " << wordValue(next) << endl;
	     triangleWords.push_back(next);
      }
   }

   delete triangleNum;
   inStream.close();

   ofstream outStream;
   outStream.open("output.txt");
   if(outStream.fail()){
      cout << "Failed!" << endl;
      return 1;
   }

   for(unsigned int i = 0; i < triangleWords.size(); ++i)
      outStream << triangleWords[i] << endl;

   outStream.close();
}

void generateTriangleNumbers(int *triangleNum){
   for(int i = 0; i < numTriangleNumbers; ++i){
      triangleNum[i] = .5 * (i) * (i+1);
   }
}

int wordValue(string word){
   int sum = 0;
   for(unsigned int i = 0; i < word.length(); ++i){
      sum += (int) word[i] - 64;
   }
   return sum;
}

bool checkTriangleNum(int * triangleNum, int num){
  for(int i = 0; i < numTriangleNumbers; ++i)
     if(triangleNum[i] == num)
	return true;
  return false;
}
