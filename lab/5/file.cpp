#include "main.hpp"

//Empty default constructor
File::File(){

}

File::File(string pathnameInput, string textInput){
  pathname = pathnameInput;
  text = textInput;

}

File & File::operator=(const File &input){
  pathname = input.pathname;
  text = input.text;
}

void File::output(){
  cout << pathname << endl;
  Document::output();
}
