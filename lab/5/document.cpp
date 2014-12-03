#include "main.hpp"

//Empty default constructor
Document::Document(){

}

Document::Document(string inputText){
  text = inputText;
}

void Document::output(){
  cout << text << endl;
}

//Overloading the assignment operator
Document & Document::operator=(const Document &input){
  text = input.text;
}
