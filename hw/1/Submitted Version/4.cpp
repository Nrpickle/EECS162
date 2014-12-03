/* PROGRAM: 4
 * DESC: This program deletes every 3rd suitor until none are left
 *       Hand-picked application of vectors
 * DATE: JAN 2014
 * INPUT: Can specify the number of suitors from the command line
 *        usage: 4 num
 *          num = number of suitors
 */
#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

void outputSuitors(vector<int> suitors); //Outputs the current suitors in the vector

int main(int argc, char** argv){
  vector<int> suitors;  //Holds the suitors
  int numSuitors = 10;  //Default number of suitors if not changed at the command line
  if(argc>1) //Tests if a command line arg exits
    numSuitors = atoi(argv[1]); //If it does, then use that number for the suitors
  for(int i = 1; i < numSuitors + 1; ++i)  //Populates the suitors
    suitors.push_back(i);

  if(numSuitors != 10)  //Only output this if non-standard
    cout << "Suitors Initialized. " << endl;  //Used to tell when the suitors were populated; useful for large tests (get a scope of the total time involved)

  //Erase every third target
  int currentTarget = 2; //Start with the third target (index 0)
    while(suitors.size() > 1){ //Check and see if more than one suitor exists
      if(suitors.size() > currentTarget){ //Do nothing, this is good
      }
      else { //Now we might have a problem...
          currentTarget = currentTarget % suitors.size(); //Make sure a valid target is selected
      }
        suitors.erase(suitors.begin()+currentTarget);  //Remove the target
	if(numSuitors == 10) //If the number is 10, show debug (show proccess)
          outputSuitors(suitors);
	currentTarget+=2;  //Increment to the next suitor. Number is 2 because one was just deleted, so it would be the 2nd one after that.
    }

  cout << "The suitor to be is: " << endl;
  outputSuitors(suitors); //Outputs the suitor you want to be
  return 0;
}

/* FUNCTION: outputSuitors
 * DESC: Outputs the suitors to the terminal
 * INPUT: The vector that contains the suitors
 * OUTPUT: Outputs the suitors to the screen
 */
void outputSuitors(vector<int> suitors){
  if(suitors.size() > 1)
    cout << "Suitors: " << endl;
  else
    cout << "Suitor: ";
  for(int i = 0; i < suitors.size(); i++)
    cout << suitors[i] << endl;
  cout << endl;
}
